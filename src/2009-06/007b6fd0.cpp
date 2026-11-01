// from server: 100% by auto
// roc 2009-06 007b6fd0  unit: CXTPMenuBar  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b6fd0
//
// 007b6fd0  8b442404             mov eax, dword ptr [esp + 4]
// 007b6fd4  50                   push eax
// 007b6fd5  83c120               add ecx, 0x20
// 007b6fd8  e843f4f7ff           call 0x736420
// 007b6fdd  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007b6fe1  8908                 mov dword ptr [eax], ecx
// 007b6fe3  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?SetAt@CXTPMenuBarMDIMenus@@QAEXIPAVCXTPMenuBarMDIMenuInfo@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
