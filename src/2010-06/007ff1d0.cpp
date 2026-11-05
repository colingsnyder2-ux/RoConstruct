// from server: 100% by auto
// roc 2010-06 007ff1d0  unit: CXTPPrintingDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ff1d0
//
// 007ff1d0  56                   push esi
// 007ff1d1  6a00                 push 0
// 007ff1d3  8bf1                 mov esi, ecx
// 007ff1d5  e8d2e01700           call 0x97d2ac
// 007ff1da  8bce                 mov ecx, esi
// 007ff1dc  5e                   pop esi
// 007ff1dd  e9e290faff           jmp 0x7a82c4
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?OnInitialUpdate@CFormView@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
