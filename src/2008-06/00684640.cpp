// from server: 100% by king_originala
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

extern const double heightMultiplier;
extern const double fixedWidthMultiplier;

struct Text {
    unsigned int reserved;
    union {
        char local[16];
        char* allocated;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

struct Size {
    float x;
    float y;
};

struct S {
    int widths[128];
    int textureWidth;
    int textureHeight;

    Size* measure(Size* result, const Text& text, volatile double height, int fixed) const;
};

Size* S::measure(Size* result, const Text& text, volatile double height, int fixed) const
{
    double scaledHeight = height * heightMultiplier;
    double width = textureWidth;
    int length = text.length;
    double scale = (width * scaledHeight / textureHeight) / width;
    double total = 0.0;

    if (!fixed) {
        for (int i = 0; i < length; ++i) {
            if (static_cast<unsigned int>(i) > text.length)
                _invalid_parameter_noinfo();

            const char* characters = text.capacity >= 16
                ? text.storage.allocated
                : text.storage.local;

            total += widths[characters[i] & 127] * scale;
        }
    } else {
        total = (widths[77] * length) * scale * fixedWidthMultiplier;
    }

    result->x = static_cast<float>(total);
    result->y = static_cast<float>(scaledHeight);
    return result;
}
