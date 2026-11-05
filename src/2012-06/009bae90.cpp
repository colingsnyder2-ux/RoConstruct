// roc 2012-06 009bae90  unit: VCXTPReportRecords::?$CXTPHeapObjectT  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009bae90
//
// 009bae90  c701c817c100         mov dword ptr [ecx], 0xc117c8
// 009bae96  8b4904               mov ecx, dword ptr [ecx + 4]
// 009bae99  85c9                 test ecx, ecx
// 009bae9b  7407                 je 0x9baea4
// 009bae9d  51                   push ecx
// 009bae9e  e81775fcff           call 0x9823ba
// 009baea3  59                   pop ecx
// 009baea4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009bae90(void*);
struct S_func_009bae90 {
    virtual ~S_func_009bae90();
    void* m_p;
};
S_func_009bae90::~S_func_009bae90()
{
    if (m_p)
        G1_func_009bae90(m_p);
}
