// from server: 100% by auto
// roc 2009-12 008d4fa0  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d4fa0
//
// 008d4fa0  8b442408             mov eax, dword ptr [esp + 8]
// 008d4fa4  8b4844               mov ecx, dword ptr [eax + 0x44]
// 008d4fa7  56                   push esi
// 008d4fa8  8b742408             mov esi, dword ptr [esp + 8]
// 008d4fac  890e                 mov dword ptr [esi], ecx
// 008d4fae  8b5048               mov edx, dword ptr [eax + 0x48]
// 008d4fb1  895604               mov dword ptr [esi + 4], edx
// 008d4fb4  8b484c               mov ecx, dword ptr [eax + 0x4c]
// 008d4fb7  6a02                 push 2
// 008d4fb9  894e08               mov dword ptr [esi + 8], ecx
// 008d4fbc  8b5050               mov edx, dword ptr [eax + 0x50]
// 008d4fbf  6a02                 push 2
// 008d4fc1  56                   push esi
// 008d4fc2  89560c               mov dword ptr [esi + 0xc], edx
// 008d4fc5  ff1558ca9800         call dword ptr [0x98ca58]
// 008d4fcb  8bc6                 mov eax, esi
// 008d4fcd  5e                   pop esi
// 008d4fce  c20800               ret 8
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?GetButtonDrawRect@CXTPTabPaintManagerAppearanceSet@@UAE?AVCRect@@PBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
