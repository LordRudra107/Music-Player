#include "headers.h"
Button b1
int main(int argc,char* argv[]){
    SDL_Init(SDL_INIT_VIDEO);
    int Width=600,Height=400;
    SDL_Window* win=SDL_CreateWindow("Player",Width,Height,SDL_WINDOW_TRANSPARENT|SDL_WINDOW_BORDERLESS);
    if (!win) {
        printf("Window error: %s\n", SDL_GetError());
        return -1;
    }
    SDL_Renderer* ren=SDL_CreateRenderer(win,NULL);
    if (!ren) {
        printf("Renderer error: %s\n", SDL_GetError());
        return -1;
    }
    SDL_Texture *tex = SDL_CreateTexture( ren,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_STREAMING,16,16);
    SDL_UpdateTexture(tex,NULL,img,16 * sizeof(Pixel));

    bool run=true;
    while(run){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type==SDL_EVENT_QUIT ||( e.type==SDL_EVENT_KEY_DOWN &&e.key.scancode==SDL_SCANCODE_ESCAPE)) run=false;
        }

        //SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(ren, 0xFF,0x00,0xFF,0xFF);
        SDL_RenderClear(ren);
        SDL_RenderTexture(ren, tex, NULL, &dst);
        SDL_RenderPresent(ren);
    }
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    SDL_Quit();
    return 0;
}
