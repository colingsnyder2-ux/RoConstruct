// from server: 100% by auto
// roc 2011-06 0043d310  unit: CMultiPlayerPane  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0043d310
//
// 0043d310  56                   push esi
// 0043d311  8bf1                 mov esi, ecx
// 0043d313  e82ed63c00           call 0x80a946
// 0043d318  c7064477a600         mov dword ptr [esi], 0xa67744
// 0043d31e  c7465400000000       mov dword ptr [esi + 0x54], 0
// 0043d325  8bc6                 mov eax, esi
// 0043d327  5e                   pop esi
// 0043d328  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
