// from server: 79% by atomic.potato
extern "C" long __stdcall InterlockedDecrement(long volatile *);
extern "C" void __stdcall G1_func_0044b020();

struct Inner {
    void* vtbl;
    void (__stdcall *fn)(int);
};

struct Holder {
    Inner* ptr;
};

struct S {
    char pad[8];
    Holder* h;
    void f();
};

void S::f()
{
    Holder* esi = h;
    Inner* p = esi->ptr;
    if (p != 0) {
        if (InterlockedDecrement((long*)((char*)p + 4)) == 0) {
            G1_func_0044b020();
            Inner* q = esi->ptr;
            if (q != 0) {
                void (__stdcall *fn)(int) = *(void (__stdcall **)(int))q->vtbl;
                fn(1);
            }
        }
        esi->ptr = 0;
    }
}
