// from server: 100% by king_originala
struct RGB
{
    unsigned char r, g, b;
};

struct Color
{
    unsigned int value;
    RGB getRGB() const;
};

extern void *__cdecl convert(void *destination, RGB color);

struct CRobloxControlColorSelector
{
    char padding[0x180];
    unsigned int selectedColor;

    void update(int);
    void f(unsigned int);
};

void CRobloxControlColorSelector::f(unsigned int value)
{
    RGB rgb;
    rgb.r = (unsigned char)value;
    rgb.g = (unsigned char)(value >> 8);
    rgb.b = (unsigned char)(value >> 16);

    Color temporary;
    Color color = *(Color *)convert(&temporary, rgb);

    selectedColor = color.getRGB().r |
        ((color.getRGB().g | (color.getRGB().b << 8)) << 8);
    update(1);
}
