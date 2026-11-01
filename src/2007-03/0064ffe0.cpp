// from server: 100% by auto
// roc 2007-03 0064ffe0  unit: seg_00640000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0064ffe0
//
// 0064ffe0  c701d8667c00         mov dword ptr [ecx], 0x7c66d8
// 0064ffe6  8b4904               mov ecx, dword ptr [ecx + 4]
// 0064ffe9  85c9                 test ecx, ecx
// 0064ffeb  7407                 je 0x64fff4
// 0064ffed  51                   push ecx
// 0064ffee  e8c1e3fcff           call 0x61e3b4
// 0064fff3  59                   pop ecx
// 0064fff4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
