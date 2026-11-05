// from server: 28% by atomic.potato
struct Inner {
    void* p;
    void* q;
};

struct S {
    char pad0[0x20];
    void* field20;
    char pad24[4];
    Inner inner28;
    int f(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j, void* k, void* l, void* m, void* n, void* o, void* p, void* q, void* r);
};

extern "C" void __stdcall sub_703ef0();

int S::f(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j, void* k, void* l, void* m, void* n, void* o, void* p, void* q, void* r)
{
    Inner local;
    local.p = 0;
    local.q = 0;
    if (c) {
        local.p = c;
        void** vt = *(void***)c;
        void* tmp = &local.q;
        ((void (__stdcall*)(void*, void*, void*))vt[0])(0, tmp, &local);
    }
    sub_703ef0();
    field20 = 0;
    if (d) {
        field20 = d;
        void** vt = *(void***)d;
        ((void (__stdcall*)(void*, void*, void*))vt[0])(0, &inner28, &local);
    }
    if (local.p) {
        void* v = *(void**)local.p;
        if (v) {
            ((void (__stdcall*)(int, void*, void*))v)(2, &local, &local);
        }
        local.p = 0;
    }
    if (local.q) {
        void* v = *(void**)local.q;
        if (v) {
            ((void (__stdcall*)(int, void*, void*))v)(2, &local.q, &local.q);
        }
    }
    return (int)this;
}
