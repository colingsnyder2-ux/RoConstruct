// from server: 100% by auto
// roc 2007-03 00642a80  unit: seg_00640000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00642a80
//
// 00642a80  c70178567c00         mov dword ptr [ecx], 0x7c5678
// 00642a86  8b4904               mov ecx, dword ptr [ecx + 4]
// 00642a89  85c9                 test ecx, ecx
// 00642a8b  7407                 je 0x642a94
// 00642a8d  51                   push ecx
// 00642a8e  e821b9fdff           call 0x61e3b4
// 00642a93  59                   pop ecx
// 00642a94  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
