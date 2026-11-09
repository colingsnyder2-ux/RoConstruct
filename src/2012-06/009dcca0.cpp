// roc 2012-06 009dcca0  unit: CXTPTabClientWnd  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009dcca0
//
// 009dcca0  c7017c68c100         mov dword ptr [ecx], 0xc1687c
// 009dcca6  8b4904               mov ecx, dword ptr [ecx + 4]
// 009dcca9  85c9                 test ecx, ecx
// 009dccab  7407                 je 0x9dccb4
// 009dccad  51                   push ecx
// 009dccae  e80757faff           call 0x9823ba
// 009dccb3  59                   pop ecx
// 009dccb4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009dcca0(void*);
struct S_func_009dcca0 {
    virtual ~S_func_009dcca0();
    void* m_p;
};
S_func_009dcca0::~S_func_009dcca0()
{
    if (m_p)
        G1_func_009dcca0(m_p);
}
