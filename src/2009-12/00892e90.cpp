// from server: 100% by auto
// roc 2009-12 00892e90  unit: CXTPMenuBarMDIMenuInfo  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00892e90
//
// 00892e90  8b442408             mov eax, dword ptr [esp + 8]
// 00892e94  50                   push eax
// 00892e95  8b442408             mov eax, dword ptr [esp + 8]
// 00892e99  8d54240c             lea edx, [esp + 0xc]
// 00892e9d  52                   push edx
// 00892e9e  50                   push eax
// 00892e9f  83c120               add ecx, 0x20
// 00892ea2  e87969f7ff           call 0x809820
// 00892ea7  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?GetNextMenu@CXTPMenuBarMDIMenus@@QBEXAAPAU__POSITION@@AAPAVCXTPMenuBarMDIMenuInfo@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
