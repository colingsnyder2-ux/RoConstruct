// roc 2012-06 009b7cd0  unit: CInstanceRecord::CNameItem  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b7cd0
//
// 009b7cd0  c701dc0dc100         mov dword ptr [ecx], 0xc10ddc
// 009b7cd6  8b4904               mov ecx, dword ptr [ecx + 4]
// 009b7cd9  85c9                 test ecx, ecx
// 009b7cdb  7407                 je 0x9b7ce4
// 009b7cdd  51                   push ecx
// 009b7cde  e8d7a6fcff           call 0x9823ba
// 009b7ce3  59                   pop ecx
// 009b7ce4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009b7cd0(void*);
struct S_func_009b7cd0 {
    virtual ~S_func_009b7cd0();
    void* m_p;
};
S_func_009b7cd0::~S_func_009b7cd0()
{
    if (m_p)
        G1_func_009b7cd0(m_p);
}
