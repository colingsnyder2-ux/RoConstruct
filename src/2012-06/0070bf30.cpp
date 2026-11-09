// roc 2012-06 0070bf30  unit: RBX::Lua::WeakFunctionRef  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0070bf30
//
// 0070bf30  8b81c4010000         mov eax, dword ptr [ecx + 0x1c4]
// 0070bf36  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0070bf30 {
    char pad0[452];
    int m_x;
    int f();
};
int S_func_0070bf30::f()
{
    return m_x;
}
