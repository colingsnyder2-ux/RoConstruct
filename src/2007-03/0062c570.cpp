// from server: 100% by auto
// roc 2007-03 0062c570  unit: seg_00620000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062c570
//
// 0062c570  c701dc377c00         mov dword ptr [ecx], 0x7c37dc
// 0062c576  8b4904               mov ecx, dword ptr [ecx + 4]
// 0062c579  85c9                 test ecx, ecx
// 0062c57b  7407                 je 0x62c584
// 0062c57d  51                   push ecx
// 0062c57e  e8311effff           call 0x61e3b4
// 0062c583  59                   pop ecx
// 0062c584  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
