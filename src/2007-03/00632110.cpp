// from server: 100% by auto
// roc 2007-03 00632110  unit: seg_00630000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00632110
//
// 00632110  56                   push esi
// 00632111  6a3c                 push 0x3c
// 00632113  8bf1                 mov esi, ecx
// 00632115  6a00                 push 0
// 00632117  56                   push esi
// 00632118  e8ffcefeff           call 0x61f01c
// 0063211d  83c40c               add esp, 0xc
// 00632120  8bc6                 mov eax, esi
// 00632122  5e                   pop esi
// 00632123  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ??0CLogFont@CXTPPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
