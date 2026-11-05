// roc 2012-06 00750720  unit: CXTSplitterWnd  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00750720
//
// 00750720  8b8108010000         mov eax, dword ptr [ecx + 0x108]
// 00750726  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00750720 {
    char pad0[264];
    int m_x;
    int f();
};
int S_func_00750720::f()
{
    return m_x;
}
