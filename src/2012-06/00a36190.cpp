// roc 2012-06 00a36190  unit: CXTPDockingPaneWindowSelect  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a36190
//
// 00a36190  8bc1                 mov eax, ecx
// 00a36192  33c9                 xor ecx, ecx
// 00a36194  c700d40ec200         mov dword ptr [eax], 0xc20ed4
// 00a3619a  894804               mov dword ptr [eax + 4], ecx
// 00a3619d  894810               mov dword ptr [eax + 0x10], ecx
// 00a361a0  89480c               mov dword ptr [eax + 0xc], ecx
// 00a361a3  894808               mov dword ptr [eax + 8], ecx
// 00a361a6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a36190
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a36190();
};
S_func_00a36190::S_func_00a36190()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
