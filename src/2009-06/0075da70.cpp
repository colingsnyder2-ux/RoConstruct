// from server: 100% by auto
// roc 2009-06 0075da70  unit: CXTPDockingPaneManager  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075da70
//
// 0075da70  8d442404             lea eax, [esp + 4]
// 0075da74  50                   push eax
// 0075da75  e856310000           call 0x760bd0
// 0075da7a  85c0                 test eax, eax
// 0075da7c  740d                 je 0x75da8b
// 0075da7e  83f8ff               cmp eax, -1
// 0075da81  7408                 je 0x75da8b
// 0075da83  b857000780           mov eax, 0x80070057
// 0075da88  c21400               ret 0x14
// 0075da8b  8b442414             mov eax, dword ptr [esp + 0x14]
// 0075da8f  b903000000           mov ecx, 3
// 0075da94  668908               mov word ptr [eax], cx
// 0075da97  c7400800000000       mov dword ptr [eax + 8], 0
// 0075da9e  33c0                 xor eax, eax
// 0075daa0  c21400               ret 0x14
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleState@CXTPDockingPaneManager@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
