// roc 2012-06 009ebb20  unit: CXTPToolTipContext::CStandardToolTip  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ebb20
//
// 009ebb20  c7019c82c100         mov dword ptr [ecx], 0xc1829c
// 009ebb26  8b4904               mov ecx, dword ptr [ecx + 4]
// 009ebb29  85c9                 test ecx, ecx
// 009ebb2b  7407                 je 0x9ebb34
// 009ebb2d  51                   push ecx
// 009ebb2e  e88768f9ff           call 0x9823ba
// 009ebb33  59                   pop ecx
// 009ebb34  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009ebb20(void*);
struct S_func_009ebb20 {
    virtual ~S_func_009ebb20();
    void* m_p;
};
S_func_009ebb20::~S_func_009ebb20()
{
    if (m_p)
        G1_func_009ebb20(m_p);
}
