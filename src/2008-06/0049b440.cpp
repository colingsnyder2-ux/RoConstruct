// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)






struct Control {
    void* table;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        volatile long* count = &control->references;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(count, 1);
    }
}

struct Source {
    const std::string& getString();
    const Shared& getShared();
};

struct __multiple_inheritance Object;

struct Descriptor {
    unsigned char padding[56];
    void (Object::*method)(Shared, std::string);

    void invoke(Object*, void*, Source*, Source*);
};

void Descriptor::invoke(Object* object, void*, Source* first, Source* second)
{
    (object->*method)(first->getShared(), second->getString());
}
