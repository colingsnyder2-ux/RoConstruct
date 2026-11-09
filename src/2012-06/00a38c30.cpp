// roc 2012-06 00a38c30  unit: CXTPDockingPaneMiniWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a38c30
//
// 00a38c30  8bc1                 mov eax, ecx
// 00a38c32  33c9                 xor ecx, ecx
// 00a38c34  c7002814c200         mov dword ptr [eax], 0xc21428
// 00a38c3a  894804               mov dword ptr [eax + 4], ecx
// 00a38c3d  894810               mov dword ptr [eax + 0x10], ecx
// 00a38c40  89480c               mov dword ptr [eax + 0xc], ecx
// 00a38c43  894808               mov dword ptr [eax + 8], ecx
// 00a38c46  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a38c30
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a38c30();
};
S_func_00a38c30::S_func_00a38c30()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
