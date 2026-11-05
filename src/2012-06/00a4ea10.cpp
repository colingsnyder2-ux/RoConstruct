// roc 2012-06 00a4ea10  unit: CXTPTabPaintManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4ea10
//
// 00a4ea10  8bc1                 mov eax, ecx
// 00a4ea12  33c9                 xor ecx, ecx
// 00a4ea14  c7001c34c200         mov dword ptr [eax], 0xc2341c
// 00a4ea1a  894804               mov dword ptr [eax + 4], ecx
// 00a4ea1d  894810               mov dword ptr [eax + 0x10], ecx
// 00a4ea20  89480c               mov dword ptr [eax + 0xc], ecx
// 00a4ea23  894808               mov dword ptr [eax + 8], ecx
// 00a4ea26  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a4ea10
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a4ea10();
};
S_func_00a4ea10::S_func_00a4ea10()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
