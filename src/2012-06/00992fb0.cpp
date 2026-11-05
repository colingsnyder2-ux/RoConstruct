// roc 2012-06 00992fb0  unit: CXTPCommandBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00992fb0
//
// 00992fb0  83792000             cmp dword ptr [ecx + 0x20], 0
// 00992fb4  7412                 je 0x992fc8
// 00992fb6  e81d661000           call 0xa995d8
// 00992fbb  a900204000           test eax, 0x402000
// 00992fc0  7406                 je 0x992fc8
// 00992fc2  b801000000           mov eax, 1
// 00992fc7  c3                   ret 
// 00992fc8  33c0                 xor eax, eax
// 00992fca  c3                   ret 
// copied from an identical function in another client (function ?CanFocus@CXTPReportControl@ns_ROCX000002@@QAEHXZ)

namespace ns_ROCX000002 {
struct CXTPReportControl
{
    char pad[0x20];
    void* field_20;
    int CanFocus();
};

extern "C" int __stdcall sub_00738322();

int CXTPReportControl::CanFocus()
{
    if (field_20 != 0)
    {
        if ((sub_00738322() & 0x402000) != 0)
            return 1;
    }
    return 0;
}
}
