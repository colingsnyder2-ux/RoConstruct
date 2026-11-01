// from server: 100% by auto
// roc 2009-06 00458490  unit: CRobloxView  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00458490
//
// 00458490  56                   push esi
// 00458491  6a01                 push 1
// 00458493  8bf1                 mov esi, ecx
// 00458495  e8b6feffff           call 0x458350
// 0045849a  8bce                 mov ecx, esi
// 0045849c  5e                   pop esi
// 0045849d  e9be132c00           jmp 0x719860
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditFindReplaceDlg.cpp (function ?OnEditChangeComboFind@CXTPSyntaxEditFindReplaceDlg@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditFindReplaceDlg.cpp
