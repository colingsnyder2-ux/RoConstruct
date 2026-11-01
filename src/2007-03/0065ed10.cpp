// from server: 100% by auto
// roc 2007-03 0065ed10  unit: seg_00650000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065ed10
//
// 0065ed10  8b442404             mov eax, dword ptr [esp + 4]
// 0065ed14  c70094000000         mov dword ptr [eax], 0x94
// 0065ed1a  c740045e000000       mov dword ptr [eax + 4], 0x5e
// 0065ed21  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlPopupColor.cpp (function ?GetSize@CXTPControlColorSelector@@MAE?AVCSize@@PAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlPopupColor.cpp
