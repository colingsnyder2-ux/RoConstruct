// roc 2012-06 009de4c0  unit: CXTPTabClientWnd  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009de4c0
//
// 009de4c0  c7019468c100         mov dword ptr [ecx], 0xc16894
// 009de4c6  8b4904               mov ecx, dword ptr [ecx + 4]
// 009de4c9  85c9                 test ecx, ecx
// 009de4cb  7407                 je 0x9de4d4
// 009de4cd  51                   push ecx
// 009de4ce  e8e73efaff           call 0x9823ba
// 009de4d3  59                   pop ecx
// 009de4d4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009de4c0(void*);
struct S_func_009de4c0 {
    virtual ~S_func_009de4c0();
    void* m_p;
};
S_func_009de4c0::~S_func_009de4c0()
{
    if (m_p)
        G1_func_009de4c0(m_p);
}
