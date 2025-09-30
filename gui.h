#pragma once

#include <iostream>

#include <SDL3/SDL.h>

#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlrenderer3.h>


class GUI
{
private:
    SDL_Window *m_window {NULL};
    SDL_Renderer *m_renderer {NULL};

    int m_width{640};
    int m_height{360};
public:
    GUI();
    bool runGUI();
    bool quitGUI();
};
