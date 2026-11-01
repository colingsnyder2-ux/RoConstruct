// from server: 100% by auto
// roc 2007-03 0070ef60  unit: seg_00700000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0070ef60
//
// 0070ef60  8bc1                 mov eax, ecx
// 0070ef62  33c9                 xor ecx, ecx
// 0070ef64  c7006ce47d00         mov dword ptr [eax], 0x7de46c
// 0070ef6a  894804               mov dword ptr [eax + 4], ecx
// 0070ef6d  894810               mov dword ptr [eax + 0x10], ecx
// 0070ef70  89480c               mov dword ptr [eax + 0xc], ecx
// 0070ef73  894808               mov dword ptr [eax + 8], ecx
// 0070ef76  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??0CByteArray@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
