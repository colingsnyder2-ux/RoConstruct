// from server: 100% by auto
// roc 2009-12 008b1170  unit: CXTPDockingPaneTabbedContainer  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b1170
//
// 008b1170  8b442414             mov eax, dword ptr [esp + 0x14]
// 008b1174  b903000000           mov ecx, 3
// 008b1179  668908               mov word ptr [eax], cx
// 008b117c  c7400800000000       mov dword ptr [eax + 8], 0
// 008b1183  33c0                 xor eax, eax
// 008b1185  c21400               ret 0x14
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?GetAccessibleState@CXTPDockingPaneTabbedContainer@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
