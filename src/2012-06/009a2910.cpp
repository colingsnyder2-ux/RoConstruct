// roc 2012-06 009a2910  unit: MyXTPCommandBars  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009a2910
//
// 009a2910  c701b4f3c000         mov dword ptr [ecx], 0xc0f3b4
// 009a2916  8b4904               mov ecx, dword ptr [ecx + 4]
// 009a2919  85c9                 test ecx, ecx
// 009a291b  7407                 je 0x9a2924
// 009a291d  51                   push ecx
// 009a291e  e897fafdff           call 0x9823ba
// 009a2923  59                   pop ecx
// 009a2924  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_009a2910(void*);
struct S_func_009a2910 {
    virtual ~S_func_009a2910();
    void* m_p;
};
S_func_009a2910::~S_func_009a2910()
{
    if (m_p)
        G1_func_009a2910(m_p);
}
