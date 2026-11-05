// from server: 100% by colin
extern "C" void* __cdecl sub_00500060(int, int);
extern "C" void __cdecl sub_00500580(void*, int, unsigned int);
extern "C" void __cdecl sub_00630d23(void*);

extern int dword_8975CC;
extern void* dword_8975C8;
extern char byte_778D80;

void func_0076fcd0()
{
    void* p = sub_00500060(0x28, 0x10);
    dword_8975C8 = p;
    sub_00500580(p, 0, (unsigned int)dword_8975CC * 4);
    sub_00630d23(&byte_778D80);
}
