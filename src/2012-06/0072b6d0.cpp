// roc 2012-06 0072b6d0  unit: RBX::Workspace  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0072b6d0
//
// 0072b6d0  8b81bc000000         mov eax, dword ptr [ecx + 0xbc]
// 0072b6d6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0072b6d0 {
    char pad0[188];
    int m_x;
    int f();
};
int S_func_0072b6d0::f()
{
    return m_x;
}
