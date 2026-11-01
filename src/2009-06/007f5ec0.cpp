// from server: 100% by auto
// roc 2009-06 007f5ec0  unit: CXTPTabPaintManager::CAppearanceSetStateButtons  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5ec0
//
// 007f5ec0  56                   push esi
// 007f5ec1  8bf1                 mov esi, ecx
// 007f5ec3  e8783a0000           call 0x7f9940
// 007f5ec8  6a00                 push 0
// 007f5eca  6a06                 push 6
// 007f5ecc  6a03                 push 3
// 007f5ece  6a02                 push 2
// 007f5ed0  8d4604               lea eax, [esi + 4]
// 007f5ed3  50                   push eax
// 007f5ed4  c7066ca49000         mov dword ptr [esi], 0x90a46c
// 007f5eda  ff15a4ed8900         call dword ptr [0x89eda4]
// 007f5ee0  c7462400000000       mov dword ptr [esi + 0x24], 0
// 007f5ee7  c7068ca59000         mov dword ptr [esi], 0x90a58c
// 007f5eed  c7462001000000       mov dword ptr [esi + 0x20], 1
// 007f5ef4  8bc6                 mov eax, esi
// 007f5ef6  5e                   pop esi
// 007f5ef7  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetVisualStudio2005@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
