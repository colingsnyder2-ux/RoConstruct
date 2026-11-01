// from server: 100% by auto
// roc 2007-03 006980a0  unit: seg_00690000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006980a0
//
// 006980a0  8b442404             mov eax, dword ptr [esp + 4]
// 006980a4  c70010000000         mov dword ptr [eax], 0x10
// 006980aa  c7400410000000       mov dword ptr [eax + 4], 0x10
// 006980b1  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?GetSize@CControlMDIButton@CXTPMenuBar@@UAE?AVCSize@@PAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
