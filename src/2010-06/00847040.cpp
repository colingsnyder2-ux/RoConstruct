// from server: 100% by auto
// roc 2010-06 00847040  unit: CXTPMenuBarMDIMenuInfo  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00847040
//
// 00847040  8b442408             mov eax, dword ptr [esp + 8]
// 00847044  50                   push eax
// 00847045  8b442408             mov eax, dword ptr [esp + 8]
// 00847049  8d54240c             lea edx, [esp + 0xc]
// 0084704d  52                   push edx
// 0084704e  50                   push eax
// 0084704f  83c120               add ecx, 0x20
// 00847052  e839920200           call 0x870290
// 00847057  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?GetNextMenu@CXTPMenuBarMDIMenus@@QBEXAAPAU__POSITION@@AAPAVCXTPMenuBarMDIMenuInfo@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMenuBar.cpp
