// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_docguardorder_4d6dcd257a209b73.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct State {
    unsigned char padding[0x1b4];
    int value;
};

struct Object {
    State* state();
};

typedef boost::shared_ptr<Object> GuardShared;
struct Shared : GuardShared {};

struct Source {
    Shared get();
};

struct Guard {
    unsigned char storage[12];
    Guard(GuardShared value);
    ~Guard();
};

struct Receiver {
    virtual void set(int value) = 0;
};

struct S {
    unsigned char padding[0x94];
    Source* source;
    Shared get();
    void f(Receiver* receiver);
};

__forceinline void apply(Receiver* receiver, const Shared& object) { int value=object->state()->value; receiver->set(value == 1); }

void S::f(Receiver* receiver)
{
    Guard guard(source->get());
    apply(receiver, get());
}
