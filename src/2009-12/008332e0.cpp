// from server: 100% by auto
// roc 2009-12 008332e0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008332e0
//
// 008332e0  c701ac659f00         mov dword ptr [ecx], 0x9f65ac
// 008332e6  83c118               add ecx, 0x18
// 008332e9  e962feffff           jmp 0x833150
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditLineMarksManager.cpp (function ??1XTP_EDIT_LMPARAM@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditLineMarksManager.cpp
