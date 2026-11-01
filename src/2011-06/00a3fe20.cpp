// from server: 100% by auto
// roc 2011-06 00a3fe20  unit: seg_00a30000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00a3fe20
//
// 00a3fe20  c70510f1d100cc52af00 mov dword ptr [0xd1f110], 0xaf52cc
// 00a3fe2a  b910f1d100           mov ecx, 0xd1f110
// 00a3fe2f  ff255410a400         jmp dword ptr [0xa41054]
// library xtp-15.2.1-shared-mfc/Source\SyntaxEdit\XTPSyntaxEditLexClass.cpp (function ??__Fs_LVarIniter@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/SyntaxEdit/XTPSyntaxEditLexClass.cpp
