// roc 2012-06 00986250  unit: CPatchedControlComboBox  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00986250
//
// 00986250  c70118cec000         mov dword ptr [ecx], 0xc0ce18
// 00986256  8b4904               mov ecx, dword ptr [ecx + 4]
// 00986259  85c9                 test ecx, ecx
// 0098625b  7407                 je 0x986264
// 0098625d  51                   push ecx
// 0098625e  e857c1ffff           call 0x9823ba
// 00986263  59                   pop ecx
// 00986264  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00986250(void*);
struct S_func_00986250 {
    virtual ~S_func_00986250();
    void* m_p;
};
S_func_00986250::~S_func_00986250()
{
    if (m_p)
        G1_func_00986250(m_p);
}
