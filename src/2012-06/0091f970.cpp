// roc 2012-06 0091f970  unit: RBX::PointToPointBreakConnector  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0091f970
//
// 0091f970  8a4118               mov al, byte ptr [ecx + 0x18]
// 0091f973  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0091f970 {
    char pad0[24];
    char m_x;
    char f();
};
char S_func_0091f970::f()
{
    return m_x;
}
