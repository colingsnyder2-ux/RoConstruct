// from server: 100% by auto
// roc 2009-12 0045fdb0  unit: CRobloxView  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0045fdb0
//
// 0045fdb0  56                   push esi
// 0045fdb1  6a01                 push 1
// 0045fdb3  8bf1                 mov esi, ecx
// 0045fdb5  e8b6feffff           call 0x45fc70
// 0045fdba  8bce                 mov ecx, esi
// 0045fdbc  5e                   pop esi
// 0045fdbd  e9d2483900           jmp 0x7f4694
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditFindReplaceDlg.cpp (function ?OnEditChangeComboFind@CXTPSyntaxEditFindReplaceDlg@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditFindReplaceDlg.cpp
