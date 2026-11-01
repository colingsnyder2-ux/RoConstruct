// from server: 100% by auto
// roc 2009-06 007f5dd0  unit: RBX::SleepStage  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5dd0
//
// 007f5dd0  56                   push esi
// 007f5dd1  8bf1                 mov esi, ecx
// 007f5dd3  e8683b0000           call 0x7f9940
// 007f5dd8  6a00                 push 0
// 007f5dda  6a06                 push 6
// 007f5ddc  6a03                 push 3
// 007f5dde  6a02                 push 2
// 007f5de0  8d4604               lea eax, [esi + 4]
// 007f5de3  50                   push eax
// 007f5de4  c7066ca49000         mov dword ptr [esi], 0x90a46c
// 007f5dea  ff15a4ed8900         call dword ptr [0x89eda4]
// 007f5df0  c7462400000000       mov dword ptr [esi + 0x24], 0
// 007f5df7  8bc6                 mov eax, esi
// 007f5df9  5e                   pop esi
// 007f5dfa  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPage2003@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
