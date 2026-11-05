// roc 2012-06 009bb780  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009bb780
//
// 009bb780  c7015818c100         mov dword ptr [ecx], 0xc11858
// 009bb786  8b4904               mov ecx, dword ptr [ecx + 4]
// 009bb789  85c9                 test ecx, ecx
// 009bb78b  7407                 je 0x9bb794
// 009bb78d  51                   push ecx
// 009bb78e  e8276cfcff           call 0x9823ba
// 009bb793  59                   pop ecx
// 009bb794  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009bb780(void*);
struct S_func_009bb780 {
    virtual ~S_func_009bb780();
    void* m_p;
};
S_func_009bb780::~S_func_009bb780()
{
    if (m_p)
        G1_func_009bb780(m_p);
}
