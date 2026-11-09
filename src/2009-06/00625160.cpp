// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_try_sp_c1_d41adcc463e21ee1.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#pragma float_control(precise, off)
#include "G3D/Rect2D.h"
#include "G3D/Color4.h"
#include "G3D/Color3.h"

struct Context {
    enum XAlign { XALIGN_RIGHT, XALIGN_LEFT };
    enum YAlign { YALIGN_TOP, YALIGN_BASELINE, YALIGN_CENTER, YALIGN_BOTTOM };
    enum Spacing { PROPORTIONAL_SPACING, MONOSPACE };
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual G3D::Rect2D getViewport();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual G3D::Vector2 drawFont2D(const std::string&, const G3D::Vector2&, double,
                      const G3D::Color4&, const G3D::Color4&, XAlign, YAlign, Spacing);
};

extern int __cdecl normalizedFontSize(int);

struct S {
    void base(Context*);
    void* check();
    void draw(Context*);
};

void S::draw(Context* adorn)
{
    Context* const c = adorn;
    base(adorn);
    if (check()) {
        G3D::Rect2D viewPort = adorn->getViewport();
        int fontSize = normalizedFontSize(12);
        G3D::Vector2 pos2d = viewPort.x0y1() + G3D::Vector2(4.0f, -4.0f);
        c->drawFont2D("StarterPack - these items will be given to each new player",
            pos2d, fontSize, G3D::Color3::white(), G3D::Color4::clear(), Context::XALIGN_LEFT, Context::YALIGN_BOTTOM, Context::PROPORTIONAL_SPACING);
    }
}
