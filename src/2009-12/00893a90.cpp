// from server: 100% by auto
// roc 2009-12 00893a90  unit: CXTPMenuBar::CControlMDIButton  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00893a90
//
// 00893a90  8b442404             mov eax, dword ptr [esp + 4]
// 00893a94  c70010000000         mov dword ptr [eax], 0x10
// 00893a9a  c7400410000000       mov dword ptr [eax + 4], 0x10
// 00893aa1  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?GetSize@CControlMDIButton@CXTPMenuBar@@UAE?AVCSize@@PAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
