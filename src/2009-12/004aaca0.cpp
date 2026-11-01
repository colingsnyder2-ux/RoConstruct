// from server: 43% by atomic.potato
struct S_func_004aaca0 {
    void __cdecl f(unsigned int a1);
};

extern "C" void __cdecl sub_007f3860(unsigned int);
extern "C" void __cdecl sub_007f4878(void*, void*);
extern "C" void __stdcall sub_0098b748(void*);

void S_func_004aaca0::f(unsigned int a1)
{
    if (a1 > 0) {
        unsigned int q = 0xffffffffu / a1;
        if (q < 0x50) {
            void* p = 0;
            sub_0098b748(&p);
            sub_007f4878(&p, (void*)0xa8ef38);
            return;
        }
    }
    sub_007f3860(0);
}
