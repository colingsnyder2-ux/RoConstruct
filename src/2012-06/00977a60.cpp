// roc 2012-06 00977a60  unit: RBX::VCEvent::?$sp_counted_impl_p  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00977a60
//
// 00977a60  c7819c00000002000000 mov dword ptr [ecx + 0x9c], 2
// 00977a6a  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00977a60 {
    char pad0[156];
    int m_x;
    void f();
};
void S_func_00977a60::f()
{
    m_x = (int)2;
}
