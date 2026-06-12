 SDL_Init(SDL_INIT_VIDEO);
int Width=600,Height=250;
SDL_Window* win=SDL_CreateWindow("Music Player",Width,Height,SDL_WINDOW_TRANSPARENT);
if (!win) {
    printf("Window error: %s\n", SDL_GetError());
    return -1;
 }
    SDL_Renderer* ren=SDL_CreateRenderer(win,NULL);
if (!ren) {
    printf("Renderer error: %s\n", SDL_GetError());
    return -1;
 }
