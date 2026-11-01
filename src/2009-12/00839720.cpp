// from server: 100% by auto
// roc 2009-12 00839720  unit: PAVCXTPDockingPaneBase::?$CList  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00839720
//
// 00839720  56                   push esi
// 00839721  8bf1                 mov esi, ecx
// 00839723  837e1000             cmp dword ptr [esi + 0x10], 0
// 00839727  7537                 jne 0x839760
// 00839729  8b4618               mov eax, dword ptr [esi + 0x18]
// 0083972c  6a18                 push 0x18
// 0083972e  50                   push eax
// 0083972f  8d4e14               lea ecx, [esi + 0x14]
// 00839732  51                   push ecx
// 00839733  e8b0acfbff           call 0x7f43e8
// 00839738  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0083973b  83c004               add eax, 4
// 0083973e  8d1449               lea edx, [ecx + ecx*2]
// 00839741  83c1ff               add ecx, -1
// 00839744  8d44d0e8             lea eax, [eax + edx*8 - 0x18]
// 00839748  7816                 js 0x839760
// 0083974a  8d9b00000000         lea ebx, [ebx]
// 00839750  8b5610               mov edx, dword ptr [esi + 0x10]
// 00839753  8910                 mov dword ptr [eax], edx
// 00839755  894610               mov dword ptr [esi + 0x10], eax
// 00839758  49                   dec ecx
// 00839759  83e818               sub eax, 0x18
// 0083975c  85c9                 test ecx, ecx
// 0083975e  7df0                 jge 0x839750
// 00839760  8b4610               mov eax, dword ptr [esi + 0x10]
// 00839763  85c0                 test eax, eax
// 00839765  7505                 jne 0x83976c
// 00839767  e8a0a3fbff           call 0x7f3b0c
// 0083976c  8b08                 mov ecx, dword ptr [eax]
// 0083976e  8b542408             mov edx, dword ptr [esp + 8]
// 00839772  894e10               mov dword ptr [esi + 0x10], ecx
// 00839775  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00839779  8908                 mov dword ptr [eax], ecx
// 0083977b  895004               mov dword ptr [eax + 4], edx
// 0083977e  ff460c               inc dword ptr [esi + 0xc]
// 00839781  8d4808               lea ecx, [eax + 8]
// 00839784  85c9                 test ecx, ecx
// 00839786  741b                 je 0x8397a3
// 00839788  c70100000000         mov dword ptr [ecx], 0
// 0083978e  c7410400000000       mov dword ptr [ecx + 4], 0
// 00839795  c7410800000000       mov dword ptr [ecx + 8], 0
// 0083979c  c7410c00000000       mov dword ptr [ecx + 0xc], 0
// 008397a3  5e                   pop esi
// 008397a4  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?NewNode@?$CList@UXTP_DOCKINGPANE_INFO@@AAU1@@@IAEPAUCNode@1@PAU21@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
