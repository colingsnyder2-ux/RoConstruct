// roc 2009-06 0071a17c  unit: ActiveDocView  size: 4 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071a17c
//
// 0071a17c  33c0                 xor eax, eax
// 0071a17e  40                   inc eax
// 0071a17f  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000040@ns_ROCX000040@@YAHXZ)

namespace ns_ROCX000040 {
int fn_ROCX000040()
{
    return 1;
}
}
