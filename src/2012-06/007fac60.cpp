// from server: 100% by tester
extern "C" void __cdecl sub_4015A0(void*, void*);
extern "C" void __cdecl sub_9831F5(void*);

extern unsigned char byte_E4F4A4;
extern unsigned int dword_E4F4A4;
extern unsigned int dword_E4F49C;
extern unsigned int dword_E4F4A0;

struct S {
    unsigned int* f();
};

unsigned int* S::f()
{
    sub_4015A0((void*)0x7FAB70, (void*)0xE4F4C4);
    if ((byte_E4F4A4 & 1) == 0) {
        dword_E4F4A4 |= 1;
        dword_E4F49C = 0;
        dword_E4F4A0 = 0;
        sub_9831F5((void*)0xB1DBE0);
    }
    return &dword_E4F49C;
}
