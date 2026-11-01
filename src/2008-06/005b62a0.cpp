// from server: 100% by king_originala
struct RGB {
    unsigned char r, g, b;
};

struct RGBA {
    unsigned char r, g, b, a;
};

extern void __cdecl convert(void *destination, RGBA color);

void *__cdecl f(void *destination, RGB color)
{
    RGBA value;
    value.r = color.r;
    value.g = color.g;
    value.b = color.b;
    value.a = 0;
    convert(destination, value);
    return destination;
}
