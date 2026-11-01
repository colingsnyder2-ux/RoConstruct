// from server: 100% by auto
// roc 2009-06 007f6120  unit: CXTPTabPaintManager::CColorSetDefault  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f6120
//
// 007f6120  56                   push esi
// 007f6121  8bf1                 mov esi, ecx
// 007f6123  e818380000           call 0x7f9940
// 007f6128  6a00                 push 0
// 007f612a  6a06                 push 6
// 007f612c  6a03                 push 3
// 007f612e  6a02                 push 2
// 007f6130  8d4604               lea eax, [esi + 4]
// 007f6133  50                   push eax
// 007f6134  c70624a49000         mov dword ptr [esi], 0x90a424
// 007f613a  ff15a4ed8900         call dword ptr [0x89eda4]
// 007f6140  c7067ca69000         mov dword ptr [esi], 0x90a67c
// 007f6146  8bc6                 mov eax, esi
// 007f6148  5e                   pop esi
// 007f6149  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPageSelected@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
