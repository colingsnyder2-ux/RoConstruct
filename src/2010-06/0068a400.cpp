// from server: 25% by atomic.potato
struct S {
    char pad0[8];
    void* field8;
    void* fieldC;
    char pad10[0x28];
    void method();
};

extern "C" void __stdcall sub_6896B0();
extern "C" void __stdcall sub_684FC0();

void S::method() {
    char buf[0x20];
    *(int*)buf = 0;
    void* p = *(void**)((char*)this + 0x44);
    if (p) {
        *(void**)buf = p;
        void** pp = *(void***)p;
        void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))pp[0];
        fn((char*)buf + 8, buf, 0);
    }
    sub_6896B0();
    sub_684FC0();
    void* q = *(void**)((char*)this + 0x24);
    if (q) {
        void** qq = *(void***)q;
        if (qq) {
            void (*fn2)(void*, void*, int) = (void (*)(void*, void*, int))qq[0];
            fn2((char*)this + 0x2c, (char*)this + 0x2c, 2);
        }
    }
}
