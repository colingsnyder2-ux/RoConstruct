// from server: 100% by auto
// roc 2009-06 008857c0  unit: seg_00880000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008857c0
//
// 008857c0  6808bb8b00           push 0x8bbb08
// 008857c5  ff159ced8900         call dword ptr [0x89ed9c]
// 008857cb  a300b6a300           mov dword ptr [0xa3b600], eax
// 008857d0  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\viewedit.cpp (function ??__E_afxMsgFindReplace@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewedit.cpp
