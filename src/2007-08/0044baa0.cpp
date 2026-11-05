// from server: 100% by auto
// roc 2007-08 0044baa0  unit: CRobloxControlColorSelector  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044baa0
//
// 0044baa0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0044baa4  8bc1                 mov eax, ecx
// 0044baa6  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044baaa  03d1                 add edx, ecx
// 0044baac  895008               mov dword ptr [eax + 8], edx
// 0044baaf  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044bab3  8908                 mov dword ptr [eax], ecx
// 0044bab5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044bab9  03d1                 add edx, ecx
// 0044babb  894804               mov dword ptr [eax + 4], ecx
// 0044babe  89500c               mov dword ptr [eax + 0xc], edx
// 0044bac1  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ??0CRect@@QAE@UtagPOINT@@UtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
