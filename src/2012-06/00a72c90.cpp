// roc 2012-06 00a72c90  unit: CXTPRibbonGroup  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a72c90
//
// 00a72c90  c701046fc200         mov dword ptr [ecx], 0xc26f04
// 00a72c96  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a72c99  85c9                 test ecx, ecx
// 00a72c9b  7407                 je 0xa72ca4
// 00a72c9d  51                   push ecx
// 00a72c9e  e817f7f0ff           call 0x9823ba
// 00a72ca3  59                   pop ecx
// 00a72ca4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a72c90(void*);
struct S_func_00a72c90 {
    virtual ~S_func_00a72c90();
    void* m_p;
};
S_func_00a72c90::~S_func_00a72c90()
{
    if (m_p)
        G1_func_00a72c90(m_p);
}
