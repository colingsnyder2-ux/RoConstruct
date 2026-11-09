// from server: 100% by auto
// roc 2010-06 00889150  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00889150
//
// 00889150  8b442408             mov eax, dword ptr [esp + 8]
// 00889154  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00889157  56                   push esi
// 00889158  8b742408             mov esi, dword ptr [esp + 8]
// 0088915c  890e                 mov dword ptr [esi], ecx
// 0088915e  8b5048               mov edx, dword ptr [eax + 0x48]
// 00889161  895604               mov dword ptr [esi + 4], edx
// 00889164  8b484c               mov ecx, dword ptr [eax + 0x4c]
// 00889167  6a02                 push 2
// 00889169  894e08               mov dword ptr [esi + 8], ecx
// 0088916c  8b5050               mov edx, dword ptr [eax + 0x50]
// 0088916f  6a02                 push 2
// 00889171  56                   push esi
// 00889172  89560c               mov dword ptr [esi + 0xc], edx
// 00889175  ff15dcbb9e00         call dword ptr [0x9ebbdc]
// 0088917b  8bc6                 mov eax, esi
// 0088917d  5e                   pop esi
// 0088917e  c20800               ret 8
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetButtonDrawRect@CAppearanceSet@CXTPTabPaintManager@@UAE?AVCRect@@PBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
