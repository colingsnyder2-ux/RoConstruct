// from server: 100% by auto
// roc 2007-03 00630d10  unit: seg_00630000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00630d10
//
// 00630d10  8bc1                 mov eax, ecx
// 00630d12  33c9                 xor ecx, ecx
// 00630d14  c700a03b7c00         mov dword ptr [eax], 0x7c3ba0
// 00630d1a  894804               mov dword ptr [eax + 4], ecx
// 00630d1d  894810               mov dword ptr [eax + 0x10], ecx
// 00630d20  89480c               mov dword ptr [eax + 0xc], ecx
// 00630d23  894808               mov dword ptr [eax + 8], ecx
// 00630d26  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
