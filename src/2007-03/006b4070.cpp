// from server: 100% by auto
// roc 2007-03 006b4070  unit: seg_006b0000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b4070
//
// 006b4070  c7013c467d00         mov dword ptr [ecx], 0x7d463c
// 006b4076  8b4904               mov ecx, dword ptr [ecx + 4]
// 006b4079  85c9                 test ecx, ecx
// 006b407b  7407                 je 0x6b4084
// 006b407d  51                   push ecx
// 006b407e  e831a3f6ff           call 0x61e3b4
// 006b4083  59                   pop ecx
// 006b4084  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
