// roc 2012-06 00898d30  unit: RBX::AdvArrowToolBase  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00898d30
//
// 00898d30  8b8198000000         mov eax, dword ptr [ecx + 0x98]
// 00898d36  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00898d30 {
    char pad0[152];
    int m_x;
    int f();
};
int S_func_00898d30::f()
{
    return m_x;
}
