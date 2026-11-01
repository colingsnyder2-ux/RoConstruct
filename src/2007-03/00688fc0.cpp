// from server: 100% by auto
// roc 2007-03 00688fc0  unit: seg_00680000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00688fc0
//
// 00688fc0  c701fced7c00         mov dword ptr [ecx], 0x7cedfc
// 00688fc6  8b4904               mov ecx, dword ptr [ecx + 4]
// 00688fc9  85c9                 test ecx, ecx
// 00688fcb  7407                 je 0x688fd4
// 00688fcd  51                   push ecx
// 00688fce  e8e153f9ff           call 0x61e3b4
// 00688fd3  59                   pop ecx
// 00688fd4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
