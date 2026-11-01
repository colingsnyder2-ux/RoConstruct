// from server: 100% by auto
// roc 2009-06 007b68b0  unit: CXTPMenuBar::CControlMDIButton  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b68b0
//
// 007b68b0  8b442404             mov eax, dword ptr [esp + 4]
// 007b68b4  c70010000000         mov dword ptr [eax], 0x10
// 007b68ba  c7400410000000       mov dword ptr [eax + 4], 0x10
// 007b68c1  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?GetSize@CControlMDIButton@CXTPMenuBar@@UAE?AVCSize@@PAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
