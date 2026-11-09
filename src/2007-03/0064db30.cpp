// from server: 100% by auto
// roc 2007-03 0064db30  unit: seg_00640000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0064db30
//
// 0064db30  c70134607c00         mov dword ptr [ecx], 0x7c6034
// 0064db36  8b4904               mov ecx, dword ptr [ecx + 4]
// 0064db39  85c9                 test ecx, ecx
// 0064db3b  7407                 je 0x64db44
// 0064db3d  51                   push ecx
// 0064db3e  e87108fdff           call 0x61e3b4
// 0064db43  59                   pop ecx
// 0064db44  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
