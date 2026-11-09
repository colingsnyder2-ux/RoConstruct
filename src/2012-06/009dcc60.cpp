// roc 2012-06 009dcc60  unit: CXTPTabClientWnd  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009dcc60
//
// 009dcc60  c7016468c100         mov dword ptr [ecx], 0xc16864
// 009dcc66  8b4904               mov ecx, dword ptr [ecx + 4]
// 009dcc69  85c9                 test ecx, ecx
// 009dcc6b  7407                 je 0x9dcc74
// 009dcc6d  51                   push ecx
// 009dcc6e  e84757faff           call 0x9823ba
// 009dcc73  59                   pop ecx
// 009dcc74  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009dcc60(void*);
struct S_func_009dcc60 {
    virtual ~S_func_009dcc60();
    void* m_p;
};
S_func_009dcc60::~S_func_009dcc60()
{
    if (m_p)
        G1_func_009dcc60(m_p);
}
