#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BMPHeader;
typedef struct {
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} DIBHeader;

#pragma pack(pop)
typedef struct {
    uint8_t b;
    uint8_t g;
    uint8_t r;
} Pixel;
bool equal(Pixel a, Pixel b) {
    return a.r == b.r &&
           a.g == b.g &&
           a.b == b.b;
}
int main() {
    FILE *fp = fopen("test.bmp", "rb");

    BMPHeader bmp;
    DIBHeader dib;
    
    fread(&bmp, sizeof(BMPHeader), 1, fp);
    fread(&dib, sizeof(DIBHeader), 1, fp);

    int width  = dib.biWidth;
    int height = dib.biHeight;
    fseek(fp, bmp.bfOffBits, SEEK_SET);

    Pixel* pixels= (Pixel *)malloc(width * height * sizeof(Pixel));
    // bmp rows are padded to be  multiple of 4bytes;
    int rowSize = (width * 3 + 3) & ~3;
    uint8_t *row = (uint8_t*)malloc(rowSize);

    for (int y = 0; y < height; y++) {
        fread(row, rowSize, 1, fp);
        
        for (int x = 0; x < width; x++) {
            Pixel *p = &pixels[(height - 1 - y) * width + x];//BMP stores rows bottom-to-top, so we flip them while loading.
            
            p->b = row[x * 3 + 0];
            p->g = row[x * 3 + 1];
            p->r = row[x * 3 + 2];
        }
    }
    
    free(row);
    fclose(fp);
    Pixel Color1{0x00,0x80,0x00};    
    Pixel Color2{0x00,0x00,0x00};    
    Pixel temp;    
    for (size_t i = 0; i < height; i++) {
          printf("{");
          for (size_t j = 0; j < width; j++) {
              temp=pixels[i*width+j];
              printf("{0x%02x,0x%02x,0x%02x}", temp.r,temp.g, temp.b);
              if(j!=width-1) printf(",");              
          }
          printf("}");      
          if(i!=height-1) printf(",\n");              
    }    
    return 0;
  }
