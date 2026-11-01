// from server: 100% by auto
// roc 2007-03 004018c0  unit: seg_00400000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004018c0
//
// 004018c0  8bc1                 mov eax, ecx
// 004018c2  33c9                 xor ecx, ecx
// 004018c4  8908                 mov dword ptr [eax], ecx
// 004018c6  894804               mov dword ptr [eax + 4], ecx
// 004018c9  894808               mov dword ptr [eax + 8], ecx
// 004018cc  89480c               mov dword ptr [eax + 0xc], ecx
// 004018cf  894810               mov dword ptr [eax + 0x10], ecx
// 004018d2  894814               mov dword ptr [eax + 0x14], ecx
// 004018d5  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\doccore.cpp (function ??0CFileStatus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/doccore.cpp
