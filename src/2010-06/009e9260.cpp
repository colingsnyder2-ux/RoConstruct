// from server: 100% by auto
// roc 2010-06 009e9260  unit: seg_009e0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009e9260
//
// 009e9260  c70590c4c2005c86a800 mov dword ptr [0xc2c490], 0xa8865c
// 009e926a  b990c4c200           mov ecx, 0xc2c490
// 009e926f  ff2588af9e00         jmp dword ptr [0x9eaf88]
// library xtp-13.2.1-shared-mfc/Source\SyntaxEdit\XTPSyntaxEditLexClass.cpp (function ??__Fs_LVarIniter@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/SyntaxEdit/XTPSyntaxEditLexClass.cpp
