// from server: 100% by auto
// roc 2007-03 0065a1f0  unit: seg_00650000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065a1f0
//
// 0065a1f0  8d442404             lea eax, [esp + 4]
// 0065a1f4  50                   push eax
// 0065a1f5  e8b6bd0200           call 0x685fb0
// 0065a1fa  85c0                 test eax, eax
// 0065a1fc  740d                 je 0x65a20b
// 0065a1fe  83f8ff               cmp eax, -1
// 0065a201  7408                 je 0x65a20b
// 0065a203  b857000780           mov eax, 0x80070057
// 0065a208  c21400               ret 0x14
// 0065a20b  6870837c00           push 0x7c8370
// 0065a210  ff15ccea7700         call dword ptr [0x77eacc]
// 0065a216  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0065a21a  8901                 mov dword ptr [ecx], eax
// 0065a21c  33c0                 xor eax, eax
// 0065a21e  c21400               ret 0x14
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleName@CXTPDockingPaneManager@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
