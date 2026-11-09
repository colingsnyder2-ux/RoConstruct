// from server: 100% by auto
// roc 2007-08 0067fec0  unit: CXTPPrintingDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0067fec0
//
// 0067fec0  56                   push esi
// 0067fec1  6a00                 push 0
// 0067fec3  8bf1                 mov esi, ecx
// 0067fec5  e80c05fbff           call 0x6303d6
// 0067feca  8bce                 mov ecx, esi
// 0067fecc  5e                   pop esi
// 0067fecd  e94c05fbff           jmp 0x63041e
// library mfc-8.0/atlmfc\src\mfc\viewform.cpp (function ?OnInitialUpdate@CFormView@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewform.cpp
