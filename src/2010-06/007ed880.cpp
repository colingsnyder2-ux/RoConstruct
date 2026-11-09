// from server: 100% by auto
// roc 2010-06 007ed880  unit: PAVCXTPDockingPaneBase::?$CList  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ed880
//
// 007ed880  56                   push esi
// 007ed881  8bf1                 mov esi, ecx
// 007ed883  837e1000             cmp dword ptr [esi + 0x10], 0
// 007ed887  7537                 jne 0x7ed8c0
// 007ed889  8b4618               mov eax, dword ptr [esi + 0x18]
// 007ed88c  6a18                 push 0x18
// 007ed88e  50                   push eax
// 007ed88f  8d4e14               lea ecx, [esi + 0x14]
// 007ed892  51                   push ecx
// 007ed893  e890acfbff           call 0x7a8528
// 007ed898  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007ed89b  83c004               add eax, 4
// 007ed89e  8d1449               lea edx, [ecx + ecx*2]
// 007ed8a1  83c1ff               add ecx, -1
// 007ed8a4  8d44d0e8             lea eax, [eax + edx*8 - 0x18]
// 007ed8a8  7816                 js 0x7ed8c0
// 007ed8aa  8d9b00000000         lea ebx, [ebx]
// 007ed8b0  8b5610               mov edx, dword ptr [esi + 0x10]
// 007ed8b3  8910                 mov dword ptr [eax], edx
// 007ed8b5  894610               mov dword ptr [esi + 0x10], eax
// 007ed8b8  49                   dec ecx
// 007ed8b9  83e818               sub eax, 0x18
// 007ed8bc  85c9                 test ecx, ecx
// 007ed8be  7df0                 jge 0x7ed8b0
// 007ed8c0  8b4610               mov eax, dword ptr [esi + 0x10]
// 007ed8c3  85c0                 test eax, eax
// 007ed8c5  7505                 jne 0x7ed8cc
// 007ed8c7  e880a3fbff           call 0x7a7c4c
// 007ed8cc  8b08                 mov ecx, dword ptr [eax]
// 007ed8ce  8b542408             mov edx, dword ptr [esp + 8]
// 007ed8d2  894e10               mov dword ptr [esi + 0x10], ecx
// 007ed8d5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007ed8d9  8908                 mov dword ptr [eax], ecx
// 007ed8db  895004               mov dword ptr [eax + 4], edx
// 007ed8de  ff460c               inc dword ptr [esi + 0xc]
// 007ed8e1  8d4808               lea ecx, [eax + 8]
// 007ed8e4  85c9                 test ecx, ecx
// 007ed8e6  741b                 je 0x7ed903
// 007ed8e8  c70100000000         mov dword ptr [ecx], 0
// 007ed8ee  c7410400000000       mov dword ptr [ecx + 4], 0
// 007ed8f5  c7410800000000       mov dword ptr [ecx + 8], 0
// 007ed8fc  c7410c00000000       mov dword ptr [ecx + 0xc], 0
// 007ed903  5e                   pop esi
// 007ed904  c20800               ret 8
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?NewNode@?$CList@UXTP_DOCKINGPANE_INFO@@AAU1@@@IAEPAUCNode@1@PAU21@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
