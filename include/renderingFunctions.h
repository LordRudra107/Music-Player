SDL_Texture* CreateTexture(SDL_Renderer* ren,Color* data,int height,int width,Theme* theme,TextureType themeType){
    const int SHIFT_VALUE=20;
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
        if(themeType==TEXTURE_LIGHT){
            if(temp.r<=0xff-SHIFT_VALUE) temp.r+=SHIFT_VALUE;
            else temp.r=0xff;
            if(temp.g<=0xff-SHIFT_VALUE) temp.g+=SHIFT_VALUE;
            else temp.g=0xff;
            if(temp.b<=0xff-SHIFT_VALUE) temp.b+=SHIFT_VALUE;
            else temp.b=0xff;            
        }
        else  if(themeType==TEXTURE_DARK){
            if(temp.r>=SHIFT_VALUE) temp.r-=SHIFT_VALUE;
            else temp.r=0x00;
            if(temp.g>=SHIFT_VALUE) temp.g-=SHIFT_VALUE;
            else temp.g=0x00;
            if(temp.b>=SHIFT_VALUE) temp.b-=SHIFT_VALUE;
            else temp.b=0x00;            
        }

        pushBack(&arr,&temp);
       }   
        
    

    for(size_t i=0;i<width*height;i++){
         Pixel* p=elementAt(&arr,i);
         printf("%d-r:%02x g:%02x b:%02x a:%02x \n",(i+1),p->r,p->g,p->b,p->a);
    }
     SDL_Texture *tex =SDL_CreateTexture(ren,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_STATIC,width,height);
     SDL_SetTextureScaleMode(tex,SDL_SCALEMODE_NEAREST);
    SDL_UpdateTexture(tex,NULL,arr.begin,width * sizeof(Pixel));
    SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
   vectorDestroy(&arr);
   return tex;
}
