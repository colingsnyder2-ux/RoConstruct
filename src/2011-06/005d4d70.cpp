// from server: 37% by atomic.potato
struct C1 {
    void* f(int);
};

struct C2 {
    void g(int);
};

struct C3 {
    void h(C1*, int);
};

extern "C" void* __cdecl alloc(unsigned int);
extern "C" void __cdecl cleanup(void*);

struct S {
    void __cdecl method(C3*);
};

void S::method(C3* p) {
    void* mem = alloc(0x2b8);
    C1* obj = 0;
    if (mem) {
        obj = (C1*)mem;
        obj->f(1);
    }
    p->h(obj, 0);
}
