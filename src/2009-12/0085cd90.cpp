// from server: 100% by auto
// roc 2009-12 0085cd90  unit: CXTPDockingPane  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085cd90
//
// 0085cd90  8d442404             lea eax, [esp + 4]
// 0085cd94  50                   push eax
// 0085cd95  e806ecfdff           call 0x83b9a0
// 0085cd9a  85c0                 test eax, eax
// 0085cd9c  7408                 je 0x85cda6
// 0085cd9e  b857000780           mov eax, 0x80070057
// 0085cda3  c21400               ret 0x14
// 0085cda6  68d4d79f00           push 0x9fd7d4
// 0085cdab  ff1550ba9800         call dword ptr [0x98ba50]
// 0085cdb1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0085cdb5  8901                 mov dword ptr [ecx], eax
// 0085cdb7  33c0                 xor eax, eax
// 0085cdb9  c21400               ret 0x14
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?GetAccessibleDefaultAction@CXTPDockingPane@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
