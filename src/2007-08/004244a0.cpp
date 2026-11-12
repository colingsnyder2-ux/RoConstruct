// from server: 92% by EspClaude
// from server: 42% by colin
// roc 2007-08 004244a0  unit: CSelectionTreeCtrl  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004244a0
// Shape: boost shared_count(p, d) ctor with try/catch (same codegen as 004074e0). Catch funclet follows at 00424519 (BOUNDS).
//

//

#pragma optimize("y", off)

void* __cdecl operator new(unsigned int);
extern void* controlVtable[];

struct Deleter {
    void operator()(void*) const;
};



struct Control {
    void** vtable;
    int strong;
    int weak;
    void* object;
    Deleter deleter;

    Control(void*, const Deleter&);
};

inline Control::Control(void* p, const Deleter& d)
    : strong(1), weak(1), deleter(d)
{
    vtable = controlVtable;
    object = p;
}

struct S {
    Control* control;
    S(void*, Deleter);
};

S::S(void* p, Deleter d) : control(0)
{
    try {
        control = new Control(p, d);
    }
    catch (...) {
        d(p);
        throw;
    }
}
