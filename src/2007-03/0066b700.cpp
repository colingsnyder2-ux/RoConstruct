// from server: 100% by auto
// roc 2007-03 0066b700  unit: seg_00660000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066b700
//
// 0066b700  56                   push esi
// 0066b701  6a00                 push 0
// 0066b703  8bf1                 mov esi, ecx
// 0066b705  e86031fbff           call 0x61e86a
// 0066b70a  8bce                 mov ecx, esi
// 0066b70c  5e                   pop esi
// 0066b70d  e9a031fbff           jmp 0x61e8b2
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp (function ?OnInitialUpdate@CFormView@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewform.cpp
