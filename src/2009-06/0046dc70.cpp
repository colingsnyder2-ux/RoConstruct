// from server: 100% by why2
struct S {
    void* field0;
    void* field4;
    void f();
};

void S::f()
{
    void* p = field4;
    if (p != 0) {
        void** vtbl = *(void***)p;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vtbl[2];
        fn(p);
    }
}
