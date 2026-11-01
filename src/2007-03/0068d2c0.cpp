// from server: 100% by auto
// roc 2007-03 0068d2c0  unit: seg_00680000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068d2c0
//
// 0068d2c0  8bc1                 mov eax, ecx
// 0068d2c2  33c9                 xor ecx, ecx
// 0068d2c4  c70060007d00         mov dword ptr [eax], 0x7d0060
// 0068d2ca  894804               mov dword ptr [eax + 4], ecx
// 0068d2cd  894810               mov dword ptr [eax + 0x10], ecx
// 0068d2d0  89480c               mov dword ptr [eax + 0xc], ecx
// 0068d2d3  894808               mov dword ptr [eax + 8], ecx
// 0068d2d6  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
