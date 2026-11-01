// from server: 100% by auto
// roc 2007-03 00680ad0  unit: seg_00680000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00680ad0
//
// 00680ad0  8bc1                 mov eax, ecx
// 00680ad2  33c9                 xor ecx, ecx
// 00680ad4  c70030e27c00         mov dword ptr [eax], 0x7ce230
// 00680ada  894804               mov dword ptr [eax + 4], ecx
// 00680add  894810               mov dword ptr [eax + 0x10], ecx
// 00680ae0  89480c               mov dword ptr [eax + 0xc], ecx
// 00680ae3  894808               mov dword ptr [eax + 8], ecx
// 00680ae6  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
