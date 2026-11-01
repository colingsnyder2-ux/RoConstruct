// from server: 100% by auto
// roc 2009-12 007f6370  unit: CPatchedControlComboBox  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f6370
//
// 007f6370  8d442404             lea eax, [esp + 4]
// 007f6374  50                   push eax
// 007f6375  e826560400           call 0x83b9a0
// 007f637a  85c0                 test eax, eax
// 007f637c  7408                 je 0x7f6386
// 007f637e  b857000780           mov eax, 0x80070057
// 007f6383  c21400               ret 0x14
// 007f6386  68b8179f00           push 0x9f17b8
// 007f638b  ff1550ba9800         call dword ptr [0x98ba50]
// 007f6391  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007f6395  8901                 mov dword ptr [ecx], eax
// 007f6397  33c0                 xor eax, eax
// 007f6399  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?GetAccessibleDefaultAction@CXTPControl@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
