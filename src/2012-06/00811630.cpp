// roc 2012-06 00811630  unit: RBX::JointInstance  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00811630
//
// 00811630  8b81a8000000         mov eax, dword ptr [ecx + 0xa8]
// 00811636  83c034               add eax, 0x34
// 00811639  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00811630 {
    char pad0[168];
    int m_x;
    int f();
};
int S_func_00811630::f()
{
    return m_x + 0x34;
}
