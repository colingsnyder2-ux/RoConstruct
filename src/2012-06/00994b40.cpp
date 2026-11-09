// roc 2012-06 00994b40  unit: CXTPControlComboBoxPopupBar  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00994b40
//
// 00994b40  c701bce3c000         mov dword ptr [ecx], 0xc0e3bc
// 00994b46  8b4904               mov ecx, dword ptr [ecx + 4]
// 00994b49  85c9                 test ecx, ecx
// 00994b4b  7407                 je 0x994b54
// 00994b4d  51                   push ecx
// 00994b4e  e867d8feff           call 0x9823ba
// 00994b53  59                   pop ecx
// 00994b54  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00994b40(void*);
struct S_func_00994b40 {
    virtual ~S_func_00994b40();
    void* m_p;
};
S_func_00994b40::~S_func_00994b40()
{
    if (m_p)
        G1_func_00994b40(m_p);
}
