// from server: 100% by colin
extern "C" void* __cdecl sub_500060(int, int);
extern "C" void __cdecl sub_500580(void*, int, unsigned int);
extern "C" void __cdecl sub_630d23(void*);

extern unsigned int dword_896C20;
extern void* dword_896C1C;

void __cdecl sub_76FAD0()
{
    void* p = sub_500060(0x28, 0x10);
    unsigned int n = dword_896C20;
    dword_896C1C = p;
    sub_500580(p, 0, n * 4);
    sub_630d23((void*)0x778D20);
}
