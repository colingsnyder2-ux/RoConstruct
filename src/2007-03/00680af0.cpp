// from server: 100% by auto
// roc 2007-03 00680af0  unit: seg_00680000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00680af0
//
// 00680af0  c70130e27c00         mov dword ptr [ecx], 0x7ce230
// 00680af6  8b4904               mov ecx, dword ptr [ecx + 4]
// 00680af9  85c9                 test ecx, ecx
// 00680afb  7407                 je 0x680b04
// 00680afd  51                   push ecx
// 00680afe  e8b1d8f9ff           call 0x61e3b4
// 00680b03  59                   pop ecx
// 00680b04  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
