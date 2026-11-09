// roc 2012-06 00a3d430  unit: CXTPDockingPaneTabbedContainer  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a3d430
//
// 00a3d430  8b4160               mov eax, dword ptr [ecx + 0x60]
// 00a3d433  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a3d430 {
    char pad0[96];
    int m_x;
    int f();
};
int S_func_00a3d430::f()
{
    return m_x;
}
