#include "headers.h"
int main(int argc,char* argv[]){
    SDL_Init(SDL_INIT_VIDEO);
    int Width=600,Height=250;
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
    
    printf("%d",sizeof(Pixel));
    SDL_Texture* tex=CreateTexture(ren,template1,32,32,&theme1);
    Button b1;
        b1.ID=0;
        b1.st[0].tex_normal=tex;
        b1.rec=(SDL_FRect){
            .x=100,
            .y=100,
            .w=32,
            .h=16
        };
            
    bool run=true;
    while(run){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type==SDL_EVENT_QUIT ||( e.type==SDL_EVENT_KEY_DOWN &&e.key.scancode==SDL_SCANCODE_ESCAPE)) run=false;
        }
      
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0x00,0xFF);
        SDL_RenderClear(ren);
        SDL_RenderTexture(ren, b1.st[0].tex_normal, NULL, &b1.rec);
        SDL_RenderPresent(ren);
        SDL_SetRenderVSync(ren, 1);
    }
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
