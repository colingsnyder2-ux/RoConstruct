// roc 2012-06 009c31d0  unit: CXTPControls  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c31d0
//
// 009c31d0  c701f82fc100         mov dword ptr [ecx], 0xc12ff8
// 009c31d6  8b4904               mov ecx, dword ptr [ecx + 4]
// 009c31d9  85c9                 test ecx, ecx
// 009c31db  7407                 je 0x9c31e4
// 009c31dd  51                   push ecx
// 009c31de  e8d7f1fbff           call 0x9823ba
// 009c31e3  59                   pop ecx
// 009c31e4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009c31d0(void*);
struct S_func_009c31d0 {
    virtual ~S_func_009c31d0();
    void* m_p;
};
S_func_009c31d0::~S_func_009c31d0()
{
    if (m_p)
        G1_func_009c31d0(m_p);
}
