// from server: 100% by auto
// roc 2009-12 00969bc0  unit: seg_00960000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00969bc0
//
// 00969bc0  68b8009b00           push 0x9b00b8
// 00969bc5  ff1530ca9800         call dword ptr [0x98ca30]
// 00969bcb  a328bbb700           mov dword ptr [0xb7bb28], eax
// 00969bd0  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\viewedit.cpp (function ??__E_afxMsgFindReplace@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewedit.cpp
