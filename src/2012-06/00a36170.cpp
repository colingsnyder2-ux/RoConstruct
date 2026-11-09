// roc 2012-06 00a36170  unit: CXTPDockingPaneWindowSelect  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a36170
//
// 00a36170  c701bc0ec200         mov dword ptr [ecx], 0xc20ebc
// 00a36176  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a36179  85c9                 test ecx, ecx
// 00a3617b  7407                 je 0xa36184
// 00a3617d  51                   push ecx
// 00a3617e  e837c2f4ff           call 0x9823ba
// 00a36183  59                   pop ecx
// 00a36184  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a36170(void*);
struct S_func_00a36170 {
    virtual ~S_func_00a36170();
    void* m_p;
};
S_func_00a36170::~S_func_00a36170()
{
    if (m_p)
        G1_func_00a36170(m_p);
}
