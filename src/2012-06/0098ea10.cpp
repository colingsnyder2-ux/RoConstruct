// roc 2012-06 0098ea10  unit: CXTPToolBar::CControlButtonExpand  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0098ea10
//
// 0098ea10  8b8174010000         mov eax, dword ptr [ecx + 0x174]
// 0098ea16  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0098ea10 {
    char pad0[372];
    int m_x;
    int f();
};
int S_func_0098ea10::f()
{
    return m_x;
}
