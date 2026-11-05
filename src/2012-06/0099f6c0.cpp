// roc 2012-06 0099f6c0  unit: CXTPToolBar  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0099f6c0
//
// 0099f6c0  8b81dc000000         mov eax, dword ptr [ecx + 0xdc]
// 0099f6c6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0099f6c0 {
    char pad0[220];
    int m_x;
    int f();
};
int S_func_0099f6c0::f()
{
    return m_x;
}
