// from server: 100% by auto
// roc 2010-06 004653c0  unit: CRobloxView  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004653c0
//
// 004653c0  56                   push esi
// 004653c1  6a01                 push 1
// 004653c3  8bf1                 mov esi, ecx
// 004653c5  e8b6feffff           call 0x465280
// 004653ca  8bce                 mov ecx, esi
// 004653cc  5e                   pop esi
// 004653cd  e902343400           jmp 0x7a87d4
// library xtp-13.2.1/Source\SyntaxEdit\XTPSyntaxEditFindReplaceDlg.cpp (function ?OnEditChangeComboFind@CXTPSyntaxEditFindReplaceDlg@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SyntaxEdit/XTPSyntaxEditFindReplaceDlg.cpp
