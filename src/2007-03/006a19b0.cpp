// from server: 100% by auto
// roc 2007-03 006a19b0  unit: seg_006a0000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006a19b0
//
// 006a19b0  8bc1                 mov eax, ecx
// 006a19b2  33c9                 xor ecx, ecx
// 006a19b4  c700fc317d00         mov dword ptr [eax], 0x7d31fc
// 006a19ba  894804               mov dword ptr [eax + 4], ecx
// 006a19bd  894810               mov dword ptr [eax + 0x10], ecx
// 006a19c0  89480c               mov dword ptr [eax + 0xc], ecx
// 006a19c3  894808               mov dword ptr [eax + 8], ecx
// 006a19c6  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
