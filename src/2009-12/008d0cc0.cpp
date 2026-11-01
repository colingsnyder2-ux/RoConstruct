// from server: 100% by auto
// roc 2009-12 008d0cc0  unit: CXTPTabPaintManager::CColorSetWinXP  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d0cc0
//
// 008d0cc0  56                   push esi
// 008d0cc1  8bf1                 mov esi, ecx
// 008d0cc3  e818380000           call 0x8d44e0
// 008d0cc8  6a00                 push 0
// 008d0cca  6a06                 push 6
// 008d0ccc  6a03                 push 3
// 008d0cce  6a02                 push 2
// 008d0cd0  8d4604               lea eax, [esi + 4]
// 008d0cd3  50                   push eax
// 008d0cd4  c70694a8a000         mov dword ptr [esi], 0xa0a894
// 008d0cda  ff1538ca9800         call dword ptr [0x98ca38]
// 008d0ce0  c706ecaaa000         mov dword ptr [esi], 0xa0aaec
// 008d0ce6  8bc6                 mov eax, esi
// 008d0ce8  5e                   pop esi
// 008d0ce9  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPageSelected@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
