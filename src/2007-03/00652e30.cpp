// from server: 100% by auto
// roc 2007-03 00652e30  unit: seg_00650000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00652e30
//
// 00652e30  c7015c767c00         mov dword ptr [ecx], 0x7c765c
// 00652e36  83c118               add ecx, 0x18
// 00652e39  e962feffff           jmp 0x652ca0
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditLineMarksManager.cpp (function ??1XTP_EDIT_LMPARAM@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditLineMarksManager.cpp
