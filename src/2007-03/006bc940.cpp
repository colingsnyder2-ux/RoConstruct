// from server: 100% by auto
// roc 2007-03 006bc940  unit: seg_006b0000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bc940
//
// 006bc940  8bc1                 mov eax, ecx
// 006bc942  33c9                 xor ecx, ecx
// 006bc944  c70004507d00         mov dword ptr [eax], 0x7d5004
// 006bc94a  894804               mov dword ptr [eax + 4], ecx
// 006bc94d  894810               mov dword ptr [eax + 0x10], ecx
// 006bc950  89480c               mov dword ptr [eax + 0xc], ecx
// 006bc953  894808               mov dword ptr [eax + 8], ecx
// 006bc956  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
