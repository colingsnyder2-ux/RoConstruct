// from server: 100% by auto
// roc 2009-06 00727bf0  unit: CXTPPaintManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00727bf0
//
// 00727bf0  8b442404             mov eax, dword ptr [esp + 4]
// 00727bf4  b902000000           mov ecx, 2
// 00727bf9  8908                 mov dword ptr [eax], ecx
// 00727bfb  894804               mov dword ptr [eax + 4], ecx
// 00727bfe  894808               mov dword ptr [eax + 8], ecx
// 00727c01  89480c               mov dword ptr [eax + 0xc], ecx
// 00727c04  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?GetCommandBarBorders@CXTPPaintManager@@UAE?AVCRect@@PAVCXTPCommandBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
