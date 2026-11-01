// from server: 100% by auto
// roc 2007-03 006c8100  unit: seg_006c0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c8100
//
// 006c8100  c70158667d00         mov dword ptr [ecx], 0x7d6658
// 006c8106  8b4904               mov ecx, dword ptr [ecx + 4]
// 006c8109  85c9                 test ecx, ecx
// 006c810b  7407                 je 0x6c8114
// 006c810d  51                   push ecx
// 006c810e  e8a162f5ff           call 0x61e3b4
// 006c8113  59                   pop ecx
// 006c8114  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
