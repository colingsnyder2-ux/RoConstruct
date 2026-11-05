// from server: 100% by auto
// roc 2010-06 007ec9f0  unit: CXTPDockingPaneManager  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ec9f0
//
// 007ec9f0  8d442404             lea eax, [esp + 4]
// 007ec9f4  50                   push eax
// 007ec9f5  e8f6300000           call 0x7efaf0
// 007ec9fa  85c0                 test eax, eax
// 007ec9fc  740d                 je 0x7eca0b
// 007ec9fe  83f8ff               cmp eax, -1
// 007eca01  7408                 je 0x7eca0b
// 007eca03  b857000780           mov eax, 0x80070057
// 007eca08  c21400               ret 0x14
// 007eca0b  8b442414             mov eax, dword ptr [esp + 0x14]
// 007eca0f  b903000000           mov ecx, 3
// 007eca14  668908               mov word ptr [eax], cx
// 007eca17  c7400800000000       mov dword ptr [eax + 8], 0
// 007eca1e  33c0                 xor eax, eax
// 007eca20  c21400               ret 0x14
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleState@CXTPDockingPaneManager@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
