#include <iostream>

#include <SDL3/SDL.h>

int main(){

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window { SDL_CreateWindow("TodoList", 640, 380, 0)};

    if( window == NULL){
        std::cerr << "Error opening window";
    }

    bool appRunning {true};
    SDL_Event event{};
    while( appRunning){
        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_EVENT_QUIT :
            appRunning = false;
            break;
        
        default:
            break;
        }
        SDL_ShowWindow(window);
    }
    

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}