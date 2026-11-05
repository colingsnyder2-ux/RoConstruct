// roc 2012-06 00a36150  unit: CXTPDockingPaneWindowSelect  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a36150
//
// 00a36150  8bc1                 mov eax, ecx
// 00a36152  33c9                 xor ecx, ecx
// 00a36154  c700bc0ec200         mov dword ptr [eax], 0xc20ebc
// 00a3615a  894804               mov dword ptr [eax + 4], ecx
// 00a3615d  894810               mov dword ptr [eax + 0x10], ecx
// 00a36160  89480c               mov dword ptr [eax + 0xc], ecx
// 00a36163  894808               mov dword ptr [eax + 8], ecx
// 00a36166  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a36150
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a36150();
};
S_func_00a36150::S_func_00a36150()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
