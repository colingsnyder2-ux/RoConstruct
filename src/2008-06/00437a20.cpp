// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_colorbrickvaluereturn76293c44c2fbbd0d.cpp

// Candidate translation unit (score above; library headers required).
static const float colorScale=1.0f/255.0f;

struct Color3 {
    float r, g, b;
    Color3(unsigned int color);
    Color3(const Color3&);
    ~Color3() {}
};

inline Color3::Color3(unsigned int color)
{
    const float scale = colorScale;
    r = float((unsigned char)color) * scale;
    g = float((unsigned char)(color >> 8)) * scale;
    b = float((unsigned char)(color >> 16)) * scale;
}

struct String;
struct Result { char* data; __declspec(dllimport) Result(const char*); __declspec(dllimport) Result(const Result&); __declspec(dllimport) ~Result(); };

struct BrickColor {
    int value;

    String& name() const;
};

extern void __cdecl closest(BrickColor* result, Color3 color);
extern const char* (__thiscall *stringData)(const String*);
extern void (__thiscall *initializeResult)(Result*, const char*);

Result __cdecl convertColor(unsigned int color)
{
    BrickColor brick;
    closest(&brick, Color3(color));
    return Result(stringData(&brick.name()));
}