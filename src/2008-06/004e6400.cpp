// from server: 100% by king_originala_sol_resume_high
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-view roc_resume_high_part_bool_native_381ff5b0aaa9ac2d.cpp

// Candidate translation unit (score above; library headers required).
#include "RenderLib/RenderScene.h"
// from server: 90% by colin
// roc 2008-06 004e6400  unit: RBX::ViewNew::Part  size: 287 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e6400
//

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

extern const float limit;
extern const float threshold;

struct Ev { bool on; };
struct Base {
    virtual ~Base();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void setValue(float);
    virtual float getValue();

    volatile long references;
    void* resource;
    char padding[196];

    struct Link* link;
    int extra;

    void releaseResource();
};

typedef G3D::ReferenceCountedPointer<RBX::Render::Chunk> NativeReference;

typedef RBX::Render::SceneManager Receiver;

struct Link {
    void* first;
    Receiver* receiver;
};

struct Listener {
    virtual void update(int, Ev) = 0;
};

struct Part : Base, Listener {
    void update(int, Ev);
};

void Part::update(int, Ev ev)
{
    link->receiver->setSleeping(NativeReference(reinterpret_cast<RBX::Render::Chunk*>(static_cast<Base*>(this))), ev.on);
    Base* object = this;

    if (!ev.on) {
        if (object->getValue() < 0.5f)
            object->setValue(0.5f);
    } else {
        if (object->getValue() < 1.0f)
            object->setValue(0.0f);
    }
}
