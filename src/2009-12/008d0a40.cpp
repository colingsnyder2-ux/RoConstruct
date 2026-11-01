// from server: 100% by auto
// roc 2009-12 008d0a40  unit: CXTPTabPaintManager::CAppearanceSetPropertyPage2007  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d0a40
//
// 008d0a40  56                   push esi
// 008d0a41  8bf1                 mov esi, ecx
// 008d0a43  e8983a0000           call 0x8d44e0
// 008d0a48  6a02                 push 2
// 008d0a4a  6a04                 push 4
// 008d0a4c  6a02                 push 2
// 008d0a4e  6a02                 push 2
// 008d0a50  8d4604               lea eax, [esi + 4]
// 008d0a53  50                   push eax
// 008d0a54  c7066ca9a000         mov dword ptr [esi], 0xa0a96c
// 008d0a5a  ff1538ca9800         call dword ptr [0x98ca38]
// 008d0a60  c7461400000000       mov dword ptr [esi + 0x14], 0
// 008d0a67  8bc6                 mov eax, esi
// 008d0a69  5e                   pop esi
// 008d0a6a  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetStateButtons@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
