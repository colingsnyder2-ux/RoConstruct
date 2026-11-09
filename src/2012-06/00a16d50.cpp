// roc 2012-06 00a16d50  unit: CXTPKeyboardManager  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a16d50
//
// 00a16d50  c70128d5c100         mov dword ptr [ecx], 0xc1d528
// 00a16d56  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a16d59  85c9                 test ecx, ecx
// 00a16d5b  7407                 je 0xa16d64
// 00a16d5d  51                   push ecx
// 00a16d5e  e857b6f6ff           call 0x9823ba
// 00a16d63  59                   pop ecx
// 00a16d64  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a16d50(void*);
struct S_func_00a16d50 {
    virtual ~S_func_00a16d50();
    void* m_p;
};
S_func_00a16d50::~S_func_00a16d50()
{
    if (m_p)
        G1_func_00a16d50(m_p);
}
