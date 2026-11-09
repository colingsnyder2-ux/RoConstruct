// roc 2012-06 00a361d0  unit: CXTPDockingPaneWindowSelect  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a361d0
//
// 00a361d0  c701d40ec200         mov dword ptr [ecx], 0xc20ed4
// 00a361d6  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a361d9  85c9                 test ecx, ecx
// 00a361db  7407                 je 0xa361e4
// 00a361dd  51                   push ecx
// 00a361de  e8d7c1f4ff           call 0x9823ba
// 00a361e3  59                   pop ecx
// 00a361e4  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a361d0(void*);
struct S_func_00a361d0 {
    virtual ~S_func_00a361d0();
    void* m_p;
};
S_func_00a361d0::~S_func_00a361d0()
{
    if (m_p)
        G1_func_00a361d0(m_p);
}
