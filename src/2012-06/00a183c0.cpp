// roc 2012-06 00a183c0  unit: CXTPShortcutManager::CKeyHelper  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a183c0
//
// 00a183c0  c70178d5c100         mov dword ptr [ecx], 0xc1d578
// 00a183c6  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a183c9  85c9                 test ecx, ecx
// 00a183cb  7407                 je 0xa183d4
// 00a183cd  51                   push ecx
// 00a183ce  e8e79ff6ff           call 0x9823ba
// 00a183d3  59                   pop ecx
// 00a183d4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a183c0(void*);
struct S_func_00a183c0 {
    virtual ~S_func_00a183c0();
    void* m_p;
};
S_func_00a183c0::~S_func_00a183c0()
{
    if (m_p)
        G1_func_00a183c0(m_p);
}
