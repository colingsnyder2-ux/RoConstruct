// roc 2012-06 00983933  unit: boost::exception  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00983933
//
// 00983933  33c0                 xor eax, eax
// 00983935  40                   inc eax
// 00983936  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000048@ns_ROCX000048@@YAHXZ)

namespace ns_ROCX000048 {
int fn_ROCX000048()
{
    return 1;
}
}
