// from server: 100% by auto
// roc 2010-06 0082cbb0  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0082cbb0
//
// 0082cbb0  56                   push esi
// 0082cbb1  8bf1                 mov esi, ecx
// 0082cbb3  e8d8ba0500           call 0x888690
// 0082cbb8  6a00                 push 0
// 0082cbba  6a04                 push 4
// 0082cbbc  6a02                 push 2
// 0082cbbe  6a02                 push 2
// 0082cbc0  8d4604               lea eax, [esi + 4]
// 0082cbc3  50                   push eax
// 0082cbc4  c7060459a600         mov dword ptr [esi], 0xa65904
// 0082cbca  ff15c0bb9e00         call dword ptr [0x9ebbc0]
// 0082cbd0  c7064c59a600         mov dword ptr [esi], 0xa6594c
// 0082cbd6  c7462401000000       mov dword ptr [esi + 0x24], 1
// 0082cbdd  c7462800000000       mov dword ptr [esi + 0x28], 0
// 0082cbe4  8bc6                 mov eax, esi
// 0082cbe6  5e                   pop esi
// 0082cbe7  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ??0CAppearanceSetPropertyPageFlat@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
