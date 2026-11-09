// from server: 100% by auto
// roc 2010-06 00428b10  unit: CWrapperView  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00428b10
//
// 00428b10  e849f13700           call 0x7a7c5e
// 00428b15  8b4804               mov ecx, dword ptr [eax + 4]
// 00428b18  e9634a0200           jmp 0x44d580
// library xtp-13.2.1/Source\SyntaxEdit\XTPSyntaxEditDoc.cpp (function ?Restore@CWaitCursor@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SyntaxEdit/XTPSyntaxEditDoc.cpp
