// roc 2012-06 008d67f0  unit: RBX::Handles  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008d67f0
//
// 008d67f0  8b818c010000         mov eax, dword ptr [ecx + 0x18c]
// 008d67f6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008d67f0 {
    char pad0[396];
    int m_x;
    int f();
};
int S_func_008d67f0::f()
{
    return m_x;
}
