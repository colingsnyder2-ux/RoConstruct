// roc 2012-06 009e6e80  unit: CXTPStatusBarPane  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e6e80
//
// 009e6e80  8b4134               mov eax, dword ptr [ecx + 0x34]
// 009e6e83  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009e6e80 {
    char pad0[52];
    int m_x;
    int f();
};
int S_func_009e6e80::f()
{
    return m_x;
}
