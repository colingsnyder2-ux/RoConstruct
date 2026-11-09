// roc 2012-06 00690a50  unit: RBX::VModelInstance::?$BoundFuncDesc  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00690a50
//
// 00690a50  8b81ac000000         mov eax, dword ptr [ecx + 0xac]
// 00690a56  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00690a50 {
    char pad0[172];
    int m_x;
    int f();
};
int S_func_00690a50::f()
{
    return m_x;
}
