// from server: 100% by auto
// roc 2007-03 0063ab20  unit: seg_00630000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0063ab20
//
// 0063ab20  8b4138               mov eax, dword ptr [ecx + 0x38]
// 0063ab23  85c0                 test eax, eax
// 0063ab25  750a                 jne 0x63ab31
// 0063ab27  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0063ab2a  50                   push eax
// 0063ab2b  ff15c8ec7700         call dword ptr [0x77ecc8]
// 0063ab31  50                   push eax
// 0063ab32  e8173bfeff           call 0x61e64e
// 0063ab37  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetOwner@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
