for(unsigned i=0;i<BUTTON_COUNT;i++){
    for(unsigned j=0;j<THEME_COUNT;j++ ){
       buttons[i].st[j].tex_normal =CreateTexture(ren,buttons[i].template,buttons[i].width,buttons[i].height,themes[j],TEXTURE_NORMAL);
       buttons[i].st[j].tex_light =CreateTexture(ren,buttons[i].template,buttons[i].width,buttons[i].height,themes[j],TEXTURE_LIGHT);
       buttons[i].st[j].tex_dark =CreateTexture(ren,buttons[i].template,buttons[i].width,buttons[i].height,themes[j],TEXTURE_DARK);
        
    }
    buttons[i].activetexture=buttons[i].st[CurrentTheme].tex_normal;
 }
