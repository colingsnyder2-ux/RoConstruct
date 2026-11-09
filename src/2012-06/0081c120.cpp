// roc 2012-06 0081c120  unit: RBX::Reflection::UTuple::$$A6A?AV?$shared_ptr::V?$function::?$sp_counted_impl_p  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0081c120
//
// 0081c120  8d81e0000000         lea eax, [ecx + 0xe0]
// 0081c126  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0081c120 {
    char pad0[224];
    int m_x;
    int* f();
};
int* S_func_0081c120::f()
{
    return &m_x;
}
