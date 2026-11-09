// roc 2012-06 00986210  unit: CPatchedControlComboBox  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00986210
//
// 00986210  c70100cec000         mov dword ptr [ecx], 0xc0ce00
// 00986216  8b4904               mov ecx, dword ptr [ecx + 4]
// 00986219  85c9                 test ecx, ecx
// 0098621b  7407                 je 0x986224
// 0098621d  51                   push ecx
// 0098621e  e897c1ffff           call 0x9823ba
// 00986223  59                   pop ecx
// 00986224  c3                   ret 
// auto-matched from its assembly shape

extern "C" void __cdecl G1_func_00986210(void*);
struct S_func_00986210 {
    virtual ~S_func_00986210();
    void* m_p;
};
S_func_00986210::~S_func_00986210()
{
    if (m_p)
        G1_func_00986210(m_p);
}
