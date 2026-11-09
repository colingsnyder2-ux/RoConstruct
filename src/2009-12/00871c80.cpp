// from server: 100% by auto
// roc 2009-12 00871c80  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00871c80
//
// 00871c80  56                   push esi
// 00871c81  8bf1                 mov esi, ecx
// 00871c83  e858280600           call 0x8d44e0
// 00871c88  6a00                 push 0
// 00871c8a  6a04                 push 4
// 00871c8c  6a02                 push 2
// 00871c8e  6a02                 push 2
// 00871c90  8d4604               lea eax, [esi + 4]
// 00871c93  50                   push eax
// 00871c94  c706c40fa000         mov dword ptr [esi], 0xa00fc4
// 00871c9a  ff1538ca9800         call dword ptr [0x98ca38]
// 00871ca0  c7060c10a000         mov dword ptr [esi], 0xa0100c
// 00871ca6  c7462401000000       mov dword ptr [esi + 0x24], 1
// 00871cad  c7462800000000       mov dword ptr [esi + 0x28], 0
// 00871cb4  8bc6                 mov eax, esi
// 00871cb6  5e                   pop esi
// 00871cb7  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ??0CAppearanceSetPropertyPageFlat@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
