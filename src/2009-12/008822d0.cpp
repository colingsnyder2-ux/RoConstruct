// from server: 100% by auto
// roc 2009-12 008822d0  unit: CXTPControlGalleryOffice2007Theme  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008822d0
//
// 008822d0  8b442414             mov eax, dword ptr [esp + 0x14]
// 008822d4  2b44240c             sub eax, dword ptr [esp + 0xc]
// 008822d8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008822dc  49                   dec ecx
// 008822dd  0fafc1               imul eax, ecx
// 008822e0  50                   push eax
// 008822e1  6a00                 push 0
// 008822e3  8d542410             lea edx, [esp + 0x10]
// 008822e7  52                   push edx
// 008822e8  ff156ccc9800         call dword ptr [0x98cc6c]
// 008822ee  8b442404             mov eax, dword ptr [esp + 4]
// 008822f2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008822f6  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008822fa  8908                 mov dword ptr [eax], ecx
// 008822fc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00882300  895004               mov dword ptr [eax + 4], edx
// 00882303  8b542414             mov edx, dword ptr [esp + 0x14]
// 00882307  894808               mov dword ptr [eax + 8], ecx
// 0088230a  89500c               mov dword ptr [eax + 0xc], edx
// 0088230d  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPResourceTheme.cpp (function ?OffsetSourceRect@@YA?AVCRect@@V1@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPResourceTheme.cpp
