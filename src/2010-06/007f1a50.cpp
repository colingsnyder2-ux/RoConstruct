// from server: 100% by auto
// roc 2010-06 007f1a50  unit: CXTPCustomizeSheet  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f1a50
//
// 007f1a50  56                   push esi
// 007f1a51  8bf1                 mov esi, ecx
// 007f1a53  e848cb0400           call 0x83e5a0
// 007f1a58  c70624cfa500         mov dword ptr [esi], 0xa5cf24
// 007f1a5e  c74620c4cea500       mov dword ptr [esi + 0x20], 0xa5cec4
// 007f1a65  8bc6                 mov eax, esi
// 007f1a67  5e                   pop esi
// 007f1a68  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlExt.cpp
