// roc 2012-06 00776ee0  unit: RBX::VBasicPartInstance::?$ActionStation  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00776ee0
//
// 00776ee0  8b81c0020000         mov eax, dword ptr [ecx + 0x2c0]
// 00776ee6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00776ee0 {
    char pad0[704];
    int m_x;
    int f();
};
int S_func_00776ee0::f()
{
    return m_x;
}
