// from server: 100% by auto
// roc 2009-06 0075d9f0  unit: CXTPDockingPaneManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075d9f0
//
// 0075d9f0  8d442404             lea eax, [esp + 4]
// 0075d9f4  50                   push eax
// 0075d9f5  e8d6310000           call 0x760bd0
// 0075d9fa  85c0                 test eax, eax
// 0075d9fc  740d                 je 0x75da0b
// 0075d9fe  83f8ff               cmp eax, -1
// 0075da01  7408                 je 0x75da0b
// 0075da03  b857000780           mov eax, 0x80070057
// 0075da08  c21400               ret 0x14
// 0075da0b  68587b8f00           push 0x8f7b58
// 0075da10  ff15d8e98900         call dword ptr [0x89e9d8]
// 0075da16  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0075da1a  8901                 mov dword ptr [ecx], eax
// 0075da1c  33c0                 xor eax, eax
// 0075da1e  c21400               ret 0x14
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleName@CXTPDockingPaneManager@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
