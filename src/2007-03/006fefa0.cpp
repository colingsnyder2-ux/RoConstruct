// from server: 100% by auto
// roc 2007-03 006fefa0  unit: seg_006f0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006fefa0
//
// 006fefa0  c70160d07d00         mov dword ptr [ecx], 0x7dd060
// 006fefa6  8b4904               mov ecx, dword ptr [ecx + 4]
// 006fefa9  85c9                 test ecx, ecx
// 006fefab  7407                 je 0x6fefb4
// 006fefad  51                   push ecx
// 006fefae  e801f4f1ff           call 0x61e3b4
// 006fefb3  59                   pop ecx
// 006fefb4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
