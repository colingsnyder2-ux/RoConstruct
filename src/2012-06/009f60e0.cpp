// roc 2012-06 009f60e0  unit: CXTPWinThemeWrapper  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f60e0
//
// 009f60e0  c70108a4c100         mov dword ptr [ecx], 0xc1a408
// 009f60e6  8b4904               mov ecx, dword ptr [ecx + 4]
// 009f60e9  85c9                 test ecx, ecx
// 009f60eb  7407                 je 0x9f60f4
// 009f60ed  51                   push ecx
// 009f60ee  e8c7c2f8ff           call 0x9823ba
// 009f60f3  59                   pop ecx
// 009f60f4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009f60e0(void*);
struct S_func_009f60e0 {
    virtual ~S_func_009f60e0();
    void* m_p;
};
S_func_009f60e0::~S_func_009f60e0()
{
    if (m_p)
        G1_func_009f60e0(m_p);
}
