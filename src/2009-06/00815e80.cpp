// from server: 100% by auto
// roc 2009-06 00815e80  unit: CXTPRibbonControlSystemPopupBarButton  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00815e80
//
// 00815e80  56                   push esi
// 00815e81  8bf1                 mov esi, ecx
// 00815e83  e8188bfaff           call 0x7be9a0
// 00815e88  c70614df9000         mov dword ptr [esi], 0x90df14
// 00815e8e  c74620b4de9000       mov dword ptr [esi + 0x20], 0x90deb4
// 00815e95  8bc6                 mov eax, esi
// 00815e97  5e                   pop esi
// 00815e98  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
