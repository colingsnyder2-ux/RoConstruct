// from server: 100% by auto
// roc 2010-06 009c49f0  unit: seg_009c0000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009c49f0
//
// 009c49f0  68280da100           push 0xa10d28
// 009c49f5  ff15b8bb9e00         call dword ptr [0x9ebbb8]
// 009c49fb  a30021c000           mov dword ptr [0xc02100], eax
// 009c4a00  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\viewedit.cpp (function ??__E_afxMsgFindReplace@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewedit.cpp
