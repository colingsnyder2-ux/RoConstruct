// from server: 100% by auto
// roc 2008-06 0077a450  unit: CXTPPropertyGridInplaceList  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0077a450
//
// 0077a450  56                   push esi
// 0077a451  8bf1                 mov esi, ecx
// 0077a453  e8386af2ff           call 0x6a0e90
// 0077a458  c706c48f8600         mov dword ptr [esi], 0x868fc4
// 0077a45e  c7465400000000       mov dword ptr [esi + 0x54], 0
// 0077a465  8bc6                 mov eax, esi
// 0077a467  5e                   pop esi
// 0077a468  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
