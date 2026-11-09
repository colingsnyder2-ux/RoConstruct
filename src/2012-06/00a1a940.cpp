// roc 2012-06 00a1a940  unit: CXTPDockBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1a940
//
// 00a1a940  c70118dec100         mov dword ptr [ecx], 0xc1de18
// 00a1a946  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a1a949  85c9                 test ecx, ecx
// 00a1a94b  7407                 je 0xa1a954
// 00a1a94d  51                   push ecx
// 00a1a94e  e8677af6ff           call 0x9823ba
// 00a1a953  59                   pop ecx
// 00a1a954  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a1a940(void*);
struct S_func_00a1a940 {
    virtual ~S_func_00a1a940();
    void* m_p;
};
S_func_00a1a940::~S_func_00a1a940()
{
    if (m_p)
        G1_func_00a1a940(m_p);
}
