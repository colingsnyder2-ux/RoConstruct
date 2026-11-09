// from server: 100% by colin
extern "C" void* __cdecl sub_00500060(unsigned int, unsigned int);
extern "C" void __cdecl sub_00500580(void*, int, unsigned int);
extern "C" void __cdecl sub_00630d23(void*);

extern unsigned int dword_896C40;
extern void* dword_896C3C;
extern char byte_778C60;

void func_0076fbd0()
{
    void* p = sub_00500060(0x28, 0x10);
    dword_896C3C = p;
    sub_00500580(p, 0, dword_896C40 * 4);
    sub_00630d23(&byte_778C60);
}
