// from server: 100% by colin
extern "C" void __cdecl sub_4015A0(void*, void*);
extern "C" void __cdecl sub_9831F5(void*);

extern unsigned char byte_E4DFB4;
extern int dword_E4DFAC;
extern int dword_E4DFB0;

struct S {
    int f();
};

int S::f() {
    sub_4015A0((void*)0xE4DFB8, (void*)0x7D7A30);
    int one = 1;
    if (!(byte_E4DFB4 & one)) {
        *(int*)&byte_E4DFB4 |= one;
        dword_E4DFAC = 0;
        dword_E4DFB0 = 0;
        sub_9831F5((void*)0xB1D0F0);
    }
    return (int)&dword_E4DFAC;
}
