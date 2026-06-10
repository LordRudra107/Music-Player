void CopyPixel(Pixel* a,Pixel*b){
    //copy a to b
    b->r=a->r;
    b->g=a->g;
    b->b=a->b;
}
SDL_Texture* CreateTexture(SDL_Renderer* ren,Color* data,int height,int width,Theme* theme){
    Pixel* arr;
    vectorInit(arr,sizeof(Pixel));
    for(size_t i=0;i<width*height;i++){
        Pixel temp={0,0,0,0};
        if(data[i]==COLOR_PRIMARY)CopyPixel(&temp,&theme.primary);
        else if(data[i]==COLOR_SECONDRY)CopyPixel(&temp,&theme->secondry);
        else if(data[i]==COLOR_HIGHLIGHT)CopyPixel(&temp,&theme->highlight);
        else if(data[i]==COLOR_SHADOW)CopyPixel(&temp,&theme->shadow);
        else if(data[i]==COLOR_ACCENT)CopyPixel(&temp,&theme->accent);
        PUSH_BACK(arr,&temp);
    }
   SDL_Texture *tex =SDL_CreateTexture(ren,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC,width,height);
   SDL_UpdateTexture(tex,NULL,arr,width * sizeof(Pixel));
   VectorDestroy(arr);
   return tex;
}
