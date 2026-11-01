// from server: 100% by auto
// roc 2007-03 00433b10  unit: seg_00430000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00433b10
//
// 00433b10  56                   push esi
// 00433b11  8bf1                 mov esi, ecx
// 00433b13  e856af1e00           call 0x61ea6e
// 00433b18  c706b4ab7800         mov dword ptr [esi], 0x78abb4
// 00433b1e  c7465400000000       mov dword ptr [esi + 0x54], 0
// 00433b25  8bc6                 mov eax, esi
// 00433b27  5e                   pop esi
// 00433b28  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
