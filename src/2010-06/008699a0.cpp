// from server: 100% by auto
// roc 2010-06 008699a0  unit: CXTPDockingPaneSplitterContainer  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008699a0
//
// 008699a0  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 008699a3  8b01                 mov eax, dword ptr [ecx]
// 008699a5  8b5004               mov edx, dword ptr [eax + 4]
// 008699a8  ffe2                 jmp edx
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?InvalidateRect@CXTPDockingPaneCaptionButton@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
