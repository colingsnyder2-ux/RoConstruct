// roc 2012-06 00a34a90  unit: CXTPDockingPaneAutoHidePanel  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a34a90
//
// 00a34a90  c7017809c200         mov dword ptr [ecx], 0xc20978
// 00a34a96  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a34a99  85c9                 test ecx, ecx
// 00a34a9b  7407                 je 0xa34aa4
// 00a34a9d  51                   push ecx
// 00a34a9e  e817d9f4ff           call 0x9823ba
// 00a34aa3  59                   pop ecx
// 00a34aa4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a34a90(void*);
struct S_func_00a34a90 {
    virtual ~S_func_00a34a90();
    void* m_p;
};
S_func_00a34a90::~S_func_00a34a90()
{
    if (m_p)
        G1_func_00a34a90(m_p);
}
