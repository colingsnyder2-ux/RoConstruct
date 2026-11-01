// from server: 100% by auto
// roc 2007-03 006583d0  unit: seg_00650000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006583d0
//
// 006583d0  8bc1                 mov eax, ecx
// 006583d2  33c9                 xor ecx, ecx
// 006583d4  c700dc807c00         mov dword ptr [eax], 0x7c80dc
// 006583da  894804               mov dword ptr [eax + 4], ecx
// 006583dd  894810               mov dword ptr [eax + 0x10], ecx
// 006583e0  89480c               mov dword ptr [eax + 0xc], ecx
// 006583e3  894808               mov dword ptr [eax + 8], ecx
// 006583e6  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
