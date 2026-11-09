// roc 2012-06 00a30600  unit: CXTPReportHyperlinks  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a30600
//
// 00a30600  c701a404c200         mov dword ptr [ecx], 0xc204a4
// 00a30606  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a30609  85c9                 test ecx, ecx
// 00a3060b  7407                 je 0xa30614
// 00a3060d  51                   push ecx
// 00a3060e  e8a71df5ff           call 0x9823ba
// 00a30613  59                   pop ecx
// 00a30614  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a30600(void*);
struct S_func_00a30600 {
    virtual ~S_func_00a30600();
    void* m_p;
};
S_func_00a30600::~S_func_00a30600()
{
    if (m_p)
        G1_func_00a30600(m_p);
}
