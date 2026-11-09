// from server: 100% by auto
// roc 2009-12 008c2ae0  unit: CXTPImageEditorPicture::PAVCAlphaBitmap::?$CList  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c2ae0
//
// 008c2ae0  56                   push esi
// 008c2ae1  8bf1                 mov esi, ecx
// 008c2ae3  837e1000             cmp dword ptr [esi + 0x10], 0
// 008c2ae7  7537                 jne 0x8c2b20
// 008c2ae9  8b4618               mov eax, dword ptr [esi + 0x18]
// 008c2aec  6a0c                 push 0xc
// 008c2aee  50                   push eax
// 008c2aef  8d4e14               lea ecx, [esi + 0x14]
// 008c2af2  51                   push ecx
// 008c2af3  e8f018f3ff           call 0x7f43e8
// 008c2af8  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008c2afb  83c004               add eax, 4
// 008c2afe  8d1449               lea edx, [ecx + ecx*2]
// 008c2b01  83c1ff               add ecx, -1
// 008c2b04  8d4490f4             lea eax, [eax + edx*4 - 0xc]
// 008c2b08  7816                 js 0x8c2b20
// 008c2b0a  8d9b00000000         lea ebx, [ebx]
// 008c2b10  8b5610               mov edx, dword ptr [esi + 0x10]
// 008c2b13  8910                 mov dword ptr [eax], edx
// 008c2b15  894610               mov dword ptr [esi + 0x10], eax
// 008c2b18  49                   dec ecx
// 008c2b19  83e80c               sub eax, 0xc
// 008c2b1c  85c9                 test ecx, ecx
// 008c2b1e  7df0                 jge 0x8c2b10
// 008c2b20  8b4610               mov eax, dword ptr [esi + 0x10]
// 008c2b23  85c0                 test eax, eax
// 008c2b25  7505                 jne 0x8c2b2c
// 008c2b27  e8e00ff3ff           call 0x7f3b0c
// 008c2b2c  8b08                 mov ecx, dword ptr [eax]
// 008c2b2e  8b542408             mov edx, dword ptr [esp + 8]
// 008c2b32  894e10               mov dword ptr [esi + 0x10], ecx
// 008c2b35  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008c2b39  895004               mov dword ptr [eax + 4], edx
// 008c2b3c  8908                 mov dword ptr [eax], ecx
// 008c2b3e  ff460c               inc dword ptr [esi + 0xc]
// 008c2b41  5e                   pop esi
// 008c2b42  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?NewNode@?$CList@II@@IAEPAUCNode@1@PAU21@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
