#include<stdio.h>
#include<SDL2/SDL.h>


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char const *argv[])
{
    //The window we'll be rendering to
    SDL_Window* window = NULL;

    //The surface contained by the window
    //SDL Surface is a 2d image
    SDL_Surface* screenSurface = NULL;

    //initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        printf("SDL could not initialized! SDL_Error: %s\n", SDL_GetError());
    }
    else{
        //Create Window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == NULL){
            printf("Window couldn't be created! SDL_Error:%s\n", SDL_GetError());
        }
        else{
            //Get window surface
            screenSurface = SDL_GetWindowSurface(window);
            //Fill the surface Pinkish
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format,255, 134,239));
            //Update the surface
            SDL_UpdateWindowSurface(window);
            //Wait two sec
            SDL_Delay(2000);
        }
    }
    //Destroy Window
    SDL_DestroyWindow(window);
    //Quit SDL Subsystem
    SDL_Quit();
    return 0;
}
