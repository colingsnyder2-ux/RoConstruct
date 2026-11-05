// from server: 100% by auto
// roc 2007-03 0066e490  unit: seg_00660000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066e490
//
// 0066e490  8bc1                 mov eax, ecx
// 0066e492  33c9                 xor ecx, ecx
// 0066e494  c70078b67c00         mov dword ptr [eax], 0x7cb678
// 0066e49a  894804               mov dword ptr [eax + 4], ecx
// 0066e49d  894810               mov dword ptr [eax + 0x10], ecx
// 0066e4a0  89480c               mov dword ptr [eax + 0xc], ecx
// 0066e4a3  894808               mov dword ptr [eax + 8], ecx
// 0066e4a6  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
