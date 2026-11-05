// from server: 100% by auto
// roc 2007-08 006e44b0  unit: PAVCXTPDockingPaneSplitterWnd::?$CList  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006e44b0
//
// 006e44b0  56                   push esi
// 006e44b1  8bf1                 mov esi, ecx
// 006e44b3  837e1000             cmp dword ptr [esi + 0x10], 0
// 006e44b7  7539                 jne 0x6e44f2
// 006e44b9  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e44bc  6a0c                 push 0xc
// 006e44be  50                   push eax
// 006e44bf  8d4e14               lea ecx, [esi + 0x14]
// 006e44c2  51                   push ecx
// 006e44c3  e8d8c1f4ff           call 0x6306a0
// 006e44c8  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e44cb  83c004               add eax, 4
// 006e44ce  8d1449               lea edx, [ecx + ecx*2]
// 006e44d1  83c1ff               add ecx, -1
// 006e44d4  8d4490f4             lea eax, [eax + edx*4 - 0xc]
// 006e44d8  7818                 js 0x6e44f2
// 006e44da  8d9b00000000         lea ebx, [ebx]
// 006e44e0  8b5610               mov edx, dword ptr [esi + 0x10]
// 006e44e3  8910                 mov dword ptr [eax], edx
// 006e44e5  894610               mov dword ptr [esi + 0x10], eax
// 006e44e8  83e901               sub ecx, 1
// 006e44eb  83e80c               sub eax, 0xc
// 006e44ee  85c9                 test ecx, ecx
// 006e44f0  7dee                 jge 0x6e44e0
// 006e44f2  8b4610               mov eax, dword ptr [esi + 0x10]
// 006e44f5  85c0                 test eax, eax
// 006e44f7  7505                 jne 0x6e44fe
// 006e44f9  e822baf4ff           call 0x62ff20
// 006e44fe  8b08                 mov ecx, dword ptr [eax]
// 006e4500  8b542408             mov edx, dword ptr [esp + 8]
// 006e4504  894e10               mov dword ptr [esi + 0x10], ecx
// 006e4507  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006e450b  895004               mov dword ptr [eax + 4], edx
// 006e450e  8908                 mov dword ptr [eax], ecx
// 006e4510  83460c01             add dword ptr [esi + 0xc], 1
// 006e4514  5e                   pop esi
// 006e4515  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\occmgr.cpp (function ?NewNode@?$CList@PAVIControlSiteFactory@@PAV1@@@IAEPAUCNode@1@PAU21@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occmgr.cpp
