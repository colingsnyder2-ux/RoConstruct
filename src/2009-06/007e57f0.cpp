// from server: 100% by auto
// roc 2009-06 007e57f0  unit: CXTPShadowsManager::PAVCShadowWnd::?$CList  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e57f0
//
// 007e57f0  56                   push esi
// 007e57f1  8bf1                 mov esi, ecx
// 007e57f3  837e1000             cmp dword ptr [esi + 0x10], 0
// 007e57f7  7537                 jne 0x7e5830
// 007e57f9  8b4618               mov eax, dword ptr [esi + 0x18]
// 007e57fc  6a0c                 push 0xc
// 007e57fe  50                   push eax
// 007e57ff  8d4e14               lea ecx, [esi + 0x14]
// 007e5802  51                   push ecx
// 007e5803  e8b23df3ff           call 0x7195ba
// 007e5808  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007e580b  83c004               add eax, 4
// 007e580e  8d1449               lea edx, [ecx + ecx*2]
// 007e5811  83c1ff               add ecx, -1
// 007e5814  8d4490f4             lea eax, [eax + edx*4 - 0xc]
// 007e5818  7816                 js 0x7e5830
// 007e581a  8d9b00000000         lea ebx, [ebx]
// 007e5820  8b5610               mov edx, dword ptr [esi + 0x10]
// 007e5823  8910                 mov dword ptr [eax], edx
// 007e5825  894610               mov dword ptr [esi + 0x10], eax
// 007e5828  49                   dec ecx
// 007e5829  83e80c               sub eax, 0xc
// 007e582c  85c9                 test ecx, ecx
// 007e582e  7df0                 jge 0x7e5820
// 007e5830  8b4610               mov eax, dword ptr [esi + 0x10]
// 007e5833  85c0                 test eax, eax
// 007e5835  7505                 jne 0x7e583c
// 007e5837  e8a834f3ff           call 0x718ce4
// 007e583c  8b08                 mov ecx, dword ptr [eax]
// 007e583e  8b542408             mov edx, dword ptr [esp + 8]
// 007e5842  894e10               mov dword ptr [esi + 0x10], ecx
// 007e5845  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007e5849  895004               mov dword ptr [eax + 4], edx
// 007e584c  8908                 mov dword ptr [eax], ecx
// 007e584e  ff460c               inc dword ptr [esi + 0xc]
// 007e5851  5e                   pop esi
// 007e5852  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?NewNode@?$CList@II@@IAEPAUCNode@1@PAU21@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
