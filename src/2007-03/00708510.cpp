// from server: 100% by auto
// roc 2007-03 00708510  unit: seg_00700000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00708510
//
// 00708510  8b442408             mov eax, dword ptr [esp + 8]
// 00708514  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00708517  56                   push esi
// 00708518  8b742408             mov esi, dword ptr [esp + 8]
// 0070851c  890e                 mov dword ptr [esi], ecx
// 0070851e  8b5048               mov edx, dword ptr [eax + 0x48]
// 00708521  895604               mov dword ptr [esi + 4], edx
// 00708524  8b484c               mov ecx, dword ptr [eax + 0x4c]
// 00708527  6a02                 push 2
// 00708529  894e08               mov dword ptr [esi + 8], ecx
// 0070852c  8b5050               mov edx, dword ptr [eax + 0x50]
// 0070852f  6a02                 push 2
// 00708531  56                   push esi
// 00708532  89560c               mov dword ptr [esi + 0xc], edx
// 00708535  ff159ced7700         call dword ptr [0x77ed9c]
// 0070853b  8bc6                 mov eax, esi
// 0070853d  5e                   pop esi
// 0070853e  c20800               ret 8
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetButtonDrawRect@CXTPTabPaintManagerAppearanceSet@@UAE?AVCRect@@PBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
