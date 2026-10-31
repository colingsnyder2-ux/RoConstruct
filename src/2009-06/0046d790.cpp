// from server: 100% by EspClaude
// roc 2009-06 0046d790  unit: CWebToolbox  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046d790
//
// 0046d790  8b89f8000000         mov ecx, dword ptr [ecx + 0xf8]
// 0046d796  85c9                 test ecx, ecx
// 0046d798  7405                 je 0x46d79f
// 0046d79a  e83bb62a00           call 0x718dda
// 0046d79f  b803000000           mov eax, 3
// 0046d7a4  c20c00               ret 0xc
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
