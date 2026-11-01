// from server: 100% by auto
// roc 2009-06 007a73a0  unit: CXTPControlGalleryOffice2007Theme  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007a73a0
//
// 007a73a0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007a73a4  2b44240c             sub eax, dword ptr [esp + 0xc]
// 007a73a8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007a73ac  49                   dec ecx
// 007a73ad  0fafc1               imul eax, ecx
// 007a73b0  50                   push eax
// 007a73b1  6a00                 push 0
// 007a73b3  8d542410             lea edx, [esp + 0x10]
// 007a73b7  52                   push edx
// 007a73b8  ff15f8ed8900         call dword ptr [0x89edf8]
// 007a73be  8b442404             mov eax, dword ptr [esp + 4]
// 007a73c2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007a73c6  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007a73ca  8908                 mov dword ptr [eax], ecx
// 007a73cc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007a73d0  895004               mov dword ptr [eax + 4], edx
// 007a73d3  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a73d7  894808               mov dword ptr [eax + 8], ecx
// 007a73da  89500c               mov dword ptr [eax + 0xc], edx
// 007a73dd  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPResourceTheme.cpp (function ?OffsetSourceRect@@YA?AVCRect@@V1@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPResourceTheme.cpp
