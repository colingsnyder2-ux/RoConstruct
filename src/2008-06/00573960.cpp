// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_unit_5ce00537768de8e8.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Rect.h"
typedef G3D::Vector2 Vector2;
typedef RBX::Rect Rect;
struct GuiTarget {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual Vector2 getPosition();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual Vector2 getSize();
    Rect getMyRect();
    G3D::Rect2D getMyRect2D();
};

Rect GuiTarget::getMyRect()
{
 Vector2 pos = getPosition();
 return Rect(pos, pos + getSize());
}

G3D::Rect2D GuiTarget::getMyRect2D() { return getMyRect().toRect2D(); }
