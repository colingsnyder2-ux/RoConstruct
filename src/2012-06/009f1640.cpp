// roc 2012-06 009f1640  unit: CXTPPropertyGridItem  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f1640
//
// 009f1640  8b81fc000000         mov eax, dword ptr [ecx + 0xfc]
// 009f1646  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009f1640 {
    char pad0[252];
    int m_x;
    int f();
};
int S_func_009f1640::f()
{
    return m_x;
}
