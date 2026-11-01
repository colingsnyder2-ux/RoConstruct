// from server: 100% by colin
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Callback {
    unsigned int a, b, c, d, e, f;
    Callback(const Callback&);
};

inline Callback::Callback(const Callback& value) {
    a = value.a;
    b = value.b;
    c = value.c;
    d = value.d;
    e = value.e;
    f = value.f;
}

struct Control {
    void* pointer;
    Control();
    ~Control();
};

inline Control::Control() : pointer(0) {}

struct Holder {
    void* target;
    Holder(const Callback&);
    ~Holder();
    void assign(const Callback&);
};

inline Holder::Holder(const Callback& source) {
    Callback copy = source;
    target = 0;
    assign(copy);
}

struct Object {
    unsigned char storage[40];
    Object();
};

struct S {
    void* object;
    Control control;
    Holder callback;

    S(const Callback&);
    void set(Object*);
    void finish();
};

S::S(const Callback& value)
    : object(0), control(), callback(value) {
    set(new Object);
    finish();
}
