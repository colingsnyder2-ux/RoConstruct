// roc 2012-06 009e18f0  unit: CXTPPropertyGrid  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e18f0
//
// 009e18f0  8b8184010000         mov eax, dword ptr [ecx + 0x184]
// 009e18f6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009e18f0 {
    char pad0[388];
    int m_x;
    int f();
};
int S_func_009e18f0::f()
{
    return m_x;
}
