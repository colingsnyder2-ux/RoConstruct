// roc 2012-06 009de500  unit: CXTPTabClientWnd  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009de500
//
// 009de500  c701ac68c100         mov dword ptr [ecx], 0xc168ac
// 009de506  8b4904               mov ecx, dword ptr [ecx + 4]
// 009de509  85c9                 test ecx, ecx
// 009de50b  7407                 je 0x9de514
// 009de50d  51                   push ecx
// 009de50e  e8a73efaff           call 0x9823ba
// 009de513  59                   pop ecx
// 009de514  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009de500(void*);
struct S_func_009de500 {
    virtual ~S_func_009de500();
    void* m_p;
};
S_func_009de500::~S_func_009de500()
{
    if (m_p)
        G1_func_009de500(m_p);
}
