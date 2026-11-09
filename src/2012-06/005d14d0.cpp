// roc 2012-06 005d14d0  unit: RBX::SceneUpdater  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005d14d0
//
// 005d14d0  8b81a4010000         mov eax, dword ptr [ecx + 0x1a4]
// 005d14d6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_005d14d0 {
    char pad0[420];
    int m_x;
    int f();
};
int S_func_005d14d0::f()
{
    return m_x;
}
