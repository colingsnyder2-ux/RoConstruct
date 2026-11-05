// from server: 100% by auto
// roc 2008-06 00401840  unit: CAboutRobloxDialog  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401840
//
// 00401840  8bc1                 mov eax, ecx
// 00401842  33c9                 xor ecx, ecx
// 00401844  8908                 mov dword ptr [eax], ecx
// 00401846  894804               mov dword ptr [eax + 4], ecx
// 00401849  894808               mov dword ptr [eax + 8], ecx
// 0040184c  89480c               mov dword ptr [eax + 0xc], ecx
// 0040184f  894810               mov dword ptr [eax + 0x10], ecx
// 00401852  894814               mov dword ptr [eax + 0x14], ecx
// 00401855  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ??0CFileStatus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
