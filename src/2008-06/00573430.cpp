// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_unit_39635652f58f6bf1.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector2.h>
struct S {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual short v5();
    virtual short v6();
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(S*);
};

extern G3D::Vector2 canvasSize;
void __cdecl f(S* item,S* target) {
 short y=item->v6();
 short x=item->v5();
 canvasSize=G3D::Vector2(x,y);
 target->v24(item);
}
