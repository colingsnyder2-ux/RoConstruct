// from server: 100% by Xemicl
// roc 2012-06 00408fa0  unit: VCApp::?$CComAggObject  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00408fa0
//
// 00408fa0  8b442404             mov eax, dword ptr [esp + 4]
// 00408fa4  85c0                 test eax, eax
// 00408fa6  7509                 jne 0x408fb1
// 00408fa8  89442404             mov dword ptr [esp + 4], eax
// 00408fac  e96ff5ffff           jmp 0x408520
// 00408fb1  89442404             mov dword ptr [esp + 4], eax
// 00408fb5  e9f6feffff           jmp 0x408eb0
// copied from an identical function in another client (function ?dispatch@ns_ROCX00004f@@YAHH@Z)

namespace ns_ROCX00004f {
extern int __cdecl zero_case(int);
extern int __cdecl nonzero_case(int);

int __cdecl dispatch(int value)
{
    if (value == 0)
        return zero_case(value);
    return nonzero_case(value);
}
}