// from server: 100% by auto
// roc 2009-06 0075e960  unit: PAVCXTPDockingPaneBase::?$CList  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075e960
//
// 0075e960  56                   push esi
// 0075e961  8bf1                 mov esi, ecx
// 0075e963  837e1000             cmp dword ptr [esi + 0x10], 0
// 0075e967  7537                 jne 0x75e9a0
// 0075e969  8b4618               mov eax, dword ptr [esi + 0x18]
// 0075e96c  6a18                 push 0x18
// 0075e96e  50                   push eax
// 0075e96f  8d4e14               lea ecx, [esi + 0x14]
// 0075e972  51                   push ecx
// 0075e973  e842acfbff           call 0x7195ba
// 0075e978  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0075e97b  83c004               add eax, 4
// 0075e97e  8d1449               lea edx, [ecx + ecx*2]
// 0075e981  83c1ff               add ecx, -1
// 0075e984  8d44d0e8             lea eax, [eax + edx*8 - 0x18]
// 0075e988  7816                 js 0x75e9a0
// 0075e98a  8d9b00000000         lea ebx, [ebx]
// 0075e990  8b5610               mov edx, dword ptr [esi + 0x10]
// 0075e993  8910                 mov dword ptr [eax], edx
// 0075e995  894610               mov dword ptr [esi + 0x10], eax
// 0075e998  49                   dec ecx
// 0075e999  83e818               sub eax, 0x18
// 0075e99c  85c9                 test ecx, ecx
// 0075e99e  7df0                 jge 0x75e990
// 0075e9a0  8b4610               mov eax, dword ptr [esi + 0x10]
// 0075e9a3  85c0                 test eax, eax
// 0075e9a5  7505                 jne 0x75e9ac
// 0075e9a7  e838a3fbff           call 0x718ce4
// 0075e9ac  8b08                 mov ecx, dword ptr [eax]
// 0075e9ae  8b542408             mov edx, dword ptr [esp + 8]
// 0075e9b2  894e10               mov dword ptr [esi + 0x10], ecx
// 0075e9b5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0075e9b9  8908                 mov dword ptr [eax], ecx
// 0075e9bb  895004               mov dword ptr [eax + 4], edx
// 0075e9be  ff460c               inc dword ptr [esi + 0xc]
// 0075e9c1  8d4808               lea ecx, [eax + 8]
// 0075e9c4  85c9                 test ecx, ecx
// 0075e9c6  741b                 je 0x75e9e3
// 0075e9c8  c70100000000         mov dword ptr [ecx], 0
// 0075e9ce  c7410400000000       mov dword ptr [ecx + 4], 0
// 0075e9d5  c7410800000000       mov dword ptr [ecx + 8], 0
// 0075e9dc  c7410c00000000       mov dword ptr [ecx + 0xc], 0
// 0075e9e3  5e                   pop esi
// 0075e9e4  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?NewNode@?$CList@UXTP_DOCKINGPANE_INFO@@AAU1@@@IAEPAUCNode@1@PAU21@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
