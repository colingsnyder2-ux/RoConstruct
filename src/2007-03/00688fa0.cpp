// from server: 100% by auto
// roc 2007-03 00688fa0  unit: seg_00680000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00688fa0
//
// 00688fa0  8bc1                 mov eax, ecx
// 00688fa2  33c9                 xor ecx, ecx
// 00688fa4  c700fced7c00         mov dword ptr [eax], 0x7cedfc
// 00688faa  894804               mov dword ptr [eax + 4], ecx
// 00688fad  894810               mov dword ptr [eax + 0x10], ecx
// 00688fb0  89480c               mov dword ptr [eax + 0xc], ecx
// 00688fb3  894808               mov dword ptr [eax + 8], ecx
// 00688fb6  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
