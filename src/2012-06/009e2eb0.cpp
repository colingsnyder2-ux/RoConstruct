// roc 2012-06 009e2eb0  unit: CXTPPropertyGrid  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e2eb0
//
// 009e2eb0  c7010071c100         mov dword ptr [ecx], 0xc17100
// 009e2eb6  8b4904               mov ecx, dword ptr [ecx + 4]
// 009e2eb9  85c9                 test ecx, ecx
// 009e2ebb  7407                 je 0x9e2ec4
// 009e2ebd  51                   push ecx
// 009e2ebe  e8f7f4f9ff           call 0x9823ba
// 009e2ec3  59                   pop ecx
// 009e2ec4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009e2eb0(void*);
struct S_func_009e2eb0 {
    virtual ~S_func_009e2eb0();
    void* m_p;
};
S_func_009e2eb0::~S_func_009e2eb0()
{
    if (m_p)
        G1_func_009e2eb0(m_p);
}
