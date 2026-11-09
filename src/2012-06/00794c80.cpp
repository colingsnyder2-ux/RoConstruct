// roc 2012-06 00794c80  unit: RBX::KernelJoint  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00794c80
//
// 00794c80  8b819c010000         mov eax, dword ptr [ecx + 0x19c]
// 00794c86  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00794c80 {
    char pad0[412];
    int m_x;
    int f();
};
int S_func_00794c80::f()
{
    return m_x;
}
