// roc 2011-06 0080b7f3  unit: boost::exception  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0080b7f3
//
// 0080b7f3  33c0                 xor eax, eax
// 0080b7f5  40                   inc eax
// 0080b7f6  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000040@ns_ROCX000040@@YAHXZ)

namespace ns_ROCX000040 {
int fn_ROCX000040()
{
    return 1;
}
}
