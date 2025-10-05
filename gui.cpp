#include "gui.h"

GUI::GUI(Manager &manager)
    : m_manager{manager}
{

    SDL_Init(SDL_INIT_VIDEO);

    m_window = SDL_CreateWindow("TodoList", 640 * 2, 380 * 2, 0);

    if (m_window == NULL)
    {
        std::cerr << "Error opening window";
    }

    m_renderer = SDL_CreateRenderer(m_window, NULL);

    initImGui();
}

bool GUI::runGUI()
{

    bool appRunning{true};

    SDL_Event event{};
    static int tick{1699};

    SDL_ShowWindow(m_window);
    while (appRunning)
    {
        SDL_PollEvent(&event);
        ImGui_ImplSDL3_ProcessEvent(&event);

        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            appRunning = false;
            return quitGUI();
            break;

        default:
            break;
        }
        updateImGui();

        SDL_SetRenderDrawColor(m_renderer, 3 * tick % 255, 7 * tick % 255, 11 * tick % 255, 0xff);
        SDL_RenderClear(m_renderer);
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), m_renderer);
        SDL_RenderPresent(m_renderer);
    }

    return false;
}

bool GUI::quitGUI()
{
    cleanupImGui();

    SDL_DestroyWindow(m_window);
    SDL_Quit();
    return true;
}

void GUI::initImGui()
{

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |=
        ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |=
        ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls

    // Setup scaling
    float main_scale = SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay());
    ImGuiStyle &style = ImGui::GetStyle();
    style.ScaleAllSizes(
        main_scale); // Bake a fixed style scale. (until we have a
                     // solution for dynamic style scaling, changing this
                     // requires resetting Style + calling this again)
                     // makes this unnecessary. We leave both here for
                     // documentation purpose)
    style.FontScaleDpi = main_scale;

    style.FontSizeBase = 20.f;
    io.Fonts->AddFontDefault();

    ImGui_ImplSDL3_InitForSDLRenderer(m_window, m_renderer);
    ImGui_ImplSDLRenderer3_Init(m_renderer);
}

void GUI::updateImGui()
{
    static bool p_open{true};
    ImGuiWindowFlags window_flags{0};

    if (m_dirtyState)
    {
        window_flags |= ImGuiWindowFlags_UnsavedDocument;
    }

    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Test", &p_open, window_flags);

    static int selected{0};
    renderSelection();

    ImGui::SameLine();

    renderInfo();

    ImGui::End();
    ImGui::ShowDemoWindow();
    ImGui::Render();
}

void GUI::cleanupImGui()
{
    ImGui_ImplSDL3_Shutdown();
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui::DestroyContext();
}

void GUI::renderMenuBar()
{
}

void GUI::renderSelection()
{

    ImGui::BeginChild("list", ImVec2{150, 0}, ImGuiChildFlags_Borders | ImGuiChildFlags_ResizeX);

    for (int i{0}; i < std::size(m_manager.todoItems); i++)
    {
        const TodoItem &item{m_manager.todoItems.at(i)};

        if (ImGui::Selectable(item.m_title.c_str(), m_selected == i, ImGuiSelectableFlags_SelectOnNav))
        {
            m_selected = i;
            m_reselectedItem = true;
        }
    }

    ImGui::EndChild();
}

void GUI::renderInfo()
{

    ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));

    TodoItem &selectedItem{m_manager.todoItems.at(m_selected)};

    ImGui::Text("Todo: %s", selectedItem.m_title.c_str());
    const char *timestampCreation{timeToStr(selectedItem.m_timestampCreation)};
    ImGui::Text("Created: %s", timestampCreation);

    ImGui::Separator();

    renderTextField(selectedItem);
    ImGui::EndChild();
}
//TODO: allow title editing
void GUI::renderTextField(TodoItem &selectedItem)
{
    static char buffer[1024 * 16]; // TODO: dynamic resizable buffer with  callbackresize

    if (m_reselectedItem)
    {
        strncpy(buffer, selectedItem.m_comment.c_str(), sizeof(buffer));
        buffer[sizeof(buffer) - 1] = 0;

        m_reselectedItem = false;
    }

    static ImGuiInputTextFlags textInputFlags{ImGuiInputTextFlags_ReadOnly};

    if (m_selectionListEnabled)
    {
        if (ImGui::Button("Edit"))
        {
            textInputFlags = textInputFlags & ~ImGuiInputTextFlags_ReadOnly;
            m_dirtyState = true;
            m_selectionListEnabled = false;
        }
    }
    else
    {
        if (ImGui::Button("Cancel"))
        {
            textInputFlags |= ImGuiInputTextFlags_ReadOnly;
            m_selectionListEnabled = true;
        }
    }

    ImGui::SameLine();

    if (!m_selectionListEnabled)
    {
        if (ImGui::Button("Save"))
        {
            textInputFlags |= ImGuiInputTextFlags_ReadOnly;
            m_selectionListEnabled = true;
            selectedItem.m_comment = std::string{buffer};
        }
    }

    ImGui::InputTextMultiline("Edit input", buffer, static_cast<size_t>(1024 * 5), ImVec2(-FLT_MIN, 0), textInputFlags);
}