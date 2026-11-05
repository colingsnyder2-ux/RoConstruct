// from server: 100% by Yeetserama
// roc 2007-08 0041bd60  unit: VDHTMLWindow::?$SignalDesc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041bd60
//
// 0041bd60  8b442404             mov eax, dword ptr [esp + 4]
// 0041bd64  50                   push eax
// 0041bd65  e866501300           call 0x550dd0
// 0041bd6a  83c404               add esp, 4
// 0041bd6d  f6d8                 neg al
// 0041bd6f  1bc0                 sbb eax, eax
// 0041bd71  25fbbfff7f           and eax, 0x7fffbffb
// 0041bd76  0505400080           add eax, 0x80004005
// 0041bd7b  c3                   ret 
// copied from an identical function in another client (function ?function@ns_ROCX00000b@@YAJPAX@Z)

namespace ns_ROCX00000b {
// from server: 100% by king_originala
extern bool __cdecl helper(void* value);

long __cdecl function(void* value)
{
    return helper(value) ? 0L : (long)0x80004005UL;
}
}
