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
    BUTTON_STOP,
    BUTTON_COUNT
}ButtonID;

typedef enum{
    TEXTURE_NORMAL,
    TEXTURE_LIGHT,
    TEXTURE_DARK
}TextureType;

typedef enum{
    THEME_DARK,
    THEME_COUNT
}ThemeType;

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
    Color* template;
    size_t width;
    size_t height;
    SDL_FRect rec;
    SDL_Texture* activeTexture;
    StateTextures st[THEME_COUNT];
    ObjectState state;
}Button;
