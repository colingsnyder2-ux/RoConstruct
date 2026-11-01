// from server: 100% by auto
// roc 2007-03 00627a90  unit: seg_00620000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00627a90
//
// 00627a90  c70150347c00         mov dword ptr [ecx], 0x7c3450
// 00627a96  8b4904               mov ecx, dword ptr [ecx + 4]
// 00627a99  85c9                 test ecx, ecx
// 00627a9b  7407                 je 0x627aa4
// 00627a9d  51                   push ecx
// 00627a9e  e81169ffff           call 0x61e3b4
// 00627aa3  59                   pop ecx
// 00627aa4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
