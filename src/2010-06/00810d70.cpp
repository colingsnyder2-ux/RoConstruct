// from server: 100% by auto
// roc 2010-06 00810d70  unit: CXTPDockingPane  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00810d70
//
// 00810d70  8d442404             lea eax, [esp + 4]
// 00810d74  50                   push eax
// 00810d75  e876edfdff           call 0x7efaf0
// 00810d7a  85c0                 test eax, eax
// 00810d7c  7408                 je 0x810d86
// 00810d7e  b857000780           mov eax, 0x80070057
// 00810d83  c21400               ret 0x14
// 00810d86  68941aa600           push 0xa61a94
// 00810d8b  ff1580aa9e00         call dword ptr [0x9eaa80]
// 00810d91  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00810d95  8901                 mov dword ptr [ecx], eax
// 00810d97  33c0                 xor eax, eax
// 00810d99  c21400               ret 0x14
// library xtp-13.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?GetAccessibleDefaultAction@CXTPDockingPane@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPane.cpp
