// from server: 100% by auto
// roc 2009-12 0083d3b0  unit: CXTPControlColorSelector  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083d3b0
//
// 0083d3b0  8b442404             mov eax, dword ptr [esp + 4]
// 0083d3b4  c70094000000         mov dword ptr [eax], 0x94
// 0083d3ba  c740045e000000       mov dword ptr [eax + 4], 0x5e
// 0083d3c1  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlPopupColor.cpp (function ?GetSize@CXTPControlColorSelector@@MAE?AVCSize@@PAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlPopupColor.cpp
