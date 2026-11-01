// from server: 100% by auto
// roc 2009-06 007d6630  unit: CXTPDockingPaneTabbedContainer  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d6630
//
// 007d6630  8b442414             mov eax, dword ptr [esp + 0x14]
// 007d6634  b903000000           mov ecx, 3
// 007d6639  668908               mov word ptr [eax], cx
// 007d663c  c7400800000000       mov dword ptr [eax + 8], 0
// 007d6643  33c0                 xor eax, eax
// 007d6645  c21400               ret 0x14
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?GetAccessibleState@CXTPDockingPaneTabbedContainer@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
