// from server: 28% by atomic.potato
struct S {
    char pad0[8];
    void* p8;
    char padC[4];
    void* p10;
    void f();
};

extern "C" {
    void __stdcall sub_b22644(void*);
    void __stdcall sub_b2263c(void*);
}

void S::f()
{
    if (p10 != 0) {
        char buf1[28];
        sub_b22644(buf1);
        char buf2[28];
        sub_b22644(buf2);
        void* q = p8;
        void (*fn)(void*) = *(void (**)(void*))q;
        fn((char*)this + 8);
    }
    sub_b2263c((char*)this + 0x1c);
    sub_b2263c((char*)this + 0x38);
}
