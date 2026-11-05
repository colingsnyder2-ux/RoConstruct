// from server: 100% by auto
// roc 2010-06 007ec970  unit: CXTPDockingPaneManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ec970
//
// 007ec970  8d442404             lea eax, [esp + 4]
// 007ec974  50                   push eax
// 007ec975  e876310000           call 0x7efaf0
// 007ec97a  85c0                 test eax, eax
// 007ec97c  740d                 je 0x7ec98b
// 007ec97e  83f8ff               cmp eax, -1
// 007ec981  7408                 je 0x7ec98b
// 007ec983  b857000780           mov eax, 0x80070057
// 007ec988  c21400               ret 0x14
// 007ec98b  68c0c2a500           push 0xa5c2c0
// 007ec990  ff1580aa9e00         call dword ptr [0x9eaa80]
// 007ec996  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007ec99a  8901                 mov dword ptr [ecx], eax
// 007ec99c  33c0                 xor eax, eax
// 007ec99e  c21400               ret 0x14
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleName@CXTPDockingPaneManager@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
