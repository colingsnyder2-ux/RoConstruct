// from server: 100% by auto
// roc 2007-03 0062ba40  unit: seg_00620000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062ba40
//
// 0062ba40  c70108367c00         mov dword ptr [ecx], 0x7c3608
// 0062ba46  8b4904               mov ecx, dword ptr [ecx + 4]
// 0062ba49  85c9                 test ecx, ecx
// 0062ba4b  7407                 je 0x62ba54
// 0062ba4d  51                   push ecx
// 0062ba4e  e86129ffff           call 0x61e3b4
// 0062ba53  59                   pop ecx
// 0062ba54  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
