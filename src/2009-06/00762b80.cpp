// from server: 100% by auto
// roc 2009-06 00762b80  unit: CXTPCustomizeSheet  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00762b80
//
// 00762b80  56                   push esi
// 00762b81  8bf1                 mov esi, ecx
// 00762b83  e8d8d50400           call 0x7b0160
// 00762b88  c706bc878f00         mov dword ptr [esi], 0x8f87bc
// 00762b8e  c746205c878f00       mov dword ptr [esi + 0x20], 0x8f875c
// 00762b95  8bc6                 mov eax, esi
// 00762b97  5e                   pop esi
// 00762b98  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
