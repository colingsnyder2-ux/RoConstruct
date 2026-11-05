// from server: 100% by auto
// roc 2009-12 008cd720  unit: CXTPPropertyGridInplaceList  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008cd720
//
// 008cd720  56                   push esi
// 008cd721  8bf1                 mov esi, ecx
// 008cd723  e8206af2ff           call 0x7f4148
// 008cd728  c7065ca4a000         mov dword ptr [esi], 0xa0a45c
// 008cd72e  c7465400000000       mov dword ptr [esi + 0x54], 0
// 008cd735  8bc6                 mov eax, esi
// 008cd737  5e                   pop esi
// 008cd738  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
