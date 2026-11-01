// from server: 100% by auto
// roc 2009-12 00802b60  unit: CXTPPaintManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00802b60
//
// 00802b60  8b442404             mov eax, dword ptr [esp + 4]
// 00802b64  b902000000           mov ecx, 2
// 00802b69  8908                 mov dword ptr [eax], ecx
// 00802b6b  894804               mov dword ptr [eax + 4], ecx
// 00802b6e  894808               mov dword ptr [eax + 8], ecx
// 00802b71  89480c               mov dword ptr [eax + 0xc], ecx
// 00802b74  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?GetCommandBarBorders@CXTPPaintManager@@UAE?AVCRect@@PAVCXTPCommandBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
