// from server: 100% by auto
// roc 2007-03 00694c20  unit: seg_00690000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00694c20
//
// 00694c20  c701640c7d00         mov dword ptr [ecx], 0x7d0c64
// 00694c26  8b4904               mov ecx, dword ptr [ecx + 4]
// 00694c29  85c9                 test ecx, ecx
// 00694c2b  7407                 je 0x694c34
// 00694c2d  51                   push ecx
// 00694c2e  e88197f8ff           call 0x61e3b4
// 00694c33  59                   pop ecx
// 00694c34  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
