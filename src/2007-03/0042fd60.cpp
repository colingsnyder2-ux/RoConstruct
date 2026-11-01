// from server: 100% by auto
// roc 2007-03 0042fd60  unit: seg_00420000  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0042fd60
//
// 0042fd60  e82be61e00           call 0x61e390
// 0042fd65  8b4804               mov ecx, dword ptr [eax + 4]
// 0042fd68  e9e3830100           jmp 0x448150
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditDoc.cpp (function ?Restore@CWaitCursor@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditDoc.cpp
