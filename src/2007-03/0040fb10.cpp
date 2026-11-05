// from server: 100% by auto
// roc 2007-03 0040fb10  unit: seg_00400000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0040fb10
//
// 0040fb10  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040fb13  50                   push eax
// 0040fb14  ff15c8ec7700         call dword ptr [0x77ecc8]
// 0040fb1a  50                   push eax
// 0040fb1b  e82eeb2000           call 0x61e64e
// 0040fb20  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barcool.cpp (function ?GetParent@CWnd@@QBEPAV1@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcool.cpp
