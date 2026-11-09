// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_afc4a3b2cbb2c51e.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/Vector2.h>
#include <G3D/Vector2int16.h>
typedef G3D::Vector2 Vec2;typedef G3D::Vector2int16 Short2;
extern void __cdecl modeOne(float*, float*, const Vec2&);
extern void __cdecl modeZero(float*, float*, const Vec2&);
extern void __cdecl absolutePosition(float*, float*, const Vec2&, const Vec2&);
extern void __cdecl insidePosition(float*, float*, const Vec2&, const Vec2&);
extern void __cdecl outsidePosition(float*, float*, const Vec2&, const Vec2&);
extern bool __cdecl specialMode();

struct DxUserInput
{
    char padding0[0x59];
    bool flag;
    char padding1[2];
    int mode;
    Vec2 position;

    bool keyMode();
    bool inside();
    Short2 getPosition();
    void f(float*, float*);
};

void DxUserInput::f(float* x, float* y)
{
    switch (mode)
    {
    case 0:
        (keyMode() || flag)
            ? absolutePosition(x, y, position, getPosition())
            : specialMode()
                ? modeZero(x, y, position)
                : inside()
                    ? insidePosition(x, y, position, getPosition())
                    : outsidePosition(x, y, position, getPosition());
        break;

    case 1:
        modeOne(x, y, position);
        break;
    }
}

