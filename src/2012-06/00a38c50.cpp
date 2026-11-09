// roc 2012-06 00a38c50  unit: CXTPDockingPaneMiniWnd  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a38c50
//
// 00a38c50  c7012814c200         mov dword ptr [ecx], 0xc21428
// 00a38c56  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a38c59  85c9                 test ecx, ecx
// 00a38c5b  7407                 je 0xa38c64
// 00a38c5d  51                   push ecx
// 00a38c5e  e85797f4ff           call 0x9823ba
// 00a38c63  59                   pop ecx
// 00a38c64  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a38c50(void*);
struct S_func_00a38c50 {
    virtual ~S_func_00a38c50();
    void* m_p;
};
S_func_00a38c50::~S_func_00a38c50()
{
    if (m_p)
        G1_func_00a38c50(m_p);
}
