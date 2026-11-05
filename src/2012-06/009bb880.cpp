// roc 2012-06 009bb880  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009bb880
//
// 009bb880  c7017018c100         mov dword ptr [ecx], 0xc11870
// 009bb886  8b4904               mov ecx, dword ptr [ecx + 4]
// 009bb889  85c9                 test ecx, ecx
// 009bb88b  7407                 je 0x9bb894
// 009bb88d  51                   push ecx
// 009bb88e  e8276bfcff           call 0x9823ba
// 009bb893  59                   pop ecx
// 009bb894  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009bb880(void*);
struct S_func_009bb880 {
    virtual ~S_func_009bb880();
    void* m_p;
};
S_func_009bb880::~S_func_009bb880()
{
    if (m_p)
        G1_func_009bb880(m_p);
}
