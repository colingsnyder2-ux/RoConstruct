// roc 2012-06 009f0890  unit: CXTPPropertyGridView  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f0890
//
// 009f0890  c7019c90c100         mov dword ptr [ecx], 0xc1909c
// 009f0896  8b4904               mov ecx, dword ptr [ecx + 4]
// 009f0899  85c9                 test ecx, ecx
// 009f089b  7407                 je 0x9f08a4
// 009f089d  51                   push ecx
// 009f089e  e8171bf9ff           call 0x9823ba
// 009f08a3  59                   pop ecx
// 009f08a4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009f0890(void*);
struct S_func_009f0890 {
    virtual ~S_func_009f0890();
    void* m_p;
};
S_func_009f0890::~S_func_009f0890()
{
    if (m_p)
        G1_func_009f0890(m_p);
}
