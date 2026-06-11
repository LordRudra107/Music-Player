#define TOTAL_THEMES 2
//enums

typedef enum {
    COLOR_NIL,
    COLOR_PRIMARY,
    COLOR_SECONDARY,
    COLOR_HIGHLIGHT,
    COLOR_SHADOW,
    COLOR_ACCENT,
    COLOR_COUNT
}Color;

typedef enum{
    STATE_NORMAL,
    STATE_HOVERED,
    STATE_CLICKED,
    STATE_SELECTED
}ObjectState;

typedef enum{
    BUTTON_PLAY,
    BUTTON_STOP
    BUTTON_COUNT
}ButtonID;

// structs

typedef struct {
    uint8_t r, g, b,a;
} Pixel;


typedef struct {
    Pixel primary;
    Pixel secondary;
    Pixel highlight;
    Pixel shadow;
    Pixel accent;   
    Pixel nil;   
}Theme;

typedef struct{
    SDL_Texture* tex_normal;
    SDL_Texture* tex_light;
    SDL_Texture* tex_dark;
}StateTextures;
    
typedef struct {
    uint16_t ID;
    Color data;
    SDL_FRect rec;
    StateTextures st[TOTAL_THEMES];
    ObjectState state;
}Button;
