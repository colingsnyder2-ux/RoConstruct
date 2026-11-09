// from server: 100% by auto
// roc 2007-08 004018b0  unit: CAboutRobloxDialog  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004018b0
//
// 004018b0  8bc1                 mov eax, ecx
// 004018b2  33c9                 xor ecx, ecx
// 004018b4  8908                 mov dword ptr [eax], ecx
// 004018b6  894804               mov dword ptr [eax + 4], ecx
// 004018b9  894808               mov dword ptr [eax + 8], ecx
// 004018bc  89480c               mov dword ptr [eax + 0xc], ecx
// 004018bf  894810               mov dword ptr [eax + 0x10], ecx
// 004018c2  894814               mov dword ptr [eax + 0x14], ecx
// 004018c5  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\doccore.cpp (function ??0CFileStatus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/doccore.cpp
