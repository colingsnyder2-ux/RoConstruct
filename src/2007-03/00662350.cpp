// from server: 100% by auto
// roc 2007-03 00662350  unit: seg_00660000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00662350
//
// 00662350  8bc1                 mov eax, ecx
// 00662352  33c9                 xor ecx, ecx
// 00662354  c700a0a07c00         mov dword ptr [eax], 0x7ca0a0
// 0066235a  894804               mov dword ptr [eax + 4], ecx
// 0066235d  894810               mov dword ptr [eax + 0x10], ecx
// 00662360  89480c               mov dword ptr [eax + 0xc], ecx
// 00662363  894808               mov dword ptr [eax + 8], ecx
// 00662366  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
