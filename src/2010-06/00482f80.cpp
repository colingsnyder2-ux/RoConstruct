// from server: 100% by auto
// roc 2010-06 00482f80  unit: RBX::LDraw2Lua::LDrawCommand  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00482f80
//
// 00482f80  c7010c31a100         mov dword ptr [ecx], 0xa1310c
// 00482f86  83c104               add ecx, 4
// 00482f89  ff2500a49e00         jmp dword ptr [0x9ea400]
// library xtp-13.2.1-shared-mfc/Source\SyntaxEdit\XTPSyntaxEditUndoManager.cpp (function ??1CXTPSyntaxEditCommand@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/SyntaxEdit/XTPSyntaxEditUndoManager.cpp
