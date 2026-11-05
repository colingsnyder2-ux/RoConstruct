// from server: 100% by auto
// roc 2010-06 007b2670  unit: CXTPPaintManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b2670
//
// 007b2670  8b442404             mov eax, dword ptr [esp + 4]
// 007b2674  b902000000           mov ecx, 2
// 007b2679  8908                 mov dword ptr [eax], ecx
// 007b267b  894804               mov dword ptr [eax + 4], ecx
// 007b267e  894808               mov dword ptr [eax + 8], ecx
// 007b2681  89480c               mov dword ptr [eax + 0xc], ecx
// 007b2684  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?GetCommandBarBorders@CXTPPaintManager@@UAE?AVCRect@@PAVCXTPCommandBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPaintManager.cpp
