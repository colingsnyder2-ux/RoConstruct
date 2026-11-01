// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs roc_unit_ec33feeb5006c149.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/LineSegment.h"
#include "G3D/Color4.h"
typedef G3D::Vector3 Vector3;
typedef G3D::Color4 Color4;
struct Frame {
    float data[12];
    Frame();
};

extern const G3D::Color3& direction();
extern G3D::LineSegment makeSegment(const Vector3&, const Vector3&);
extern const float strength;

struct Context {
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
    virtual void setFrame(const Frame&);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void apply(const G3D::LineSegment&, const Color4&, float);
};

struct LaserTool {
    char padding[24];
    int remaining;
    Vector3 start;
    Vector3 finish;

    void fire(Context*);
};

void LaserTool::fire(Context* context)
{
    if (remaining > 0) {
        --remaining;
        context->setFrame(Frame());
        Color4 color(direction(), 1.0f);
        context->apply(makeSegment(start, finish), color, strength);
    }
}
