// from server: 66% by king_originala
struct Handle {
    void* object;
    void* control;
    Handle(const Handle&);
    ~Handle();
};

Handle __cdecl makeHandle(void*);

struct Signal {
    void clear();
};

struct Base {
    void update(void*, void*);
};

struct Registry {
    void update(void*, Handle);
};

extern Registry registry;

struct S {
    char prefix[0x14];
    char base[0x50];
    Signal signal;
    void f(const Handle&);
};

void S::f(const Handle& argument)
{
    void* object = argument.object;
    reinterpret_cast<Base*>(this)->update(object, argument.control);
    signal.clear();
    void* subobject = this ? static_cast<void*>(base) : 0;
    registry.update(subobject, makeHandle(object));
}
