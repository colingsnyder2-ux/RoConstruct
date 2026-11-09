// roc 2012-06 00999e80  unit: CXTPImageManagerResource::CBitmapDC  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00999e80
//
// 00999e80  c70150e7c000         mov dword ptr [ecx], 0xc0e750
// 00999e86  8b4904               mov ecx, dword ptr [ecx + 4]
// 00999e89  85c9                 test ecx, ecx
// 00999e8b  7407                 je 0x999e94
// 00999e8d  51                   push ecx
// 00999e8e  e82785feff           call 0x9823ba
// 00999e93  59                   pop ecx
// 00999e94  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00999e80(void*);
struct S_func_00999e80 {
    virtual ~S_func_00999e80();
    void* m_p;
};
S_func_00999e80::~S_func_00999e80()
{
    if (m_p)
        G1_func_00999e80(m_p);
}
