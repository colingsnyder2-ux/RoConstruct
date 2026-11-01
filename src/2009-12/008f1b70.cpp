// from server: 100% by auto
// roc 2009-12 008f1b70  unit: CXTPRibbonControlSystemRecentFileList  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f1b70
//
// 008f1b70  56                   push esi
// 008f1b71  8bf1                 mov esi, ecx
// 008f1b73  e858ffffff           call 0x8f1ad0
// 008f1b78  c7068cf1a000         mov dword ptr [esi], 0xa0f18c
// 008f1b7e  c746202cf1a000       mov dword ptr [esi + 0x20], 0xa0f12c
// 008f1b85  8bc6                 mov eax, esi
// 008f1b87  5e                   pop esi
// 008f1b88  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
