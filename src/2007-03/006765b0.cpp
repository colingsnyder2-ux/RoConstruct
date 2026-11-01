// from server: 100% by auto
// roc 2007-03 006765b0  unit: seg_00670000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006765b0
//
// 006765b0  56                   push esi
// 006765b1  8bf1                 mov esi, ecx
// 006765b3  e898e80300           call 0x6b4e50
// 006765b8  c70694c27c00         mov dword ptr [esi], 0x7cc294
// 006765be  c7462034c27c00       mov dword ptr [esi + 0x20], 0x7cc234
// 006765c5  8bc6                 mov eax, esi
// 006765c7  5e                   pop esi
// 006765c8  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
