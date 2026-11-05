// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client roc_unit_006cb460d421f354.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Rect.h"
extern float g_974d78;
extern float g_974d7c;
typedef G3D::Vector2 Vec2f;
typedef RBX::Rect Rect;
struct S {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual Vec2f size();

    char pad[0x158];
    int m15c;
    int m160;
    G3D::Vector2int16 offset;

    Vec2f f();
};

Vec2f S::f() {
 Rect canvas(Vec2f::zero(),Vec2f(g_974d78,g_974d7c));
 Rect me(Vec2f::zero(),size());
 canvas = canvas.inset(offset);
 return canvas.positionChild(me,(Rect::Location)m15c,(Rect::Location)m160).low;
}
