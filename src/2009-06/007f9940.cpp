// from server: 100% by auto
// roc 2009-06 007f9940  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f9940
//
// 007f9940  56                   push esi
// 007f9941  6a00                 push 0
// 007f9943  6a00                 push 0
// 007f9945  8bf1                 mov esi, ecx
// 007f9947  6a00                 push 0
// 007f9949  6a00                 push 0
// 007f994b  8d4604               lea eax, [esi + 4]
// 007f994e  50                   push eax
// 007f994f  c7065ca79000         mov dword ptr [esi], 0x90a75c
// 007f9955  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007f995c  ff15a4ed8900         call dword ptr [0x89eda4]
// 007f9962  c74614feffffff       mov dword ptr [esi + 0x14], 0xfffffffe
// 007f9969  c7462000000000       mov dword ptr [esi + 0x20], 0
// 007f9970  8bc6                 mov eax, esi
// 007f9972  5e                   pop esi
// 007f9973  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ??0CXTPTabPaintManagerAppearanceSet@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
