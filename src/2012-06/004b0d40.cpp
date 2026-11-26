// from server: 100% by Xemicl
// roc 2012-06 004b0d40  unit: CWebToolbox  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b0d40
//
// 004b0d40  8b89f8000000         mov ecx, dword ptr [ecx + 0xf8]
// 004b0d46  85c9                 test ecx, ecx
// 004b0d48  7405                 je 0x4b0d4f
// 004b0d4a  e855174d00           call 0x9824a4
// 004b0d4f  b803000000           mov eax, 3
// 004b0d54  c20c00               ret 0xc
// copied from an identical function in another client (function ?fn_ROCX000028_0046a6f0@CWebToolbox@ns_ROCX000028@@QAEHHHH@Z)

namespace ns_ROCX000028 {
struct CWebToolbox
{
    char pad[0xf8];
    void* field_f8;
    int fn_ROCX000028_0046a6f0(int, int, int);
    void sub_006a0a28();
};

int CWebToolbox::fn_ROCX000028_0046a6f0(int, int, int)
{
    if (field_f8 != 0) {
        ((CWebToolbox*)field_f8)->sub_006a0a28();
    }
    return 3;
}
}