// roc 2012-06 009f1630  unit: CXTPPropertyGridItem  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f1630
//
// 009f1630  8b81d8000000         mov eax, dword ptr [ecx + 0xd8]
// 009f1636  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009f1630 {
    char pad0[216];
    int m_x;
    int f();
};
int S_func_009f1630::f()
{
    return m_x;
}
