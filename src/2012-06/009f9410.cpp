// roc 2012-06 009f9410  unit: CXTPDockingPaneAutoHidePanel  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f9410
//
// 009f9410  8b4114               mov eax, dword ptr [ecx + 0x14]
// 009f9413  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009f9410 {
    char pad0[20];
    int m_x;
    int f();
};
int S_func_009f9410::f()
{
    return m_x;
}
