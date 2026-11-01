// from server: 100% by auto
// roc 2007-03 0065dc10  unit: seg_00650000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065dc10
//
// 0065dc10  c70118887c00         mov dword ptr [ecx], 0x7c8818
// 0065dc16  8b4904               mov ecx, dword ptr [ecx + 4]
// 0065dc19  85c9                 test ecx, ecx
// 0065dc1b  7407                 je 0x65dc24
// 0065dc1d  51                   push ecx
// 0065dc1e  e89107fcff           call 0x61e3b4
// 0065dc23  59                   pop ecx
// 0065dc24  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??1?$CArray@HABH@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
