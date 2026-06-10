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
} Colors;
typedef enum{
    STATE_NORMAL,
    STATE_HOVERED,
    STATE_CLICKED
}ObjectState;

// structs
typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct{
    SDL_Texture* tex_normal;
    SDL_Texture* tex_hovered;
    SDL_Texture* tex_clicked;
}ButtonStateTectures;
struct Theme{
    Pixel primary;
    Pixel secondry;
    Pixel highlight;
    Pixel shadow;
    Pixel accent;   
}
struct Button{
    uint16_t ID;
    Color *data;
    SDL_FRect rec;
    ButtonStateTextures bst[TOTAL_THEMES];
    ObjectState state;
}
