// from server: 100% by auto
// roc 2011-06 0085cc50  unit: CXTPPrintingDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085cc50
//
// 0085cc50  56                   push esi
// 0085cc51  6a00                 push 0
// 0085cc53  8bf1                 mov esi, ecx
// 0085cc55  e8eefc1600           call 0x9cc948
// 0085cc5a  8bce                 mov ecx, esi
// 0085cc5c  5e                   pop esi
// 0085cc5d  e920ddfaff           jmp 0x80a982
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?OnInitialUpdate@CFormView@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
