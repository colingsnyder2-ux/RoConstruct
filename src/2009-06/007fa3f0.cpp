// from server: 100% by auto
// roc 2009-06 007fa3f0  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007fa3f0
//
// 007fa3f0  8b442408             mov eax, dword ptr [esp + 8]
// 007fa3f4  8b4844               mov ecx, dword ptr [eax + 0x44]
// 007fa3f7  56                   push esi
// 007fa3f8  8b742408             mov esi, dword ptr [esp + 8]
// 007fa3fc  890e                 mov dword ptr [esi], ecx
// 007fa3fe  8b5048               mov edx, dword ptr [eax + 0x48]
// 007fa401  895604               mov dword ptr [esi + 4], edx
// 007fa404  8b484c               mov ecx, dword ptr [eax + 0x4c]
// 007fa407  6a02                 push 2
// 007fa409  894e08               mov dword ptr [esi + 8], ecx
// 007fa40c  8b5050               mov edx, dword ptr [eax + 0x50]
// 007fa40f  6a02                 push 2
// 007fa411  56                   push esi
// 007fa412  89560c               mov dword ptr [esi + 0xc], edx
// 007fa415  ff15bced8900         call dword ptr [0x89edbc]
// 007fa41b  8bc6                 mov eax, esi
// 007fa41d  5e                   pop esi
// 007fa41e  c20800               ret 8
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetButtonDrawRect@CXTPTabPaintManagerAppearanceSet@@UAE?AVCRect@@PBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
