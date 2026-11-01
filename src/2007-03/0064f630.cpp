// from server: 100% by auto
// roc 2007-03 0064f630  unit: seg_00640000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0064f630
//
// 0064f630  c70140667c00         mov dword ptr [ecx], 0x7c6640
// 0064f636  8b4904               mov ecx, dword ptr [ecx + 4]
// 0064f639  85c9                 test ecx, ecx
// 0064f63b  7407                 je 0x64f644
// 0064f63d  51                   push ecx
// 0064f63e  e871edfcff           call 0x61e3b4
// 0064f643  59                   pop ecx
// 0064f644  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
