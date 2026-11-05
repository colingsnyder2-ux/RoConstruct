// roc 2012-06 009b7d10  unit: CInstanceRecord::CNameItem  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b7d10
//
// 009b7d10  c701f40dc100         mov dword ptr [ecx], 0xc10df4
// 009b7d16  8b4904               mov ecx, dword ptr [ecx + 4]
// 009b7d19  85c9                 test ecx, ecx
// 009b7d1b  7407                 je 0x9b7d24
// 009b7d1d  51                   push ecx
// 009b7d1e  e897a6fcff           call 0x9823ba
// 009b7d23  59                   pop ecx
// 009b7d24  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009b7d10(void*);
struct S_func_009b7d10 {
    virtual ~S_func_009b7d10();
    void* m_p;
};
S_func_009b7d10::~S_func_009b7d10()
{
    if (m_p)
        G1_func_009b7d10(m_p);
}
