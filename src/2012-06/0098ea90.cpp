// roc 2012-06 0098ea90  unit: CXTPPopupBar  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0098ea90
//
// 0098ea90  8b81d4010000         mov eax, dword ptr [ecx + 0x1d4]
// 0098ea96  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0098ea90 {
    char pad0[468];
    int m_x;
    int f();
};
int S_func_0098ea90::f()
{
    return m_x;
}
