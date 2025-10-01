#include "gui.h"

GUI::GUI()
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
    static bool dirtyText{false};
    static bool p_open{true};
    ImGuiWindowFlags window_flags{0};

    if (dirtyText)
    {
        window_flags |= ImGuiWindowFlags_UnsavedDocument;
    }

    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Test", &p_open, window_flags);

    static int selected{0};

    ImGui::BeginChild("list", ImVec2{150, 0}, ImGuiChildFlags_Borders | ImGuiChildFlags_ResizeX);
    for (int i = 0; i < 15; i++)
    {
        char label[128];
        sprintf(label, "Item %d", i);
        if (ImGui::Selectable(label, selected == i, ImGuiSelectableFlags_SelectOnNav))
        {
            selected = i;
        }
    }
    ImGui::EndChild();
    ImGui::SameLine();

    ImGui::BeginGroup();
    ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));
    ImGui::Text("Selected item: %d", selected);
    ImGui::Separator();
    if (ImGui::BeginTabBar("tabs", ImGuiTabBarFlags_None))
    {
        if (ImGui::BeginTabItem("Info"))
        {
            //TODO: Load text from selected item
            ImGui::TextWrapped("Lorem ipsum");
            ImGui::EndTabItem();
        }
        static ImGuiInputTextFlags textInputFlags{ImGuiInputTextFlags_AllowTabInput | ImGuiInputTextFlags_ReadOnly};
        if (ImGui::BeginTabItem("Edit"))
        {

            if (ImGui::Button("Edit"))
            {
                textInputFlags = textInputFlags & ~ImGuiInputTextFlags_ReadOnly;
                dirtyText = true;
            }
            ImGui::SameLine();
            if (ImGui::Button("Save"))
            {
                textInputFlags |= ImGuiInputTextFlags_ReadOnly;
                dirtyText = false;
                //TODO: Call saving function
                //TODO: Hide save button when not editing
            }

            static char textBuffer[1024 * 5];
            ImGui::InputTextMultiline("Edit input", textBuffer, static_cast<size_t>(1024 * 5), ImVec2(-FLT_MIN, 0), textInputFlags);
            ImGui::EndTabItem();
        }
        else
        {
            textInputFlags |= ImGuiInputTextFlags_ReadOnly;
        }
        ImGui::EndTabBar();
    }
    ImGui::EndChild();
    ImGui::EndGroup();

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