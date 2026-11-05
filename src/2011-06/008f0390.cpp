// from server: 100% by auto
// roc 2011-06 008f0390  unit: CXTShadowWnd  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f0390
//
// 008f0390  56                   push esi
// 008f0391  8bf1                 mov esi, ecx
// 008f0393  837e1000             cmp dword ptr [esi + 0x10], 0
// 008f0397  7537                 jne 0x8f03d0
// 008f0399  8b4618               mov eax, dword ptr [esi + 0x18]
// 008f039c  6a0c                 push 0xc
// 008f039e  50                   push eax
// 008f039f  8d4e14               lea ecx, [esi + 0x14]
// 008f03a2  51                   push ecx
// 008f03a3  e844a8f1ff           call 0x80abec
// 008f03a8  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008f03ab  83c004               add eax, 4
// 008f03ae  8d1449               lea edx, [ecx + ecx*2]
// 008f03b1  83c1ff               add ecx, -1
// 008f03b4  8d4490f4             lea eax, [eax + edx*4 - 0xc]
// 008f03b8  7816                 js 0x8f03d0
// 008f03ba  8d9b00000000         lea ebx, [ebx]
// 008f03c0  8b5610               mov edx, dword ptr [esi + 0x10]
// 008f03c3  8910                 mov dword ptr [eax], edx
// 008f03c5  894610               mov dword ptr [esi + 0x10], eax
// 008f03c8  49                   dec ecx
// 008f03c9  83e80c               sub eax, 0xc
// 008f03cc  85c9                 test ecx, ecx
// 008f03ce  7df0                 jge 0x8f03c0
// 008f03d0  8b4610               mov eax, dword ptr [esi + 0x10]
// 008f03d3  85c0                 test eax, eax
// 008f03d5  7505                 jne 0x8f03dc
// 008f03d7  e82e9ff1ff           call 0x80a30a
// 008f03dc  8b08                 mov ecx, dword ptr [eax]
// 008f03de  8b542408             mov edx, dword ptr [esp + 8]
// 008f03e2  894e10               mov dword ptr [esi + 0x10], ecx
// 008f03e5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008f03e9  895004               mov dword ptr [eax + 4], edx
// 008f03ec  8908                 mov dword ptr [eax], ecx
// 008f03ee  ff460c               inc dword ptr [esi + 0xc]
// 008f03f1  5e                   pop esi
// 008f03f2  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?NewNode@?$CList@II@@IAEPAUCNode@1@PAU21@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
