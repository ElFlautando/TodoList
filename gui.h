#pragma once

#include <iostream>
#include <string.h>

#include <SDL3/SDL.h>

#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlrenderer3.h>

#include "manager.h"
#include "utils.h"


class GUI
{
private:
    SDL_Window *m_window {NULL};
    SDL_Renderer *m_renderer {NULL};
    

    int m_width{640};
    int m_height{360};


    void initImGui();
    void updateImGui(Manager& manager);
    void cleanupImGui();

public:
    GUI();
    bool runGUI(Manager& manager);
    bool quitGUI();
};
