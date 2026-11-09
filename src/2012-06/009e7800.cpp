// roc 2012-06 009e7800  unit: CXTPStatusBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e7800
//
// 009e7800  c701a479c100         mov dword ptr [ecx], 0xc179a4
// 009e7806  8b4904               mov ecx, dword ptr [ecx + 4]
// 009e7809  85c9                 test ecx, ecx
// 009e780b  7407                 je 0x9e7814
// 009e780d  51                   push ecx
// 009e780e  e8a7abf9ff           call 0x9823ba
// 009e7813  59                   pop ecx
// 009e7814  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009e7800(void*);
struct S_func_009e7800 {
    virtual ~S_func_009e7800();
    void* m_p;
};
S_func_009e7800::~S_func_009e7800()
{
    if (m_p)
        G1_func_009e7800(m_p);
}
