// roc 2012-06 00977ac0  unit: RBX::VCEvent::?$sp_counted_impl_p  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00977ac0
//
// 00977ac0  dd8108010000         fld qword ptr [ecx + 0x108]
// 00977ac6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00977ac0 {
    char pad[264];
    double m_x;
    double f();
};
double S_func_00977ac0::f()
{
    return m_x;
}
