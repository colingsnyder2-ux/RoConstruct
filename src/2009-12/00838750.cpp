// from server: 100% by auto
// roc 2009-12 00838750  unit: CXTPDockingPaneManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00838750
//
// 00838750  8d442404             lea eax, [esp + 4]
// 00838754  50                   push eax
// 00838755  e846320000           call 0x83b9a0
// 0083875a  85c0                 test eax, eax
// 0083875c  740d                 je 0x83876b
// 0083875e  83f8ff               cmp eax, -1
// 00838761  7408                 je 0x83876b
// 00838763  b857000780           mov eax, 0x80070057
// 00838768  c21400               ret 0x14
// 0083876b  6800809f00           push 0x9f8000
// 00838770  ff1550ba9800         call dword ptr [0x98ba50]
// 00838776  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0083877a  8901                 mov dword ptr [ecx], eax
// 0083877c  33c0                 xor eax, eax
// 0083877e  c21400               ret 0x14
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleName@CXTPDockingPaneManager@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
