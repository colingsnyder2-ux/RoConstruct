// from server: 100% by auto
// roc 2009-12 004286c0  unit: CWrapperView  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004286c0
//
// 004286c0  e859b43c00           call 0x7f3b1e
// 004286c5  8b4804               mov ecx, dword ptr [eax + 4]
// 004286c8  e983380200           jmp 0x44bf50
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditDoc.cpp (function ?Restore@CWaitCursor@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditDoc.cpp
