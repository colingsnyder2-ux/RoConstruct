// roc 2012-06 009b8e10  unit: CInstanceRecord  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b8e10
//
// 009b8e10  c7018c0fc100         mov dword ptr [ecx], 0xc10f8c
// 009b8e16  8b4904               mov ecx, dword ptr [ecx + 4]
// 009b8e19  85c9                 test ecx, ecx
// 009b8e1b  7407                 je 0x9b8e24
// 009b8e1d  51                   push ecx
// 009b8e1e  e89795fcff           call 0x9823ba
// 009b8e23  59                   pop ecx
// 009b8e24  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009b8e10(void*);
struct S_func_009b8e10 {
    virtual ~S_func_009b8e10();
    void* m_p;
};
S_func_009b8e10::~S_func_009b8e10()
{
    if (m_p)
        G1_func_009b8e10(m_p);
}
