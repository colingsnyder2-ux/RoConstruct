// roc 2012-06 0071f930  unit: CPatchedControlComboBox  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071f930
//
// 0071f930  8b81b8010000         mov eax, dword ptr [ecx + 0x1b8]
// 0071f936  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0071f930 {
    char pad0[440];
    int m_x;
    int f();
};
int S_func_0071f930::f()
{
    return m_x;
}
