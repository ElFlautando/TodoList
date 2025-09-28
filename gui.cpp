#include "gui.h"

GUI::GUI(){

    SDL_Init(SDL_INIT_VIDEO);
    
    m_window = SDL_CreateWindow("TodoList", 640, 380, 0);

    if( m_window == NULL){
        std::cerr << "Error opening window";
    }
}

bool GUI::runGUI(){


    bool appRunning {true};

    SDL_Event event{};

    SDL_ShowWindow(m_window);
    while( appRunning){
        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_EVENT_QUIT :
            appRunning = false;
            return quitGUI();
            break;
        
        default:
            break;
        }

    }
    

    return false;
}

bool GUI::quitGUI(){

    SDL_DestroyWindow(m_window);
    SDL_Quit();
    return true;
}