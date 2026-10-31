// from server: 100% by EspClaude
// roc 2009-06 00419120  unit: CRBXHTMLControlSite  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00419120
//
// 00419120  8b442404             mov eax, dword ptr [esp + 4]
// 00419124  50                   push eax
// 00419125  e8c6a91c00           call 0x5e3af0
// 0041912a  0fb6c0               movzx eax, al
// 0041912d  83c404               add esp, 4
// 00419130  f7d8                 neg eax
// 00419132  1bc0                 sbb eax, eax
// 00419134  25fbbfff7f           and eax, 0x7fffbffb
// 00419139  0505400080           add eax, 0x80004005
// 0041913e  c3                   ret 
// copied from an identical function in another client (function ?function@ns_ROCX000035@@YAJPAX@Z)

namespace ns_ROCX000035 {
extern bool __cdecl helper(void* value);

long __cdecl function(void* value)
{
    return helper(value) ? 0L : (long)0x80004005UL;
}
}
