SDL_Texture* CreateTexture(SDL_Renderer* ren,Color* data,int height,int width,Theme* theme){
    Vector arr;
    vectorInit(&arr,sizeof(Pixel));
    for(size_t i=0;i<width*height;i++){
        Pixel temp={0,0,0,0};
        if(data[i]==COLOR_PRIMARY)temp=theme->primary;
        else if(data[i]==COLOR_SECONDARY)temp=theme->secondary;
        else if(data[i]==COLOR_HIGHLIGHT)temp=theme->highlight;
        else if(data[i]==COLOR_SHADOW)temp=theme->shadow;
        else if(data[i]==COLOR_ACCENT)temp=theme->accent;
        else temp=theme->nil;
        pushBack(&arr,&temp);
        
    }
   
    for(size_t i=0;i<width*height;i++){
         Pixel* p=elementAt(&arr,i);
         //printf("%d-r:%02x g:%02x b:%02x a:%02x \n",(i+1),p->r,p->g,p->b,p->a);
    }
     SDL_Texture *tex =SDL_CreateTexture(ren,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_STATIC,width,height);
     SDL_SetTextureScaleMode(tex,SDL_SCALEMODE_NEAREST);
    SDL_UpdateTexture(tex,NULL,arr.begin,width * sizeof(Pixel));
  
   vectorDestroy(&arr);
   return tex;
}
