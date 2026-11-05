// from server: 100% by EspClaude
// roc 2009-06 00408640  unit: VCApp::?$CComObject  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00408640
//
// 00408640  8b442404             mov eax, dword ptr [esp + 4]
// 00408644  85c0                 test eax, eax
// 00408646  7509                 jne 0x408651
// 00408648  89442404             mov dword ptr [esp + 4], eax
// 0040864c  e9eff8ffff           jmp 0x407f40
// 00408651  89442404             mov dword ptr [esp + 4], eax
// 00408655  e9a6fcffff           jmp 0x408300
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
