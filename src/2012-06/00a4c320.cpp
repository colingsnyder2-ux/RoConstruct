// roc 2012-06 00a4c320  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4c320
//
// 00a4c320  c7012830c200         mov dword ptr [ecx], 0xc23028
// 00a4c326  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a4c329  85c9                 test ecx, ecx
// 00a4c32b  7407                 je 0xa4c334
// 00a4c32d  51                   push ecx
// 00a4c32e  e88760f3ff           call 0x9823ba
// 00a4c333  59                   pop ecx
// 00a4c334  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a4c320(void*);
struct S_func_00a4c320 {
    virtual ~S_func_00a4c320();
    void* m_p;
};
S_func_00a4c320::~S_func_00a4c320()
{
    if (m_p)
        G1_func_00a4c320(m_p);
}
