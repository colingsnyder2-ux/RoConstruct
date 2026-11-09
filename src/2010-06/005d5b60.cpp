// from server: 42% by atomic.potato
extern "C" void __stdcall helper_009ea40c();
extern "C" void __stdcall helper_005d5b60();

struct S {
    void f(int a, int b);
};

void S::f(int a, int b) {
    helper_009ea40c();
    void (*fn)(int) = *(void (**)(int))((char*)this + 0x38);
    int arg = *(int*)((char*)this + 0x3c) + b;
    fn(arg);
    void* p = *(void**)((char*)&a + 4);
    if (p) {
        void** vt = *(void***)p;
        void (*dtor)(void*, int) = (void (*)(void*, int))vt[0];
        dtor(p, 1);
    }
}
