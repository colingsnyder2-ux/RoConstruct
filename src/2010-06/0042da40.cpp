// from server: 100% by auto
// roc 2010-06 0042da40  unit: CMultiPlayerPane  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042da40
//
// 0042da40  56                   push esi
// 0042da41  8bf1                 mov esi, ecx
// 0042da43  e840a83700           call 0x7a8288
// 0042da48  c7067c5da000         mov dword ptr [esi], 0xa05d7c
// 0042da4e  c7465400000000       mov dword ptr [esi + 0x54], 0
// 0042da55  8bc6                 mov eax, esi
// 0042da57  5e                   pop esi
// 0042da58  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
