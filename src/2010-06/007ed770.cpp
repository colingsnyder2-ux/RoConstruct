// from server: 100% by auto
// roc 2010-06 007ed770  unit: CXTPDockingPaneManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ed770
//
// 007ed770  8d41ac               lea eax, [ecx - 0x54]
// 007ed773  85c0                 test eax, eax
// 007ed775  7422                 je 0x7ed799
// 007ed777  83782000             cmp dword ptr [eax + 0x20], 0
// 007ed77b  741c                 je 0x7ed799
// 007ed77d  85c0                 test eax, eax
// 007ed77f  7403                 je 0x7ed784
// 007ed781  8b4020               mov eax, dword ptr [eax + 0x20]
// 007ed784  8b542404             mov edx, dword ptr [esp + 4]
// 007ed788  52                   push edx
// 007ed789  6820cba800           push 0xa8cb20
// 007ed78e  6a00                 push 0
// 007ed790  50                   push eax
// 007ed791  e82a2e0000           call 0x7f05c0
// 007ed796  c20400               ret 4
// 007ed799  b805400080           mov eax, 0x80004005
// 007ed79e  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleParent@CXTPDockingPaneManager@@MAEJPAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
