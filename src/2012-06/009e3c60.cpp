// roc 2012-06 009e3c60  unit: CXTPDockingPane  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e3c60
//
// 009e3c60  8b81e4000000         mov eax, dword ptr [ecx + 0xe4]
// 009e3c66  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009e3c60 {
    char pad0[228];
    int m_x;
    int f();
};
int S_func_009e3c60::f()
{
    return m_x;
}
