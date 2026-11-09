// roc 2012-06 009a28f0  unit: MyXTPCommandBars  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009a28f0
//
// 009a28f0  8bc1                 mov eax, ecx
// 009a28f2  33c9                 xor ecx, ecx
// 009a28f4  c700b4f3c000         mov dword ptr [eax], 0xc0f3b4
// 009a28fa  894804               mov dword ptr [eax + 4], ecx
// 009a28fd  894810               mov dword ptr [eax + 0x10], ecx
// 009a2900  89480c               mov dword ptr [eax + 0xc], ecx
// 009a2903  894808               mov dword ptr [eax + 8], ecx
// 009a2906  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009a28f0
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009a28f0();
};
S_func_009a28f0::S_func_009a28f0()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
