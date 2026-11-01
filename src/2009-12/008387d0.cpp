// from server: 100% by auto
// roc 2009-12 008387d0  unit: CXTPDockingPaneManager  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008387d0
//
// 008387d0  8d442404             lea eax, [esp + 4]
// 008387d4  50                   push eax
// 008387d5  e8c6310000           call 0x83b9a0
// 008387da  85c0                 test eax, eax
// 008387dc  740d                 je 0x8387eb
// 008387de  83f8ff               cmp eax, -1
// 008387e1  7408                 je 0x8387eb
// 008387e3  b857000780           mov eax, 0x80070057
// 008387e8  c21400               ret 0x14
// 008387eb  8b442414             mov eax, dword ptr [esp + 0x14]
// 008387ef  b903000000           mov ecx, 3
// 008387f4  668908               mov word ptr [eax], cx
// 008387f7  c7400800000000       mov dword ptr [eax + 8], 0
// 008387fe  33c0                 xor eax, eax
// 00838800  c21400               ret 0x14
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleState@CXTPDockingPaneManager@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
