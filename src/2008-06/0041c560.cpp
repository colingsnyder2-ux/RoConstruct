// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)






struct Control {
    long reserved;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        volatile long* count = &control->references;
        _InterlockedExchangeAdd(count, 1);
    }
}

struct Value {
    const std::string& text();
    const Shared& pointer();
};

struct Base1 {};
struct Base2 {};

struct __multiple_inheritance Object : Base1, Base2 {
};

typedef void (Object::*Callback)(Shared, std::string, std::string);

struct S {
    char reserved[56];
    Callback callback;

    void f(Object*, void*, Value*, Value*, Value*);
};

void S::f(Object* object, void*, Value* first, Value* second, Value* third)
{
    (object->*callback)(first->pointer(), second->text(), third->text());
}
