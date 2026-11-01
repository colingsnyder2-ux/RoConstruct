// from server: 100% by auto
// roc 2009-12 008d0a80  unit: CXTPTabPaintManager::CAppearanceSetStateButtons  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d0a80
//
// 008d0a80  56                   push esi
// 008d0a81  8bf1                 mov esi, ecx
// 008d0a83  e8583a0000           call 0x8d44e0
// 008d0a88  6a00                 push 0
// 008d0a8a  6a06                 push 6
// 008d0a8c  6a03                 push 3
// 008d0a8e  6a02                 push 2
// 008d0a90  8d4604               lea eax, [esi + 4]
// 008d0a93  50                   push eax
// 008d0a94  c706dca8a000         mov dword ptr [esi], 0xa0a8dc
// 008d0a9a  ff1538ca9800         call dword ptr [0x98ca38]
// 008d0aa0  c7462400000000       mov dword ptr [esi + 0x24], 0
// 008d0aa7  c706fca9a000         mov dword ptr [esi], 0xa0a9fc
// 008d0aad  c7462001000000       mov dword ptr [esi + 0x20], 1
// 008d0ab4  8bc6                 mov eax, esi
// 008d0ab6  5e                   pop esi
// 008d0ab7  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetVisualStudio2005@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
