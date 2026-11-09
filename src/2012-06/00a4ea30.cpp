// roc 2012-06 00a4ea30  unit: CXTPTabPaintManager  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4ea30
//
// 00a4ea30  c7011c34c200         mov dword ptr [ecx], 0xc2341c
// 00a4ea36  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a4ea39  85c9                 test ecx, ecx
// 00a4ea3b  7407                 je 0xa4ea44
// 00a4ea3d  51                   push ecx
// 00a4ea3e  e87739f3ff           call 0x9823ba
// 00a4ea43  59                   pop ecx
// 00a4ea44  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00a4ea30(void*);
struct S_func_00a4ea30 {
    virtual ~S_func_00a4ea30();
    void* m_p;
};
S_func_00a4ea30::~S_func_00a4ea30()
{
    if (m_p)
        G1_func_00a4ea30(m_p);
}
