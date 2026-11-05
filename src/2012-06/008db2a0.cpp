// roc 2012-06 008db2a0  unit: RBX::SkateboardPlatform  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008db2a0
//
// 008db2a0  8b81e4030000         mov eax, dword ptr [ecx + 0x3e4]
// 008db2a6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008db2a0 {
    char pad0[996];
    int m_x;
    int f();
};
int S_func_008db2a0::f()
{
    return m_x;
}
