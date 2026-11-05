// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_claudeS4_0414f5b2821e01fc.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include "util/PV.h"
struct Object;
typedef boost::shared_ptr<Object> Shared;
typedef RBX::PV Transform;

struct TransformProperty {
    void assign(const Transform&);
};

struct Object {
    char padding[0x228];
    TransformProperty transform;
    Shared getObject();
    void setParent(void*);
};

struct Actor {
    const G3D::CoordinateFrame& getTransform();
};

namespace RBX {
    class Instance;
    class ServiceProvider {
    public:
        void notify(int);
    };
}

extern Actor* __cdecl findActor(RBX::Instance*);
extern __declspec(noalias) Shared __cdecl convert(const Shared&) throw();
extern RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance*);

struct Tool {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual Shared createObject();
    virtual Transform makeTransform(int, const G3D::CoordinateFrame&);
    virtual int getNotification();

    char padding[0x14];
    RBX::Instance* parent;
    Shared stored;
    int field24;
    int field28;
    int field2c;

    void execute(int);
};

void Tool::execute(int argument)
{
    field2c = field28;
    Actor* actor = findActor(parent);
    if (actor) {
        if (!stored)
            stored = createObject();

        Shared selected = convert(stored.get()->getObject());
        selected->setParent(parent);
        selected->transform.assign(makeTransform(argument, actor->getTransform()));
        func_005807b0(parent)->notify(getNotification());
    }
}
