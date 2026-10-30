#include "force_verified.h"
// libpng: write a 32x16 RGB image and read it back losslessly.
#include "png.h"
#include <stdio.h>
#include <string.h>

int main()
{
    const int W = 32, H = 16;
    static png_byte image[H][W * 3];
    for (int y = 0; y < H; ++y)
        for (int x = 0; x < W * 3; ++x)
            image[y][x] = (png_byte)(x * 3 + y * 11);
    png_bytep rows[H];
    for (int y = 0; y < H; ++y)
        rows[y] = image[y];

    FILE* out = fopen("png_roundtrip.png", "wb");
    png_structp w = png_create_write_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
    png_infop wi = png_create_info_struct(w);
    png_init_io(w, out);
    png_set_IHDR(w, wi, W, H, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    png_write_info(w, wi);
    png_write_image(w, rows);
    png_write_end(w, wi);
    png_destroy_write_struct(&w, &wi);
    fclose(out);

    FILE* in = fopen("png_roundtrip.png", "rb");
    png_structp r = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
    png_infop ri = png_create_info_struct(r);
    png_init_io(r, in);
    png_read_info(r, ri);
    static png_byte back[H][W * 3];
    png_bytep backRows[H];
    for (int y = 0; y < H; ++y)
        backRows[y] = back[y];
    png_read_image(r, backRows);
    int width = png_get_image_width(r, ri), height = png_get_image_height(r, ri);
    png_destroy_read_struct(&r, &ri, 0);
    fclose(in);
    int same = memcmp(image, back, sizeof(image)) == 0;
    printf("libpng %s %dx%d same=%d\n", png_get_libpng_ver(0), width, height, same);
    return same && width == W && height == H ? 0 : 1;
}
