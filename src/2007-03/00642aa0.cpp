// from server: 100% by auto
// roc 2007-03 00642aa0  unit: seg_00640000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00642aa0
//
// 00642aa0  8bc1                 mov eax, ecx
// 00642aa2  33c9                 xor ecx, ecx
// 00642aa4  c70090567c00         mov dword ptr [eax], 0x7c5690
// 00642aaa  894804               mov dword ptr [eax + 4], ecx
// 00642aad  894810               mov dword ptr [eax + 0x10], ecx
// 00642ab0  89480c               mov dword ptr [eax + 0xc], ecx
// 00642ab3  894808               mov dword ptr [eax + 8], ecx
// 00642ab6  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
