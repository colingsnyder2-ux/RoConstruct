// roc 2012-06 006d0930  unit: RBX::DataModel::PAVGenericJob::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 3 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006d0930
//
// 006d0930  8a01                 mov al, byte ptr [ecx]
// 006d0932  c3                   ret 
// auto-matched from its assembly shape

struct S_func_006d0930 {
    char m_x;
    char f();
};
char S_func_006d0930::f()
{
    return m_x;
}
