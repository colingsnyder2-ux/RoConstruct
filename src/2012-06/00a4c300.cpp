// roc 2012-06 00a4c300  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4c300
//
// 00a4c300  8bc1                 mov eax, ecx
// 00a4c302  33c9                 xor ecx, ecx
// 00a4c304  c7002830c200         mov dword ptr [eax], 0xc23028
// 00a4c30a  894804               mov dword ptr [eax + 4], ecx
// 00a4c30d  894810               mov dword ptr [eax + 0x10], ecx
// 00a4c310  89480c               mov dword ptr [eax + 0xc], ecx
// 00a4c313  894808               mov dword ptr [eax + 8], ecx
// 00a4c316  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a4c300
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a4c300();
};
S_func_00a4c300::S_func_00a4c300()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
