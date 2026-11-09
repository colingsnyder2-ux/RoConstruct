// from server: 100% by auto
// roc 2007-03 00644580  unit: seg_00640000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00644580
//
// 00644580  c701bc587c00         mov dword ptr [ecx], 0x7c58bc
// 00644586  8b4904               mov ecx, dword ptr [ecx + 4]
// 00644589  85c9                 test ecx, ecx
// 0064458b  7407                 je 0x644594
// 0064458d  51                   push ecx
// 0064458e  e8219efdff           call 0x61e3b4
// 00644593  59                   pop ecx
// 00644594  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
