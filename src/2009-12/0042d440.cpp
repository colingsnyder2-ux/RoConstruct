// from server: 100% by auto
// roc 2009-12 0042d440  unit: CMultiPlayerPane  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0042d440
//
// 0042d440  56                   push esi
// 0042d441  8bf1                 mov esi, ecx
// 0042d443  e8006d3c00           call 0x7f4148
// 0042d448  c706e44f9a00         mov dword ptr [esi], 0x9a4fe4
// 0042d44e  c7465400000000       mov dword ptr [esi + 0x54], 0
// 0042d455  8bc6                 mov eax, esi
// 0042d457  5e                   pop esi
// 0042d458  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
