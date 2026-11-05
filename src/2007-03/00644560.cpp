// from server: 100% by auto
// roc 2007-03 00644560  unit: seg_00640000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00644560
//
// 00644560  8bc1                 mov eax, ecx
// 00644562  33c9                 xor ecx, ecx
// 00644564  c700bc587c00         mov dword ptr [eax], 0x7c58bc
// 0064456a  894804               mov dword ptr [eax + 4], ecx
// 0064456d  894810               mov dword ptr [eax + 0x10], ecx
// 00644570  89480c               mov dword ptr [eax + 0xc], ecx
// 00644573  894808               mov dword ptr [eax + 8], ecx
// 00644576  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
