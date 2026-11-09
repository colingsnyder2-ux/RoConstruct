// roc 2012-06 00a70640  unit: CXTPRibbonTab  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a70640
//
// 00a70640  c701f065c200         mov dword ptr [ecx], 0xc265f0
// 00a70646  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a70649  85c9                 test ecx, ecx
// 00a7064b  7407                 je 0xa70654
// 00a7064d  51                   push ecx
// 00a7064e  e8671df1ff           call 0x9823ba
// 00a70653  59                   pop ecx
// 00a70654  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a70640(void*);
struct S_func_00a70640 {
    virtual ~S_func_00a70640();
    void* m_p;
};
S_func_00a70640::~S_func_00a70640()
{
    if (m_p)
        G1_func_00a70640(m_p);
}
