// from server: 31% by atomic.potato
struct Inner {
    char pad[8];
    void method(void*, void*, char, void*);
};

struct Outer {
    Inner* p;
};

void __stdcall helper(Outer* o, void* a, void* b, char c, void* d);

void __stdcall func(Outer* o, void* a, void* b, char c, void* d) {
    o->p->method(a, b, c, d);
}
