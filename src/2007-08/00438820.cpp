// from server: 100% by EspClaude
// roc 2007-08 00438820  G3D::VColor3 XItem: COLORREF (vslot 0xe8) -> Color3
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
#define GetRValue(rgb) ((BYTE)(rgb))
#define GetGValue(rgb) ((BYTE)(((WORD)(rgb)) >> 8))
#define GetBValue(rgb) ((BYTE)((rgb)>>16))

struct S;
struct VTable {
    char pad[0xe8];
    DWORD (__thiscall *getColor)(S*);
};
struct Color3 { float r, g, b; };

struct S {
    VTable* vtable;
    Color3 color();
};

Color3 S::color()
{
    DWORD value = vtable->getColor(this);
    Color3 result;
    result.r = GetRValue(value) / 255.0;
    result.g = GetGValue(value) / 255.0;
    result.b = GetBValue(value) / 255.0;
    return result;
}
