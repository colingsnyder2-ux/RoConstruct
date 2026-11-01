// from server: 100% by auto
// roc 2007-03 00679320  unit: seg_00670000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00679320
//
// 00679320  8d442404             lea eax, [esp + 4]
// 00679324  50                   push eax
// 00679325  e886cc0000           call 0x685fb0
// 0067932a  85c0                 test eax, eax
// 0067932c  7408                 je 0x679336
// 0067932e  b857000780           mov eax, 0x80070057
// 00679333  c21400               ret 0x14
// 00679336  68b4d17c00           push 0x7cd1b4
// 0067933b  ff15ccea7700         call dword ptr [0x77eacc]
// 00679341  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00679345  8901                 mov dword ptr [ecx], eax
// 00679347  33c0                 xor eax, eax
// 00679349  c21400               ret 0x14
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?GetAccessibleDefaultAction@CXTPDockingPane@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
