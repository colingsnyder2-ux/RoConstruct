// from server: 100% by auto
// roc 2008-06 00432e30  unit: CMultiPlayerPane  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00432e30
//
// 00432e30  56                   push esi
// 00432e31  8bf1                 mov esi, ecx
// 00432e33  e858e02600           call 0x6a0e90
// 00432e38  c706dc1c8100         mov dword ptr [esi], 0x811cdc
// 00432e3e  c7465400000000       mov dword ptr [esi + 0x54], 0
// 00432e45  8bc6                 mov eax, esi
// 00432e47  5e                   pop esi
// 00432e48  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
