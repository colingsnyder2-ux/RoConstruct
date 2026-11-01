// from server: 100% by auto
// roc 2007-03 0076e720  unit: seg_00760000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0076e720
//
// 0076e720  68b0367900           push 0x7936b0
// 0076e725  ff15c0ed7700         call dword ptr [0x77edc0]
// 0076e72b  a34c668b00           mov dword ptr [0x8b664c], eax
// 0076e730  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\viewedit.cpp (function ??__E_afxMsgFindReplace@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewedit.cpp
