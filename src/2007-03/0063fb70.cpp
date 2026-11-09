// from server: 100% by auto
// roc 2007-03 0063fb70  unit: seg_00630000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0063fb70
//
// 0063fb70  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0063fb73  50                   push eax
// 0063fb74  ff1500ee7700         call dword ptr [0x77ee00]
// 0063fb7a  50                   push eax
// 0063fb7b  e80eb00f00           call 0x73ab8e
// 0063fb80  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
