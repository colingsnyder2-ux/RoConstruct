// roc 2012-06 00a70620  unit: CXTPRibbonTab  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a70620
//
// 00a70620  8bc1                 mov eax, ecx
// 00a70622  33c9                 xor ecx, ecx
// 00a70624  c700f065c200         mov dword ptr [eax], 0xc265f0
// 00a7062a  894804               mov dword ptr [eax + 4], ecx
// 00a7062d  894810               mov dword ptr [eax + 0x10], ecx
// 00a70630  89480c               mov dword ptr [eax + 0xc], ecx
// 00a70633  894808               mov dword ptr [eax + 8], ecx
// 00a70636  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a70620
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a70620();
};
S_func_00a70620::S_func_00a70620()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
