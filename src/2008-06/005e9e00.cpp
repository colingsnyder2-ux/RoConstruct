// from server: 100% by colin
// roc-lang: cpp
// roc 2008-06 005e9e00  unit: RBX::PhysicsService  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e9e00
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// stl: set<ptr>
#include <set>

struct Sub {
    virtual void s0();
    virtual int kind();
};

struct Elem {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual bool v7();
    Sub* sub;
};

struct Notifier {
    char storage[0x85];
    void raise(Elem* e);
};

struct PhysicsService {
    char padding[0x20];
    Notifier notifier;
    bool notifying;
    char padding2[0x1e];
    std::set<Elem*> parts;

    void step();
};

void PhysicsService::step()
{
    std::set<Elem*>::iterator it = parts.begin();
    while (it != parts.end())
    {
        Elem* e = *it;
        it++;
        if (e->sub->kind() == 7 && e->v7())
        {
            notifying = true;
            notifier.raise(e);
            notifying = false;
        }
    }
}
