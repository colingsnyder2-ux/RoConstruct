// from server: 100% by auto
// roc 2009-12 0083d950  unit: CXTPCustomizeSheet  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083d950
//
// 0083d950  56                   push esi
// 0083d951  8bf1                 mov esi, ecx
// 0083d953  e8c8d60400           call 0x88b020
// 0083d958  c706648c9f00         mov dword ptr [esi], 0x9f8c64
// 0083d95e  c74620048c9f00       mov dword ptr [esi + 0x20], 0x9f8c04
// 0083d965  8bc6                 mov eax, esi
// 0083d967  5e                   pop esi
// 0083d968  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
