// from server: 100% by colin
// roc 2007-08 0076d7f0  unit: seg_00760000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076d7f0

extern "C" void* __cdecl sub_500060(unsigned int, unsigned int);
extern "C" void __cdecl sub_500580(void*, int, unsigned int);
extern "C" void __cdecl sub_630d23(void*);

extern unsigned int dword_88AC48;
extern void* dword_88AC44;

void sub_76D7F0()
{
    void* p = sub_500060(0x28, 0x10);
    dword_88AC44 = p;
    sub_500580(p, 0, dword_88AC48 * 4);
    sub_630d23((void*)0x777F70);
}
