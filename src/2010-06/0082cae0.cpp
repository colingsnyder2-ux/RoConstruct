// from server: 100% by auto
// roc 2010-06 0082cae0  unit: CXTPRibbonTheme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0082cae0
//
// 0082cae0  56                   push esi
// 0082cae1  8bf1                 mov esi, ecx
// 0082cae3  e8a8bb0500           call 0x888690
// 0082cae8  6a00                 push 0
// 0082caea  6a04                 push 4
// 0082caec  6a02                 push 2
// 0082caee  6a02                 push 2
// 0082caf0  8d4604               lea eax, [esi + 4]
// 0082caf3  50                   push eax
// 0082caf4  c7060459a600         mov dword ptr [esi], 0xa65904
// 0082cafa  ff15c0bb9e00         call dword ptr [0x9ebbc0]
// 0082cb00  8bc6                 mov eax, esi
// 0082cb02  5e                   pop esi
// 0082cb03  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ??0CAppearanceSetFlat@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
