// from server: 100% by auto
// roc 2007-03 006e6660  unit: seg_006e0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e6660
//
// 006e6660  c70184997d00         mov dword ptr [ecx], 0x7d9984
// 006e6666  8b4904               mov ecx, dword ptr [ecx + 4]
// 006e6669  85c9                 test ecx, ecx
// 006e666b  7407                 je 0x6e6674
// 006e666d  51                   push ecx
// 006e666e  e8417df3ff           call 0x61e3b4
// 006e6673  59                   pop ecx
// 006e6674  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
