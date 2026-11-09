// roc 2012-06 00a34a70  unit: CXTPDockingPaneAutoHidePanel  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a34a70
//
// 00a34a70  8bc1                 mov eax, ecx
// 00a34a72  33c9                 xor ecx, ecx
// 00a34a74  c7007809c200         mov dword ptr [eax], 0xc20978
// 00a34a7a  894804               mov dword ptr [eax + 4], ecx
// 00a34a7d  894810               mov dword ptr [eax + 0x10], ecx
// 00a34a80  89480c               mov dword ptr [eax + 0xc], ecx
// 00a34a83  894808               mov dword ptr [eax + 8], ecx
// 00a34a86  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a34a70
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a34a70();
};
S_func_00a34a70::S_func_00a34a70()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
