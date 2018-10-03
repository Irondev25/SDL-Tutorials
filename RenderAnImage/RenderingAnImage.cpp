#include<stdio.h>
#include<SDL2/SDL.h>


//Starts up SDL and creates window
bool init();

//loads media
bool loadMedia();

//free media and shutdown SDL
void close();


//Global Variables
SDL_Window* gWindow = NULL;

//An SDL surface is just an image data type that contains 
//the pixels of an image along with all data needed to render it.
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;




int main(int argc, char const *argv[]){
    //start up sdl and create window
    if(!init()){
        printf("Failed to initialize!\n");
    }
    else{
        //Load Media
        if(!loadMedia()){
            printf("Failed to load media!\n");
        }
        else{
            //Apply the image
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);
            //Wait for 2 seconds
            SDL_Delay(2000);
        }
    }
    close();
    return 0;
}


bool init(){
    int WIDTH = 640;
    int HEIGHT = 480;

    //initialization flag
    bool success = true;

    //initialize sdl
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        printf("SDL couldn't be initialized! SDL_Error:%s\n", SDL_GetError());
        success = false;
    }
    else{
        //create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL){
            printf("Window couldn't be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else{
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}


bool loadMedia(){
    //loading success flag
    bool success = true;

    //load splash image
    gHelloWorld = SDL_LoadBMP("MARBLES.BMP");
    if(gHelloWorld == NULL){
        printf("Unable to load image %s! SDL_Error:%s\n", "MARBLES.BMP", SDL_GetError());
        success = false;
    }
    return success;
}

void close(){
    //deallocate surface
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    //Quit SDL SubSystems
    SDL_Quit();
}


