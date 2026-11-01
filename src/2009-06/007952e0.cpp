// from server: 100% by auto
// roc 2009-06 007952e0  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007952e0
//
// 007952e0  56                   push esi
// 007952e1  8bf1                 mov esi, ecx
// 007952e3  e858460600           call 0x7f9940
// 007952e8  6a00                 push 0
// 007952ea  6a04                 push 4
// 007952ec  6a02                 push 2
// 007952ee  6a02                 push 2
// 007952f0  8d4604               lea eax, [esi + 4]
// 007952f3  50                   push eax
// 007952f4  c706e4039000         mov dword ptr [esi], 0x9003e4
// 007952fa  ff15a4ed8900         call dword ptr [0x89eda4]
// 00795300  c7062c049000         mov dword ptr [esi], 0x90042c
// 00795306  c7462401000000       mov dword ptr [esi + 0x24], 1
// 0079530d  c7462800000000       mov dword ptr [esi + 0x28], 0
// 00795314  8bc6                 mov eax, esi
// 00795316  5e                   pop esi
// 00795317  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ??0CAppearanceSetPropertyPageFlat@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
