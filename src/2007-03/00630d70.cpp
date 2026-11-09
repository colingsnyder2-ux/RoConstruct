// from server: 100% by auto
// roc 2007-03 00630d70  unit: seg_00630000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00630d70
//
// 00630d70  c701b83b7c00         mov dword ptr [ecx], 0x7c3bb8
// 00630d76  8b4904               mov ecx, dword ptr [ecx + 4]
// 00630d79  85c9                 test ecx, ecx
// 00630d7b  7407                 je 0x630d84
// 00630d7d  51                   push ecx
// 00630d7e  e831d6feff           call 0x61e3b4
// 00630d83  59                   pop ecx
// 00630d84  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
