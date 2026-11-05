// roc 2012-06 009e77c0  unit: CXTPStatusBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e77c0
//
// 009e77c0  c7018c79c100         mov dword ptr [ecx], 0xc1798c
// 009e77c6  8b4904               mov ecx, dword ptr [ecx + 4]
// 009e77c9  85c9                 test ecx, ecx
// 009e77cb  7407                 je 0x9e77d4
// 009e77cd  51                   push ecx
// 009e77ce  e8e7abf9ff           call 0x9823ba
// 009e77d3  59                   pop ecx
// 009e77d4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009e77c0(void*);
struct S_func_009e77c0 {
    virtual ~S_func_009e77c0();
    void* m_p;
};
S_func_009e77c0::~S_func_009e77c0()
{
    if (m_p)
        G1_func_009e77c0(m_p);
}
