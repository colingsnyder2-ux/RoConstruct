// from server: 100% by auto
// roc 2007-03 0071fa50  unit: seg_00710000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071fa50
//
// 0071fa50  c701403a7e00         mov dword ptr [ecx], 0x7e3a40
// 0071fa56  8b4904               mov ecx, dword ptr [ecx + 4]
// 0071fa59  85c9                 test ecx, ecx
// 0071fa5b  7407                 je 0x71fa64
// 0071fa5d  51                   push ecx
// 0071fa5e  e851e9efff           call 0x61e3b4
// 0071fa63  59                   pop ecx
// 0071fa64  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
