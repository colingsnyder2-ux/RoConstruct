// from server: 100% by auto
// roc 2007-03 006ce300  unit: seg_006c0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006ce300
//
// 006ce300  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 006ce303  8b01                 mov eax, dword ptr [ecx]
// 006ce305  8b5004               mov edx, dword ptr [eax + 4]
// 006ce308  ffe2                 jmp edx
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?InvalidateRect@CXTPDockingPaneCaptionButton@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
