// from server: 100% by auto
// roc 2007-03 00637540  unit: seg_00630000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00637540
//
// 00637540  8b442404             mov eax, dword ptr [esp + 4]
// 00637544  b902000000           mov ecx, 2
// 00637549  8908                 mov dword ptr [eax], ecx
// 0063754b  894804               mov dword ptr [eax + 4], ecx
// 0063754e  894808               mov dword ptr [eax + 8], ecx
// 00637551  89480c               mov dword ptr [eax + 0xc], ecx
// 00637554  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?GetCommandBarBorders@CXTPPaintManager@@UAE?AVCRect@@PAVCXTPCommandBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
