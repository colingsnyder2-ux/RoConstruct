// from server: 100% by auto
// roc 2007-03 00662370  unit: seg_00660000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00662370
//
// 00662370  c701a0a07c00         mov dword ptr [ecx], 0x7ca0a0
// 00662376  8b4904               mov ecx, dword ptr [ecx + 4]
// 00662379  85c9                 test ecx, ecx
// 0066237b  7407                 je 0x662384
// 0066237d  51                   push ecx
// 0066237e  e831c0fbff           call 0x61e3b4
// 00662383  59                   pop ecx
// 00662384  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
