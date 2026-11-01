// from server: 100% by auto
// roc 2007-03 006fef80  unit: seg_006f0000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006fef80
//
// 006fef80  8bc1                 mov eax, ecx
// 006fef82  33c9                 xor ecx, ecx
// 006fef84  c70060d07d00         mov dword ptr [eax], 0x7dd060
// 006fef8a  894804               mov dword ptr [eax + 4], ecx
// 006fef8d  894810               mov dword ptr [eax + 0x10], ecx
// 006fef90  89480c               mov dword ptr [eax + 0xc], ecx
// 006fef93  894808               mov dword ptr [eax + 8], ecx
// 006fef96  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
