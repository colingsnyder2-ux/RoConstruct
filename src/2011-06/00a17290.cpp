// from server: 100% by auto
// roc 2011-06 00a17290  unit: seg_00a10000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00a17290
//
// 00a17290  68b840a700           push 0xa740b8
// 00a17295  ff15c01ba400         call dword ptr [0xa41bc0]
// 00a1729b  a33c41cb00           mov dword ptr [0xcb413c], eax
// 00a172a0  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\viewedit.cpp (function ??__E_afxMsgFindReplace@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewedit.cpp
