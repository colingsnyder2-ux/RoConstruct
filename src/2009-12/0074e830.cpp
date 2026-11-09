// from server: 36% by atomic.potato
struct Inner {
    void* p;
    void (__stdcall *fn)(void*, void*, int);
};

struct Outer {
    char pad0[4];
    Inner* inner;
    char pad1[0x20];
    void sub_74D1E0();
    void sub_74DFC0(void*, void*);
    void* func(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j);
};

void* Outer::func(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j)
{
    Inner local;
    local.p = 0;
    local.fn = 0;
    if (a) {
        local.p = a;
        void** vt = *(void***)a;
        void (__stdcall *fn)(void*, void*, int) = (void (__stdcall *)(void*, void*, int))vt[0];
        fn(&local, &local, 0);
    }
    sub_74D1E0();
    sub_74DFC0(b, c);
    if (local.p) {
        void** vt = *(void***)local.p;
        if (vt) {
            void (__stdcall *fn2)(void*, void*, int) = (void (__stdcall *)(void*, void*, int))vt[0];
            fn2(&local, &local, 2);
        }
    }

    return this;
}
