// from server: 100% by auto
// roc 2007-03 006c56a0  unit: seg_006c0000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c56a0
//
// 006c56a0  8bc1                 mov eax, ecx
// 006c56a2  33c9                 xor ecx, ecx
// 006c56a4  c7006c617d00         mov dword ptr [eax], 0x7d616c
// 006c56aa  894804               mov dword ptr [eax + 4], ecx
// 006c56ad  894810               mov dword ptr [eax + 0x10], ecx
// 006c56b0  89480c               mov dword ptr [eax + 0xc], ecx
// 006c56b3  894808               mov dword ptr [eax + 8], ecx
// 006c56b6  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
