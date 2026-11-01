// from server: 100% by auto
// roc 2009-12 008f1a30  unit: CXTPRibbonControlSystemPopupBarButton  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f1a30
//
// 008f1a30  56                   push esi
// 008f1a31  8bf1                 mov esi, ecx
// 008f1a33  e828e7f9ff           call 0x890160
// 008f1a38  c7067ceca000         mov dword ptr [esi], 0xa0ec7c
// 008f1a3e  c746201ceca000       mov dword ptr [esi + 0x20], 0xa0ec1c
// 008f1a45  8bc6                 mov eax, esi
// 008f1a47  5e                   pop esi
// 008f1a48  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
