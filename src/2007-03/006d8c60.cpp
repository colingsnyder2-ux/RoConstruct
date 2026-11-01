// from server: 100% by auto
// roc 2007-03 006d8c60  unit: seg_006d0000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d8c60
//
// 006d8c60  8bc1                 mov eax, ecx
// 006d8c62  33c9                 xor ecx, ecx
// 006d8c64  c700807d7d00         mov dword ptr [eax], 0x7d7d80
// 006d8c6a  894804               mov dword ptr [eax + 4], ecx
// 006d8c6d  894810               mov dword ptr [eax + 0x10], ecx
// 006d8c70  89480c               mov dword ptr [eax + 0xc], ecx
// 006d8c73  894808               mov dword ptr [eax + 8], ecx
// 006d8c76  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
