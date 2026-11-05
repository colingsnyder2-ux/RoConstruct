// roc 2012-06 00a16d10  unit: CXTPKeyboardManager  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a16d10
//
// 00a16d10  c70110d5c100         mov dword ptr [ecx], 0xc1d510
// 00a16d16  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a16d19  85c9                 test ecx, ecx
// 00a16d1b  7407                 je 0xa16d24
// 00a16d1d  51                   push ecx
// 00a16d1e  e897b6f6ff           call 0x9823ba
// 00a16d23  59                   pop ecx
// 00a16d24  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a16d10(void*);
struct S_func_00a16d10 {
    virtual ~S_func_00a16d10();
    void* m_p;
};
S_func_00a16d10::~S_func_00a16d10()
{
    if (m_p)
        G1_func_00a16d10(m_p);
}
