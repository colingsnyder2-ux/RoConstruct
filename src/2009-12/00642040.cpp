// from server: 54% by atomic.potato
struct S {
    void* f0;
    void* f4;
    void* f8;
    void* fc;
    char f10;
    char f11;
    S* ctor(void* a, void* b);
};

extern "C" void* __cdecl sub_6322e0(void*);
extern "C" void* __cdecl sub_6325b0(void*);
extern "C" void __cdecl sub_7e1df0();
extern char byte_B901E4;

S* S::ctor(void* a, void* b)
{
    f0 = (void*)0x99fd70;
    f4 = sub_6322e0(a);
    if (byte_B901E4) {
        sub_7e1df0();
    }
    f0 = (void*)0x9ba0a4;
    f8 = (void*)0xb03434;
    fc = sub_6325b0(a);
    f10 = 0;
    f11 = 0;
    return this;
}
