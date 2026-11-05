// roc 2012-06 00898d50  unit: RBX::AdvArrowToolBase  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00898d50
//
// 00898d50  8b81a0000000         mov eax, dword ptr [ecx + 0xa0]
// 00898d56  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00898d50 {
    char pad0[160];
    int m_x;
    int f();
};
int S_func_00898d50::f()
{
    return m_x;
}
