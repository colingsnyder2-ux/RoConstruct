// from server: 100% by auto
// roc 2007-03 0062c480  unit: seg_00620000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062c480
//
// 0062c480  c701c4377c00         mov dword ptr [ecx], 0x7c37c4
// 0062c486  8b4904               mov ecx, dword ptr [ecx + 4]
// 0062c489  85c9                 test ecx, ecx
// 0062c48b  7407                 je 0x62c494
// 0062c48d  51                   push ecx
// 0062c48e  e8211fffff           call 0x61e3b4
// 0062c493  59                   pop ecx
// 0062c494  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
