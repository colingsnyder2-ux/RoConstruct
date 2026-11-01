// from server: 100% by auto
// roc 2009-06 007b5cb0  unit: CXTPMenuBarMDIMenuInfo  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b5cb0
//
// 007b5cb0  8b442408             mov eax, dword ptr [esp + 8]
// 007b5cb4  50                   push eax
// 007b5cb5  8b442408             mov eax, dword ptr [esp + 8]
// 007b5cb9  8d54240c             lea edx, [esp + 0xc]
// 007b5cbd  52                   push edx
// 007b5cbe  50                   push eax
// 007b5cbf  83c120               add ecx, 0x20
// 007b5cc2  e8a9d3fdff           call 0x793070
// 007b5cc7  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?GetNextMenu@CXTPMenuBarMDIMenus@@QBEXAAPAU__POSITION@@AAPAVCXTPMenuBarMDIMenuInfo@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
