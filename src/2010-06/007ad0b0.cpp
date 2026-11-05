// from server: 100% by auto
// roc 2010-06 007ad0b0  unit: CRobloxControlColorSelector  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ad0b0
//
// 007ad0b0  56                   push esi
// 007ad0b1  6a3c                 push 0x3c
// 007ad0b3  8bf1                 mov esi, ecx
// 007ad0b5  6a00                 push 0
// 007ad0b7  56                   push esi
// 007ad0b8  e827bbffff           call 0x7a8be4
// 007ad0bd  83c40c               add esp, 0xc
// 007ad0c0  8bc6                 mov eax, esi
// 007ad0c2  5e                   pop esi
// 007ad0c3  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPPaintManager.cpp (function ??0CLogFont@CXTPPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPaintManager.cpp
