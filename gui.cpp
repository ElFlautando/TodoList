#include "gui.h"

GUI::GUI(){

    SDL_Init(SDL_INIT_VIDEO);
    
    m_window = SDL_CreateWindow("TodoList", 640, 380, 0);

    if( m_window == NULL){
        std::cerr << "Error opening window";
    }

    m_renderer = SDL_CreateRenderer(m_window, NULL);
}

bool GUI::runGUI(){


    bool appRunning {true};

    SDL_Event event{};
    static int tick{1699};

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
       
        SDL_SetRenderDrawColor(m_renderer, 3*tick%255, 7*tick%255, 11*tick%255,  0xff);
        SDL_RenderClear(m_renderer);
        SDL_RenderPresent(m_renderer);

    }
    

    return false;
}

bool GUI::quitGUI(){

    SDL_DestroyWindow(m_window);
    SDL_Quit();
    return true;
}