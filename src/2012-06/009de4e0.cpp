// roc 2012-06 009de4e0  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009de4e0
//
// 009de4e0  8bc1                 mov eax, ecx
// 009de4e2  33c9                 xor ecx, ecx
// 009de4e4  c700ac68c100         mov dword ptr [eax], 0xc168ac
// 009de4ea  894804               mov dword ptr [eax + 4], ecx
// 009de4ed  894810               mov dword ptr [eax + 0x10], ecx
// 009de4f0  89480c               mov dword ptr [eax + 0xc], ecx
// 009de4f3  894808               mov dword ptr [eax + 8], ecx
// 009de4f6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009de4e0
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009de4e0();
};
S_func_009de4e0::S_func_009de4e0()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
