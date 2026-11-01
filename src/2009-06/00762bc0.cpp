// from server: 100% by auto
// roc 2009-06 00762bc0  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00762bc0
//
// 00762bc0  56                   push esi
// 00762bc1  8bf1                 mov esi, ecx
// 00762bc3  e8d8bd0500           call 0x7be9a0
// 00762bc8  c70684898f00         mov dword ptr [esi], 0x8f8984
// 00762bce  c7462024898f00       mov dword ptr [esi + 0x20], 0x8f8924
// 00762bd5  8bc6                 mov eax, esi
// 00762bd7  5e                   pop esi
// 00762bd8  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
