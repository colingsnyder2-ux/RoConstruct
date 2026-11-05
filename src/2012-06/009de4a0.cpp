// roc 2012-06 009de4a0  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009de4a0
//
// 009de4a0  8bc1                 mov eax, ecx
// 009de4a2  33c9                 xor ecx, ecx
// 009de4a4  c7009468c100         mov dword ptr [eax], 0xc16894
// 009de4aa  894804               mov dword ptr [eax + 4], ecx
// 009de4ad  894810               mov dword ptr [eax + 0x10], ecx
// 009de4b0  89480c               mov dword ptr [eax + 0xc], ecx
// 009de4b3  894808               mov dword ptr [eax + 8], ecx
// 009de4b6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009de4a0
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009de4a0();
};
S_func_009de4a0::S_func_009de4a0()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
