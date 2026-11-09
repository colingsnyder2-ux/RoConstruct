// from server: 100% by auto
// roc 2007-03 006c5680  unit: seg_006c0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c5680
//
// 006c5680  c70154617d00         mov dword ptr [ecx], 0x7d6154
// 006c5686  8b4904               mov ecx, dword ptr [ecx + 4]
// 006c5689  85c9                 test ecx, ecx
// 006c568b  7407                 je 0x6c5694
// 006c568d  51                   push ecx
// 006c568e  e8218df5ff           call 0x61e3b4
// 006c5693  59                   pop ecx
// 006c5694  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
