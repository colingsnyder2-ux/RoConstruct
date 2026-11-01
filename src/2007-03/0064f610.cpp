// from server: 100% by auto
// roc 2007-03 0064f610  unit: seg_00640000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0064f610
//
// 0064f610  8bc1                 mov eax, ecx
// 0064f612  33c9                 xor ecx, ecx
// 0064f614  c70040667c00         mov dword ptr [eax], 0x7c6640
// 0064f61a  894804               mov dword ptr [eax + 4], ecx
// 0064f61d  894810               mov dword ptr [eax + 0x10], ecx
// 0064f620  89480c               mov dword ptr [eax + 0xc], ecx
// 0064f623  894808               mov dword ptr [eax + 8], ecx
// 0064f626  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
