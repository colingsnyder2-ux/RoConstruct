// from server: 100% by auto
// roc 2007-03 00698080  unit: seg_00690000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00698080
//
// 00698080  8b442408             mov eax, dword ptr [esp + 8]
// 00698084  50                   push eax
// 00698085  8b442408             mov eax, dword ptr [esp + 8]
// 00698089  8d54240c             lea edx, [esp + 0xc]
// 0069808d  52                   push edx
// 0069808e  50                   push eax
// 0069808f  83c120               add ecx, 0x20
// 00698092  e869d4f8ff           call 0x625500
// 00698097  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?GetNextMenu@CXTPMenuBarMDIMenus@@QBEXAAPAU__POSITION@@AAPAVCXTPMenuBarMDIMenuInfo@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
