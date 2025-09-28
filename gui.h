#pragma once

#include <iostream>

#include <SDL3/SDL.h>

class GUI
{
private:
    SDL_Window *m_window {NULL};
    int m_width{640};
    int m_height{360};

public:
    GUI();
    bool runGUI();
    bool quitGUI();
};
