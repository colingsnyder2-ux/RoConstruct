// from server: 100% by auto
// roc 2009-06 00758460  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00758460
//
// 00758460  c70104618f00         mov dword ptr [ecx], 0x8f6104
// 00758466  83c118               add ecx, 0x18
// 00758469  e962feffff           jmp 0x7582d0
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditLineMarksManager.cpp (function ??1XTP_EDIT_LMPARAM@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditLineMarksManager.cpp
