// from server: 84% by EspClaude
// from server: 79% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_claude_6a6bb4f4380e23ce.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, on)
static const float colorScale=1.0f/255.0f;

struct Color3 {
    float r, g, b;
    Color3(unsigned int color);
    Color3(const Color3&);
    ~Color3() {}
};

inline Color3::Color3(unsigned int color)
{
    r = (unsigned char)color / 255.0;
    g = ((color & 0xFF00) >> 8) / 255.0;
    b = (unsigned char)(color >> 16) / 255.0;
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