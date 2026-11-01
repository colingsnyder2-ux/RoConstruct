// from server: 100% by colin
struct Inner;

struct InnerVtbl {
    char pad[0x150];
    void* (__thiscall *fn)(Inner*, Inner*);
};

struct Inner {
    InnerVtbl* vtbl;
};

struct Outer {
    char pad[0xfc];
    Inner* inner;
    Inner* method(Inner* arg);
};

Inner* Outer::method(Inner* arg) {
    Inner* p = inner;
    p->vtbl->fn(p, arg);
    return arg;
}
