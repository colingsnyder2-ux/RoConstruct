// from server: 100% by auto
// roc 2010-06 008357d0  unit: CXTPControlGalleryOffice2007Theme  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008357d0
//
// 008357d0  8b442414             mov eax, dword ptr [esp + 0x14]
// 008357d4  2b44240c             sub eax, dword ptr [esp + 0xc]
// 008357d8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008357dc  49                   dec ecx
// 008357dd  0fafc1               imul eax, ecx
// 008357e0  50                   push eax
// 008357e1  6a00                 push 0
// 008357e3  8d542410             lea edx, [esp + 0x10]
// 008357e7  52                   push edx
// 008357e8  ff1540bc9e00         call dword ptr [0x9ebc40]
// 008357ee  8b442404             mov eax, dword ptr [esp + 4]
// 008357f2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008357f6  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008357fa  8908                 mov dword ptr [eax], ecx
// 008357fc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00835800  895004               mov dword ptr [eax + 4], edx
// 00835803  8b542414             mov edx, dword ptr [esp + 0x14]
// 00835807  894808               mov dword ptr [eax + 8], ecx
// 0083580a  89500c               mov dword ptr [eax + 0xc], edx
// 0083580d  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPOffice2007Theme.cpp (function ?OffsetSourceRect@@YA?AVCRect@@V1@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOffice2007Theme.cpp
