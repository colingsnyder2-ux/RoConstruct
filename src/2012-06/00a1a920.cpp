// roc 2012-06 00a1a920  unit: CXTPDockBar  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1a920
//
// 00a1a920  8bc1                 mov eax, ecx
// 00a1a922  33c9                 xor ecx, ecx
// 00a1a924  c70018dec100         mov dword ptr [eax], 0xc1de18
// 00a1a92a  894804               mov dword ptr [eax + 4], ecx
// 00a1a92d  894810               mov dword ptr [eax + 0x10], ecx
// 00a1a930  89480c               mov dword ptr [eax + 0xc], ecx
// 00a1a933  894808               mov dword ptr [eax + 8], ecx
// 00a1a936  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a1a920
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a1a920();
};
S_func_00a1a920::S_func_00a1a920()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
