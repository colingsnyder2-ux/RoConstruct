// from server: 100% by auto
// roc 2009-06 00770390  unit: CXTPPrintingDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00770390
//
// 00770390  56                   push esi
// 00770391  6a00                 push 0
// 00770393  8bf1                 mov esi, ecx
// 00770395  e864c00d00           call 0x84c3fe
// 0077039a  8bce                 mov ecx, esi
// 0077039c  5e                   pop esi
// 0077039d  e9ba8ffaff           jmp 0x71935c
// library mfc-9.0/atlmfc\src\mfc\viewform.cpp (function ?OnInitialUpdate@CFormView@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewform.cpp
