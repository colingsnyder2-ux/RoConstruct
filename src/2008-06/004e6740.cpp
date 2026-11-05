// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_nativeownerref_9eccb474e84ed3cb.cpp

// Candidate translation unit (score above; library headers required).
extern const float minimumValue;
extern const float zeroValue;

#include "G3D/ReferenceCount.h"
struct Ref {
 virtual ~Ref();
 G3D::AtomicInt32 ReferenceCountedObject_refCount;
 void ReferenceCountedObject_zeroWeakPointers();
};
typedef G3D::ReferenceCountedPointer<Ref> Handle;
struct State {
    char padding[0x1c8];
    int enabled;
};

struct Receiver {
    virtual void update(const Handle&, bool);
};

struct Holder {
    int padding;
    Receiver* receiver;
};

struct S : Ref {
    char padding[0xb4];
    State* state;
    char padding2[12];
    Handle cached;
    Holder* holder;

    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setValue(float);
    virtual float getValue();

    void f();
};

void S::f()
{
    if (state) {
        cached = (Ref*)0;

        {
            Handle reference(this);
            holder->receiver->update(reference, state->enabled == 0);
        }

        if (state->enabled) {
            if (getValue() < minimumValue)
                setValue(minimumValue);
        } else {
            if (getValue() < zeroValue)
                setValue(0.0f);
        }
    }
}
