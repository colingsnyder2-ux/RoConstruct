// roc 2012-06 009f2b70  unit: CXTPPropertyGridItemConstraints  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f2b70
//
// 009f2b70  c7013094c100         mov dword ptr [ecx], 0xc19430
// 009f2b76  8b4904               mov ecx, dword ptr [ecx + 4]
// 009f2b79  85c9                 test ecx, ecx
// 009f2b7b  7407                 je 0x9f2b84
// 009f2b7d  51                   push ecx
// 009f2b7e  e837f8f8ff           call 0x9823ba
// 009f2b83  59                   pop ecx
// 009f2b84  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009f2b70(void*);
struct S_func_009f2b70 {
    virtual ~S_func_009f2b70();
    void* m_p;
};
S_func_009f2b70::~S_func_009f2b70()
{
    if (m_p)
        G1_func_009f2b70(m_p);
}
