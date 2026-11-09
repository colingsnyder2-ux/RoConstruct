// roc 2012-06 00a567a0  unit: CXTPPropertyGridInplaceButton  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a567a0
//
// 00a567a0  c7016835c200         mov dword ptr [ecx], 0xc23568
// 00a567a6  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a567a9  85c9                 test ecx, ecx
// 00a567ab  7407                 je 0xa567b4
// 00a567ad  51                   push ecx
// 00a567ae  e807bcf2ff           call 0x9823ba
// 00a567b3  59                   pop ecx
// 00a567b4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a567a0(void*);
struct S_func_00a567a0 {
    virtual ~S_func_00a567a0();
    void* m_p;
};
S_func_00a567a0::~S_func_00a567a0()
{
    if (m_p)
        G1_func_00a567a0(m_p);
}
