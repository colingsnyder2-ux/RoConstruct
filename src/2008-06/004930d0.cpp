// from server: 100% by coldek
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_codex_june2_5db4bc5ce93303a6.cpp

// Candidate translation unit (score above; library headers required).
// from server: 87% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <G3D/CoordinateFrame.h>
using G3D::Vector2;

#include "util/Rect.h"
using RBX::Rect;

namespace RBX {
    class Instance;
    // Existing-pointer provider view: only native rate1c0 and scale1c8 are read.
    class ServiceProvider {
    public:
        char prefix[0x1c0];
        float rate;
        double scale;
    };
}

extern RBX::ServiceProvider* func_00492e00(RBX::Instance*);
extern const double lowerBound;
extern const double upperBound;
struct NativeColor;
extern const NativeColor color1;
extern const NativeColor color2;

struct Object {
    const G3D::CoordinateFrame& getCoordinateFrame() const;
};

extern Object* findObject(RBX::Instance*);

struct Receiver {
    void submit(const Rect*);
};

struct S {
    char prefix[0x170];
    RBX::Instance* object;
    Rect bounds() const;
    void draw(const Rect*, const void*, const void*);
    void f(Receiver*);
};

void S::f(Receiver* receiver)
{
    RBX::ServiceProvider* provider = func_00492e00(reinterpret_cast<RBX::Instance*>(this));
    if (!provider)
        return;
    if (!object)
        return;

    Object* target = findObject(object);
    if (!target)
        return;

    Rect original=bounds();
    const Vector2 dimensions=original.size();

    Vector2 center=target->getCoordinateFrame().translation.xz();

    double scale = 1.0;
    scale /= provider->rate;
    scale *= provider->scale;

    Vector2 adjusted;
    if(scale>lowerBound) {
        adjusted=dimensions*0.5f;
    } else if(scale<upperBound) {
        adjusted=dimensions+Vector2(2.0f,2.0f);
    } else {
        adjusted=dimensions;
    }
    Vector2 halfSize=adjusted*0.5f;
    const Vector2 high=center+halfSize;
    const Vector2 low=center-halfSize;
    Rect result(low,high);
    draw(&result, &color2, &color1);
    receiver->submit(&result);
}
