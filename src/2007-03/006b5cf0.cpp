// from server: 100% by auto
// roc 2007-03 006b5cf0  unit: seg_006b0000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b5cf0
//
// 006b5cf0  8bc1                 mov eax, ecx
// 006b5cf2  33c9                 xor ecx, ecx
// 006b5cf4  c70018497d00         mov dword ptr [eax], 0x7d4918
// 006b5cfa  894804               mov dword ptr [eax + 4], ecx
// 006b5cfd  894810               mov dword ptr [eax + 0x10], ecx
// 006b5d00  89480c               mov dword ptr [eax + 0xc], ecx
// 006b5d03  894808               mov dword ptr [eax + 8], ecx
// 006b5d06  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
