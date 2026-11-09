// roc 2012-06 00a16d30  unit: CXTPKeyboardManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a16d30
//
// 00a16d30  8bc1                 mov eax, ecx
// 00a16d32  33c9                 xor ecx, ecx
// 00a16d34  c70028d5c100         mov dword ptr [eax], 0xc1d528
// 00a16d3a  894804               mov dword ptr [eax + 4], ecx
// 00a16d3d  894810               mov dword ptr [eax + 0x10], ecx
// 00a16d40  89480c               mov dword ptr [eax + 0xc], ecx
// 00a16d43  894808               mov dword ptr [eax + 8], ecx
// 00a16d46  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a16d30
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a16d30();
};
S_func_00a16d30::S_func_00a16d30()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
