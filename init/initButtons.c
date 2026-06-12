Button buttons[BUTTON_COUNT];
buttons[BUTTON_PLAY].template=template_ButtonPlay;
buttons[BUTTON_PLAY].width=32;
buttons[BUTTON_PLAY].height=32;
buttons[BUTTON_PLAY].state=STATE_NORMAL;
buttons[BUTTON_PLAY].rec=(SDL_FRect){
    .x=0,.y=0,.w=32,.h=32};
