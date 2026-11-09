// from server: 86% by atomic.potato
struct S {
    char pad[0xbc];
    char flag;
    void f(int);
};

extern "C" void __stdcall sub_684660(int);
extern "C" char __cdecl sub_5400a0(void*, int);

void S::f(int a) {
    sub_684660(a);
    if (this->flag == 0) {
        if (sub_5400a0(this, 0)) {
            void** vt = *(void***)this;
            void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vt[0x58 / 4];
            fn(this);
        }
    }
}
