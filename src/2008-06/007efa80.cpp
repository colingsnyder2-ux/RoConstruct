// from server: 100% by auto
// roc 2008-06 007efa80  unit: seg_007e0000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007efa80
//
// 007efa80  6848b18100           push 0x81b148
// 007efa85  ff15082d8000         call dword ptr [0x802d08]
// 007efa8b  a388df9600           mov dword ptr [0x96df88], eax
// 007efa90  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\viewedit.cpp (function ??__E_afxMsgFindReplace@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewedit.cpp
