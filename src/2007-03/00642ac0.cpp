// from server: 100% by auto
// roc 2007-03 00642ac0  unit: seg_00640000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00642ac0
//
// 00642ac0  c70190567c00         mov dword ptr [ecx], 0x7c5690
// 00642ac6  8b4904               mov ecx, dword ptr [ecx + 4]
// 00642ac9  85c9                 test ecx, ecx
// 00642acb  7407                 je 0x642ad4
// 00642acd  51                   push ecx
// 00642ace  e8e1b8fdff           call 0x61e3b4
// 00642ad3  59                   pop ecx
// 00642ad4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
