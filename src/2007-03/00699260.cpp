// from server: 100% by auto
// roc 2007-03 00699260  unit: seg_00690000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00699260
//
// 00699260  8b442404             mov eax, dword ptr [esp + 4]
// 00699264  50                   push eax
// 00699265  83c120               add ecx, 0x20
// 00699268  e80383feff           call 0x681570
// 0069926d  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00699271  8908                 mov dword ptr [eax], ecx
// 00699273  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?SetAt@CXTPMenuBarMDIMenus@@QAEXIPAVCXTPMenuBarMDIMenuInfo@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
