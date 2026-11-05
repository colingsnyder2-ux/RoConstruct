// from server: 100% by auto
// roc 2007-08 0076d4c0  unit: seg_00760000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076d4c0
//
// 0076d4c0  6828497900           push 0x794928
// 0076d4c5  ff1570ed7700         call dword ptr [0x77ed70]
// 0076d4cb  a394c08b00           mov dword ptr [0x8bc094], eax
// 0076d4d0  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\viewedit.cpp (function ??__E_afxMsgFindReplace@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewedit.cpp
