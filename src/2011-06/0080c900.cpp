// from server: 100% by tester
struct Inner;

struct InnerVtbl {
    char pad[0x15c];
    void* (__thiscall *fn)(Inner*, Inner*);
};

struct Inner {
    InnerVtbl* vtbl;
};

struct Outer {
    char pad[0x100];
    Inner* inner;
    Inner* method(Inner* arg);
};

Inner* Outer::method(Inner* arg) {
    Inner* p = inner;
    p->vtbl->fn(p, arg);
    return arg;
}