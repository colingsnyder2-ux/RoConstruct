// from server: 100% by auto
// roc 2007-03 0064fee0  unit: seg_00640000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0064fee0
//
// 0064fee0  c701c0667c00         mov dword ptr [ecx], 0x7c66c0
// 0064fee6  8b4904               mov ecx, dword ptr [ecx + 4]
// 0064fee9  85c9                 test ecx, ecx
// 0064feeb  7407                 je 0x64fef4
// 0064feed  51                   push ecx
// 0064feee  e8c1e4fcff           call 0x61e3b4
// 0064fef3  59                   pop ecx
// 0064fef4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
