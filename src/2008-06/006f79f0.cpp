// from server: 100% by auto
// roc 2008-06 006f79f0  unit: CXTPPrintingDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006f79f0
//
// 006f79f0  56                   push esi
// 006f79f1  6a00                 push 0
// 006f79f3  8bf1                 mov esi, ecx
// 006f79f5  e85a94faff           call 0x6a0e54
// 006f79fa  8bce                 mov ecx, esi
// 006f79fc  5e                   pop esi
// 006f79fd  e98894faff           jmp 0x6a0e8a
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?OnInitialUpdate@CFormView@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
