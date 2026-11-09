// from server: 100% by auto
// roc 2012-06 00aeb6f0  unit: seg_00ae0000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeb6f0
//
// 00aeb6f0  687806b600           push 0xb60678
// 00aeb6f5  ff15743bb200         call dword ptr [0xb23b74]
// 00aeb6fb  a35ca9e100           mov dword ptr [0xe1a95c], eax
// 00aeb700  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\viewedit.cpp (function ??__E_afxMsgFindReplace@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewedit.cpp
