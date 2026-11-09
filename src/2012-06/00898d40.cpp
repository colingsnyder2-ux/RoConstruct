// roc 2012-06 00898d40  unit: RBX::AdvArrowToolBase  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00898d40
//
// 00898d40  8b819c000000         mov eax, dword ptr [ecx + 0x9c]
// 00898d46  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00898d40 {
    char pad0[156];
    int m_x;
    int f();
};
int S_func_00898d40::f()
{
    return m_x;
}
