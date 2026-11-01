// from server: 100% by king_originala
struct S;

struct VTable {
    char pad[0xe8];
    unsigned int (__thiscall *getColor)(S*);
};

struct Color3 {
    float r, g, b;
};

extern const float colorScale;

struct S {
    VTable* vtable;
    Color3 color();
};

#pragma float_control(precise, off, push)

Color3 S::color() {
    unsigned int value = vtable->getColor(this);
    Color3 result;
    result.r = (int)(unsigned char)value * colorScale;
    result.g = (int)(unsigned char)(value >> 8) * colorScale;
    result.b = (int)(unsigned char)(value >> 16) * colorScale;
    return result;
}

#pragma float_control(pop)
