// from server: 100% by auto
// roc 2010-06 007fc7e0  unit: CXTPControlToolbars  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007fc7e0
//
// 007fc7e0  56                   push esi
// 007fc7e1  8bf1                 mov esi, ecx
// 007fc7e3  e8787b0400           call 0x844360
// 007fc7e8  c70674eea500         mov dword ptr [esi], 0xa5ee74
// 007fc7ee  c7462014eea500       mov dword ptr [esi + 0x20], 0xa5ee14
// 007fc7f5  8bc6                 mov eax, esi
// 007fc7f7  5e                   pop esi
// 007fc7f8  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlExt.cpp
