// from server: 100% by auto
// roc 2007-03 0065dbf0  unit: seg_00650000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065dbf0
//
// 0065dbf0  8bc1                 mov eax, ecx
// 0065dbf2  33c9                 xor ecx, ecx
// 0065dbf4  c70018887c00         mov dword ptr [eax], 0x7c8818
// 0065dbfa  894804               mov dword ptr [eax + 4], ecx
// 0065dbfd  894810               mov dword ptr [eax + 0x10], ecx
// 0065dc00  89480c               mov dword ptr [eax + 0xc], ecx
// 0065dc03  894808               mov dword ptr [eax + 8], ecx
// 0065dc06  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
