// from server: 100% by tester
// roc 2007-08 0076fd90  unit: seg_00760000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076fd90
//
// 0076fd90  6a10                 push 0x10
// 0076fd92  6a28                 push 0x28
// 0076fd94  e8c702d9ff           call 0x500060
// 0076fd99  8b0ddc758900         mov ecx, dword ptr [0x8975dc]
// 0076fd9f  8d148d00000000       lea edx, [ecx*4]
// 0076fda6  52                   push edx
// 0076fda7  6a00                 push 0
// 0076fda9  50                   push eax
// 0076fdaa  a3d8758900           mov dword ptr [0x8975d8], eax
// 0076fdaf  e8cc07d9ff           call 0x500580
// 0076fdb4  68608d7700           push 0x778d60
// 0076fdb9  e8650fecff           call 0x630d23
// 0076fdbe  83c418               add esp, 0x18
// 0076fdc1  c3                   ret 

extern "C" void* __cdecl sub_500060(unsigned int, unsigned int);
extern "C" void __cdecl sub_500580(void*, int, unsigned int);
extern "C" void __cdecl sub_630d23(void*);

extern unsigned int dword_8975DC;
extern void* dword_8975D8;

void sub_76FD90()
{
    void* p = sub_500060(0x28, 0x10);
    unsigned int n = dword_8975DC;
    dword_8975D8 = p;
    sub_500580(p, 0, n * 4);
    sub_630d23((void*)0x778D60);
}
