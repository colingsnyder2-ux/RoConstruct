// roc 2012-06 009b8df0  unit: CInstanceRecord  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b8df0
//
// 009b8df0  8bc1                 mov eax, ecx
// 009b8df2  33c9                 xor ecx, ecx
// 009b8df4  c7008c0fc100         mov dword ptr [eax], 0xc10f8c
// 009b8dfa  894804               mov dword ptr [eax + 4], ecx
// 009b8dfd  894810               mov dword ptr [eax + 0x10], ecx
// 009b8e00  89480c               mov dword ptr [eax + 0xc], ecx
// 009b8e03  894808               mov dword ptr [eax + 8], ecx
// 009b8e06  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009b8df0
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009b8df0();
};
S_func_009b8df0::S_func_009b8df0()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
