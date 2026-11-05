// roc 2012-06 009a28b0  unit: MyXTPCommandBars  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009a28b0
//
// 009a28b0  c7019cf3c000         mov dword ptr [ecx], 0xc0f39c
// 009a28b6  8b4904               mov ecx, dword ptr [ecx + 4]
// 009a28b9  85c9                 test ecx, ecx
// 009a28bb  7407                 je 0x9a28c4
// 009a28bd  51                   push ecx
// 009a28be  e8f7fafdff           call 0x9823ba
// 009a28c3  59                   pop ecx
// 009a28c4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009a28b0(void*);
struct S_func_009a28b0 {
    virtual ~S_func_009a28b0();
    void* m_p;
};
S_func_009a28b0::~S_func_009a28b0()
{
    if (m_p)
        G1_func_009a28b0(m_p);
}
