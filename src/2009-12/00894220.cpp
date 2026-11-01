// from server: 100% by auto
// roc 2009-12 00894220  unit: CXTPMenuBar  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00894220
//
// 00894220  8b442404             mov eax, dword ptr [esp + 4]
// 00894224  50                   push eax
// 00894225  83c120               add ecx, 0x20
// 00894228  e853ffffff           call 0x894180
// 0089422d  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00894231  8908                 mov dword ptr [eax], ecx
// 00894233  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?SetAt@CXTPMenuBarMDIMenus@@QAEXIPAVCXTPMenuBarMDIMenuInfo@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
