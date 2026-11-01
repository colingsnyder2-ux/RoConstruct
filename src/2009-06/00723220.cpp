// from server: 100% by auto
// roc 2009-06 00723220  unit: RBX::Network::Players::Plugin  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00723220
//
// 00723220  8b01                 mov eax, dword ptr [ecx]
// 00723222  56                   push esi
// 00723223  8b742408             mov esi, dword ptr [esp + 8]
// 00723227  8906                 mov dword ptr [esi], eax
// 00723229  8b5104               mov edx, dword ptr [ecx + 4]
// 0072322c  895604               mov dword ptr [esi + 4], edx
// 0072322f  8b4108               mov eax, dword ptr [ecx + 8]
// 00723232  8b542410             mov edx, dword ptr [esp + 0x10]
// 00723236  894608               mov dword ptr [esi + 8], eax
// 00723239  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0072323d  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 00723240  52                   push edx
// 00723241  50                   push eax
// 00723242  56                   push esi
// 00723243  894e0c               mov dword ptr [esi + 0xc], ecx
// 00723246  ff15f8ed8900         call dword ptr [0x89edf8]
// 0072324c  8bc6                 mov eax, esi
// 0072324e  5e                   pop esi
// 0072324f  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ??HCRect@@QBE?AV0@UtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
