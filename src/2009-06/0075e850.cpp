// from server: 100% by auto
// roc 2009-06 0075e850  unit: CXTPDockingPaneManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075e850
//
// 0075e850  8d41ac               lea eax, [ecx - 0x54]
// 0075e853  85c0                 test eax, eax
// 0075e855  7422                 je 0x75e879
// 0075e857  83782000             cmp dword ptr [eax + 0x20], 0
// 0075e85b  741c                 je 0x75e879
// 0075e85d  85c0                 test eax, eax
// 0075e85f  7403                 je 0x75e864
// 0075e861  8b4020               mov eax, dword ptr [eax + 0x20]
// 0075e864  8b542404             mov edx, dword ptr [esp + 4]
// 0075e868  52                   push edx
// 0075e869  68e04e9200           push 0x924ee0
// 0075e86e  6a00                 push 0
// 0075e870  50                   push eax
// 0075e871  e81a2e0000           call 0x761690
// 0075e876  c20400               ret 4
// 0075e879  b805400080           mov eax, 0x80004005
// 0075e87e  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleParent@CXTPDockingPaneManager@@MAEJPAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
