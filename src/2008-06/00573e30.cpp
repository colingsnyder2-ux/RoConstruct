// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_a82b7218bc76e3f9.cpp

// Candidate translation unit (score above; library headers required).
#include "gui/Gui.h"
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
struct Vec2 {
    float x, y;
};

struct GuiItem {
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual Vec2 size();
};

typedef std::vector<boost::shared_ptr<RBX::Instance> > Children;

extern "C" void* __cdecl cast_object(void*, long, void*, void*, int);

struct S {
    char padding0[264];
    Children* children;
    char padding1[72];
    int direction;

    unsigned count();
    Vec2 f();
};

static inline const float& maximum(const float& a, const float& b)
{
    return a < b ? b : a;
}

Vec2 S::f()
{
    Vec2 result;
    result.x = 0.0f;
    result.y = 0.0f;

    for (unsigned i = 0; i < count(); ++i) {
        Children* c = children;
        GuiItem* item = reinterpret_cast<GuiItem*>(dynamic_cast<RBX::GuiItem*>(
            static_cast<RBX::Instance*>((*c)[i].get())));

        if (item) {
            Vec2 extent = item->size();
            switch (direction) {
            case 0:
                result.x += extent.x;
                result.y = maximum(result.y, extent.y);
                break;
            case 1:
                result.x = maximum(result.x, extent.x);
                result.y += extent.y;
                break;
            }
        }
    }
    return result;
}
