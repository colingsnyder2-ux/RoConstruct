// from server: 100% by auto
// roc 2007-03 006dcc20  unit: seg_006d0000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006dcc20
//
// 006dcc20  56                   push esi
// 006dcc21  8bf1                 mov esi, ecx
// 006dcc23  e8461ef4ff           call 0x61ea6e
// 006dcc28  c7061c817d00         mov dword ptr [esi], 0x7d811c
// 006dcc2e  c7465400000000       mov dword ptr [esi + 0x54], 0
// 006dcc35  8bc6                 mov eax, esi
// 006dcc37  5e                   pop esi
// 006dcc38  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
