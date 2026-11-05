// roc 2012-06 009f08d0  unit: CXTPPropertyGridView  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f08d0
//
// 009f08d0  c701b490c100         mov dword ptr [ecx], 0xc190b4
// 009f08d6  8b4904               mov ecx, dword ptr [ecx + 4]
// 009f08d9  85c9                 test ecx, ecx
// 009f08db  7407                 je 0x9f08e4
// 009f08dd  51                   push ecx
// 009f08de  e8d71af9ff           call 0x9823ba
// 009f08e3  59                   pop ecx
// 009f08e4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009f08d0(void*);
struct S_func_009f08d0 {
    virtual ~S_func_009f08d0();
    void* m_p;
};
S_func_009f08d0::~S_func_009f08d0()
{
    if (m_p)
        G1_func_009f08d0(m_p);
}
