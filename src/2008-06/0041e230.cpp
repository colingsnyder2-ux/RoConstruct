// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
extern void* control_vtable[];

struct Deleter {
    void operator()(void*) const;
};

struct Control {
    void** vtable;
    long strong;
    long weak;
    void* object;
    Deleter deleter;

    Control(void*, Deleter);
};

inline Control::Control(void* value, Deleter)
{
    strong = 1;
    weak = 1;
    vtable = control_vtable;
    object = value;
}

struct S {
    Control* control;
    S(void*, Deleter);
};

S::S(void* object, Deleter deleter) : control(0)
{
    try {
        control = new Control(object, deleter);
    }
    catch (...) {
        deleter(object);
        throw;
    }
}
