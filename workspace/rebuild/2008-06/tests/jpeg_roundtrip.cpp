// libjpeg: encode a 64x48 gradient to a file and decode it back; size and approximate pixels must agree.
#include <stdio.h>
#include <stdlib.h>
extern "C" {
#include "jpeglib.h"
}

int main()
{
    const int W = 64, H = 48;
    static JSAMPLE image[W * H * 3];
    for (int i = 0; i < W * H; ++i)
    {
        image[i * 3] = (JSAMPLE)(i % W * 4);
        image[i * 3 + 1] = (JSAMPLE)(i / W * 5);
        image[i * 3 + 2] = 128;
    }
    FILE* out = fopen("jpeg_roundtrip.jpg", "wb");
    jpeg_compress_struct c;
    jpeg_error_mgr err;
    c.err = jpeg_std_error(&err);
    jpeg_create_compress(&c);
    jpeg_stdio_dest(&c, out);
    c.image_width = W; c.image_height = H; c.input_components = 3; c.in_color_space = JCS_RGB;
    jpeg_set_defaults(&c);
    jpeg_set_quality(&c, 95, TRUE);
    jpeg_start_compress(&c, TRUE);
    while (c.next_scanline < c.image_height)
    {
        JSAMPROW row = &image[c.next_scanline * W * 3];
        jpeg_write_scanlines(&c, &row, 1);
    }
    jpeg_finish_compress(&c);
    jpeg_destroy_compress(&c);
    fclose(out);

    FILE* in = fopen("jpeg_roundtrip.jpg", "rb");
    jpeg_decompress_struct d;
    d.err = jpeg_std_error(&err);
    jpeg_create_decompress(&d);
    jpeg_stdio_src(&d, in);
    jpeg_read_header(&d, TRUE);
    jpeg_start_decompress(&d);
    static JSAMPLE back[W * H * 3];
    while (d.output_scanline < d.output_height)
    {
        JSAMPROW row = &back[d.output_scanline * W * 3];
        jpeg_read_scanlines(&d, &row, 1);
    }
    jpeg_finish_decompress(&d);
    int w = d.output_width, h = d.output_height;
    jpeg_destroy_decompress(&d);
    fclose(in);
    long worst = 0;
    for (int i = 0; i < W * H * 3; ++i)
        worst = labs((long)image[i] - back[i]) > worst ? labs((long)image[i] - back[i]) : worst;
    printf("jpeg %dx%d worst=%ld\n", w, h, worst);
    return w == W && h == H && worst < 24 ? 0 : 1;
}
