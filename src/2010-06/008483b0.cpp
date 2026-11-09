// from server: 100% by auto
// roc 2010-06 008483b0  unit: CXTPMenuBar  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008483b0
//
// 008483b0  8b442404             mov eax, dword ptr [esp + 4]
// 008483b4  50                   push eax
// 008483b5  83c120               add ecx, 0x20
// 008483b8  e8c349f6ff           call 0x7acd80
// 008483bd  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008483c1  8908                 mov dword ptr [eax], ecx
// 008483c3  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?SetAt@CXTPMenuBarMDIMenus@@QAEXIPAVCXTPMenuBarMDIMenuInfo@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMenuBar.cpp
