// roc 2012-06 00a16160  unit: CXTPHookManagerHookAble  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a16160
//
// 00a16160  c701d8d4c100         mov dword ptr [ecx], 0xc1d4d8
// 00a16166  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a16169  85c9                 test ecx, ecx
// 00a1616b  7407                 je 0xa16174
// 00a1616d  51                   push ecx
// 00a1616e  e847c2f6ff           call 0x9823ba
// 00a16173  59                   pop ecx
// 00a16174  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a16160(void*);
struct S_func_00a16160 {
    virtual ~S_func_00a16160();
    void* m_p;
};
S_func_00a16160::~S_func_00a16160()
{
    if (m_p)
        G1_func_00a16160(m_p);
}
