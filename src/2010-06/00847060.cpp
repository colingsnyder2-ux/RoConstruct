// from server: 100% by auto
// roc 2010-06 00847060  unit: CXTPMenuBar::CControlMDIButton  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00847060
//
// 00847060  8b442404             mov eax, dword ptr [esp + 4]
// 00847064  c70010000000         mov dword ptr [eax], 0x10
// 0084706a  c7400410000000       mov dword ptr [eax + 4], 0x10
// 00847071  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?GetSize@CControlMDIButton@CXTPMenuBar@@UAE?AVCSize@@PAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMenuBar.cpp
