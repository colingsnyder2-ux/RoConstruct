// from server: 100% by king_originala
#pragma float_control(precise, off)

struct Color {
    float r, g, b;
};

float material[4];
extern "C" void (__stdcall *glMaterialfv)(unsigned int, unsigned int, const float *);

struct S {
    char pad0[0x70];
    int changes;
    char pad1[4];
    int requests;
    char pad2[0x3e0];
    Color color;

    void setColor(const Color &value);
};

void S::setColor(const Color &value)
{
    ++requests;
    if (color.r != value.r || color.g != value.g || color.b != value.b) {
        color.r = value.r;
        color.g = value.g;
        color.b = value.b;
        material[0] = value.r;
        material[1] = value.g;
        material[2] = value.b;
        material[3] = 1.0f;
        glMaterialfv(0x408, 0x1202, material);
        ++changes;
    }
}
