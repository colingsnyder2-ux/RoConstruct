// roc 2012-06 006780c0  unit: RBX::XVGfxBinding::XV?$mf2::V?$bind_t::?$callable_slot  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006780c0
//
// 006780c0  c6819800000001       mov byte ptr [ecx + 0x98], 1
// 006780c7  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006780c0 {
    char pad0[152];
    char m_x;
    void f();
};
void S_func_006780c0::f()
{
    m_x = (char)1;
}
