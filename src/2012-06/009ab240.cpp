// roc 2012-06 009ab240  unit: CXTPReportControl  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ab240
//
// 009ab240  c7015402c100         mov dword ptr [ecx], 0xc10254
// 009ab246  8b4904               mov ecx, dword ptr [ecx + 4]
// 009ab249  85c9                 test ecx, ecx
// 009ab24b  7407                 je 0x9ab254
// 009ab24d  51                   push ecx
// 009ab24e  e86771fdff           call 0x9823ba
// 009ab253  59                   pop ecx
// 009ab254  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009ab240(void*);
struct S_func_009ab240 {
    virtual ~S_func_009ab240();
    void* m_p;
};
S_func_009ab240::~S_func_009ab240()
{
    if (m_p)
        G1_func_009ab240(m_p);
}
