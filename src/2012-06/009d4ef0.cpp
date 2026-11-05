// roc 2012-06 009d4ef0  unit: CXTPPrintPageHeaderFooter  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d4ef0
//
// 009d4ef0  8b442408             mov eax, dword ptr [esp + 8]
// 009d4ef4  99                   cdq 
// 009d4ef5  f77c2404             idiv dword ptr [esp + 4]
// 009d4ef9  33c9                 xor ecx, ecx
// 009d4efb  85d2                 test edx, edx
// 009d4efd  0f95c1               setne cl
// 009d4f00  03c1                 add eax, ecx
// 009d4f02  c20800               ret 8
// copied from an identical function in another client (function ?sub_0067FDB0@ns_ROCX000059@@YGHHH@Z)

namespace ns_ROCX000059 {
int __stdcall sub_0067FDB0(int divisor, int value)
{
    int quotient = value / divisor;
    int remainder = value % divisor;
    return quotient + (remainder != 0 ? 1 : 0);
}
}
