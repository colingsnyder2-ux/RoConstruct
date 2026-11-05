// from server: 100% by king_originala
struct Text;

struct Size {
    float x;
    float y;
};

struct Font {
    Size* measure(Size* result, const Text* text, double height, int mode);
};

extern Font* currentFont;

struct AdornRbxGfx {
    Size* measure(Size* result, const Text* text, double height, int mode);
};

Size* AdornRbxGfx::measure(Size* result, const Text* text, double height, int mode)
{
    Size* temporary = reinterpret_cast<Size*>(&height);
    currentFont->measure(temporary, text, height, mode);
    result->x = temporary->x;
    result->y = temporary->y;
    return result;
}
