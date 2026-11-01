// from server: 100% by auto
// roc 2009-06 00427a80  unit: CWrapperView  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00427a80
//
// 00427a80  e871122f00           call 0x718cf6
// 00427a85  8b4804               mov ecx, dword ptr [eax + 4]
// 00427a88  e9b3e20100           jmp 0x445d40
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditDoc.cpp (function ?Restore@CWaitCursor@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditDoc.cpp
