// from server: 100% by auto
// roc 2007-03 0066e340  unit: seg_00660000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066e340
//
// 0066e340  8b442404             mov eax, dword ptr [esp + 4]
// 0066e344  50                   push eax
// 0066e345  51                   push ecx
// 0066e346  ff15d8ee7700         call dword ptr [0x77eed8]
// 0066e34c  f7d8                 neg eax
// 0066e34e  1bc0                 sbb eax, eax
// 0066e350  83c001               add eax, 1
// 0066e353  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ??9CRect@@QBEHABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
