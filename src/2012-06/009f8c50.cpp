// roc 2012-06 009f8c50  unit: CXTPResourceManager  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f8c50
//
// 009f8c50  c701b0b0c100         mov dword ptr [ecx], 0xc1b0b0
// 009f8c56  8b4904               mov ecx, dword ptr [ecx + 4]
// 009f8c59  85c9                 test ecx, ecx
// 009f8c5b  7407                 je 0x9f8c64
// 009f8c5d  51                   push ecx
// 009f8c5e  e85797f8ff           call 0x9823ba
// 009f8c63  59                   pop ecx
// 009f8c64  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009f8c50(void*);
struct S_func_009f8c50 {
    virtual ~S_func_009f8c50();
    void* m_p;
};
S_func_009f8c50::~S_func_009f8c50()
{
    if (m_p)
        G1_func_009f8c50(m_p);
}
