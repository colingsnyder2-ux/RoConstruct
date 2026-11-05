// roc 2012-06 009e9f70  unit: CInstanceRecord::CNameItem  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e9f70
//
// 009e9f70  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 009e9f73  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009e9f70 {
    char pad0[60];
    int m_x;
    int f();
};
int S_func_009e9f70::f()
{
    return m_x;
}
