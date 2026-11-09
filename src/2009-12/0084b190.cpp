// from server: 100% by auto
// roc 2009-12 0084b190  unit: CXTPPrintingDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084b190
//
// 0084b190  56                   push esi
// 0084b191  6a00                 push 0
// 0084b193  8bf1                 mov esi, ecx
// 0084b195  e8d0b70d00           call 0x92696a
// 0084b19a  8bce                 mov ecx, esi
// 0084b19c  5e                   pop esi
// 0084b19d  e9e28ffaff           jmp 0x7f4184
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp (function ?OnInitialUpdate@CFormView@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewform.cpp
