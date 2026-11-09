// roc 2012-06 009fa6a0  unit: CXTPControlGalleryPaintManager  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009fa6a0
//
// 009fa6a0  c701c0b1c100         mov dword ptr [ecx], 0xc1b1c0
// 009fa6a6  8b4904               mov ecx, dword ptr [ecx + 4]
// 009fa6a9  85c9                 test ecx, ecx
// 009fa6ab  7407                 je 0x9fa6b4
// 009fa6ad  51                   push ecx
// 009fa6ae  e8077df8ff           call 0x9823ba
// 009fa6b3  59                   pop ecx
// 009fa6b4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009fa6a0(void*);
struct S_func_009fa6a0 {
    virtual ~S_func_009fa6a0();
    void* m_p;
};
S_func_009fa6a0::~S_func_009fa6a0()
{
    if (m_p)
        G1_func_009fa6a0(m_p);
}
