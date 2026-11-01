// from server: 100% by auto
// roc 2007-03 0065b050  unit: seg_00650000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065b050
//
// 0065b050  8d41ac               lea eax, [ecx - 0x54]
// 0065b053  85c0                 test eax, eax
// 0065b055  7422                 je 0x65b079
// 0065b057  83782000             cmp dword ptr [eax + 0x20], 0
// 0065b05b  741c                 je 0x65b079
// 0065b05d  85c0                 test eax, eax
// 0065b05f  7403                 je 0x65b064
// 0065b061  8b4020               mov eax, dword ptr [eax + 0x20]
// 0065b064  8b542404             mov edx, dword ptr [esp + 4]
// 0065b068  52                   push edx
// 0065b069  6830257c00           push 0x7c2530
// 0065b06e  6a00                 push 0
// 0065b070  50                   push eax
// 0065b071  e86ab90200           call 0x6869e0
// 0065b076  c20400               ret 4
// 0065b079  b805400080           mov eax, 0x80004005
// 0065b07e  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleParent@CXTPDockingPaneManager@@MAEJPAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
