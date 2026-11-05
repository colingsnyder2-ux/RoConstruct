// from server: 100% by auto
// roc 2010-06 007f1a90  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f1a90
//
// 007f1a90  56                   push esi
// 007f1a91  8bf1                 mov esi, ecx
// 007f1a93  e8c8280500           call 0x844360
// 007f1a98  c706ecd0a500         mov dword ptr [esi], 0xa5d0ec
// 007f1a9e  c746208cd0a500       mov dword ptr [esi + 0x20], 0xa5d08c
// 007f1aa5  8bc6                 mov eax, esi
// 007f1aa7  5e                   pop esi
// 007f1aa8  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlExt.cpp
