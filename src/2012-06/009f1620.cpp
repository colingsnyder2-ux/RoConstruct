// roc 2012-06 009f1620  unit: CXTPPropertyGridItem  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f1620
//
// 009f1620  8b81d4000000         mov eax, dword ptr [ecx + 0xd4]
// 009f1626  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009f1620 {
    char pad0[212];
    int m_x;
    int f();
};
int S_func_009f1620::f()
{
    return m_x;
}
