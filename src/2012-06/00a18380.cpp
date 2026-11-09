// roc 2012-06 00a18380  unit: CXTPShortcutManager::CKeyHelper  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a18380
//
// 00a18380  c70160d5c100         mov dword ptr [ecx], 0xc1d560
// 00a18386  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a18389  85c9                 test ecx, ecx
// 00a1838b  7407                 je 0xa18394
// 00a1838d  51                   push ecx
// 00a1838e  e827a0f6ff           call 0x9823ba
// 00a18393  59                   pop ecx
// 00a18394  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a18380(void*);
struct S_func_00a18380 {
    virtual ~S_func_00a18380();
    void* m_p;
};
S_func_00a18380::~S_func_00a18380()
{
    if (m_p)
        G1_func_00a18380(m_p);
}
