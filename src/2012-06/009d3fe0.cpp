// roc 2012-06 009d3fe0  unit: CXTPControlSelector  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d3fe0
//
// 009d3fe0  33c0                 xor eax, eax
// 009d3fe2  3905d09be500         cmp dword ptr [0xe59bd0], eax
// 009d3fe8  0f95c0               setne al
// 009d3feb  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000047@ns_ROCX000047@@YAHXZ)

namespace ns_ROCX000047 {
extern int g_008c8f54;

int fn_ROCX000047()
{
    return g_008c8f54 != 0;
}
}
