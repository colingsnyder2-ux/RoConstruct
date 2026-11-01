// from server: 100% by auto
// roc 2009-12 008d44e0  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d44e0
//
// 008d44e0  56                   push esi
// 008d44e1  6a00                 push 0
// 008d44e3  6a00                 push 0
// 008d44e5  8bf1                 mov esi, ecx
// 008d44e7  6a00                 push 0
// 008d44e9  6a00                 push 0
// 008d44eb  8d4604               lea eax, [esi + 4]
// 008d44ee  50                   push eax
// 008d44ef  c706ccaba000         mov dword ptr [esi], 0xa0abcc
// 008d44f5  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 008d44fc  ff1538ca9800         call dword ptr [0x98ca38]
// 008d4502  c74614feffffff       mov dword ptr [esi + 0x14], 0xfffffffe
// 008d4509  c7462000000000       mov dword ptr [esi + 0x20], 0
// 008d4510  8bc6                 mov eax, esi
// 008d4512  5e                   pop esi
// 008d4513  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ??0CXTPTabPaintManagerAppearanceSet@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
