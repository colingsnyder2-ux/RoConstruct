// from server: 100% by auto
// roc 2008-06 0076a730  unit: IIPAVCRgn::?$CMap  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0076a730
//
// 0076a730  56                   push esi
// 0076a731  8bf1                 mov esi, ecx
// 0076a733  837e1000             cmp dword ptr [esi + 0x10], 0
// 0076a737  7537                 jne 0x76a770
// 0076a739  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076a73c  6a0c                 push 0xc
// 0076a73e  50                   push eax
// 0076a73f  8d4e14               lea ecx, [esi + 0x14]
// 0076a742  51                   push ecx
// 0076a743  e8f469f3ff           call 0x6a113c
// 0076a748  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0076a74b  83c004               add eax, 4
// 0076a74e  8d1449               lea edx, [ecx + ecx*2]
// 0076a751  83c1ff               add ecx, -1
// 0076a754  8d4490f4             lea eax, [eax + edx*4 - 0xc]
// 0076a758  7816                 js 0x76a770
// 0076a75a  8d9b00000000         lea ebx, [ebx]
// 0076a760  8b5610               mov edx, dword ptr [esi + 0x10]
// 0076a763  8910                 mov dword ptr [eax], edx
// 0076a765  894610               mov dword ptr [esi + 0x10], eax
// 0076a768  49                   dec ecx
// 0076a769  83e80c               sub eax, 0xc
// 0076a76c  85c9                 test ecx, ecx
// 0076a76e  7df0                 jge 0x76a760
// 0076a770  8b4610               mov eax, dword ptr [esi + 0x10]
// 0076a773  85c0                 test eax, eax
// 0076a775  7505                 jne 0x76a77c
// 0076a777  e8c861f3ff           call 0x6a0944
// 0076a77c  8b08                 mov ecx, dword ptr [eax]
// 0076a77e  8b542408             mov edx, dword ptr [esp + 8]
// 0076a782  894e10               mov dword ptr [esi + 0x10], ecx
// 0076a785  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0076a789  895004               mov dword ptr [eax + 4], edx
// 0076a78c  8908                 mov dword ptr [eax], ecx
// 0076a78e  ff460c               inc dword ptr [esi + 0xc]
// 0076a791  5e                   pop esi
// 0076a792  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?NewNode@?$CList@II@@IAEPAUCNode@1@PAU21@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
