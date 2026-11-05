// from server: 29% by atomic.potato
extern "C" void __stdcall G1_func_006a5750();

struct S {
    void f(int);
};

void S::f(int)
{
    void* p = 0;
    void* q = 0;
    int saved = 0;
    void* g = (void*)0xdba4c4;
    void (*fn)(void*, void*, int) = 0;
    if (*(void**)0xdba4c4) {
        fn = *(void (**)(void*, void*, int))0xdba4c4;
        fn(&q, &q, 2);
    }
    if (*(void**)0x34) {
        q = *(void**)0x34;
        saved = 0xdba4c4;
    } else {
        saved = 0;
    }
    G1_func_006a5750();
    if (saved) {
        void (*fn2)(void*, void*, int) = *(void (**)(void*, void*, int))saved;
        if (fn2) {
            fn2(&q, &q, 2);
        }
    }
}
