// from server: 100% by tajop
struct Inner {
    int data[9];
    Inner(const Inner& other);
    ~Inner();
};

struct Mid {
    Inner c;
    int d;
    int e;
    int f;
};

struct Functor {
    int a;
    int b;
    Mid m;
};

struct Buffer {
    int data;
};

struct VTable {
    bool assign_to(Functor f, Buffer& functor);
};

extern VTable stored_vtable;

struct S {
    VTable* vtable;
    int pad;
    Buffer functor;
    void assign_to(Functor f);
};

void S::assign_to(Functor f) {
    vtable = stored_vtable.assign_to(f, functor) ? &stored_vtable : 0;
}
