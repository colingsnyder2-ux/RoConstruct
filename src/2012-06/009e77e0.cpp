// roc 2012-06 009e77e0  unit: CXTPStatusBar  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e77e0
//
// 009e77e0  8bc1                 mov eax, ecx
// 009e77e2  33c9                 xor ecx, ecx
// 009e77e4  c700a479c100         mov dword ptr [eax], 0xc179a4
// 009e77ea  894804               mov dword ptr [eax + 4], ecx
// 009e77ed  894810               mov dword ptr [eax + 0x10], ecx
// 009e77f0  89480c               mov dword ptr [eax + 0xc], ecx
// 009e77f3  894808               mov dword ptr [eax + 8], ecx
// 009e77f6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009e77e0
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009e77e0();
};
S_func_009e77e0::S_func_009e77e0()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
