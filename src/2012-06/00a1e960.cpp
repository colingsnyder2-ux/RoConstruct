// roc 2012-06 00a1e960  unit: CXTPRibbonBar  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1e960
//
// 00a1e960  8b818c020000         mov eax, dword ptr [ecx + 0x28c]
// 00a1e966  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a1e960 {
    char pad0[652];
    int m_x;
    int f();
};
int S_func_00a1e960::f()
{
    return m_x;
}
