// from server: 100% by auto
// roc 2009-12 007fd5b0  unit: CXTPControlComboBoxAutoCompleteWnd  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fd5b0
//
// 007fd5b0  56                   push esi
// 007fd5b1  6a3c                 push 0x3c
// 007fd5b3  8bf1                 mov esi, ecx
// 007fd5b5  6a00                 push 0
// 007fd5b7  56                   push esi
// 007fd5b8  e8e774ffff           call 0x7f4aa4
// 007fd5bd  83c40c               add esp, 0xc
// 007fd5c0  8bc6                 mov eax, esi
// 007fd5c2  5e                   pop esi
// 007fd5c3  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ??0CLogFont@CXTPPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
