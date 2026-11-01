// from server: 100% by auto
// roc 2009-12 007f97b0  unit: CXTPControlComboBoxList  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f97b0
//
// 007f97b0  8b442408             mov eax, dword ptr [esp + 8]
// 007f97b4  3d0a020000           cmp eax, 0x20a
// 007f97b9  7523                 jne 0x7f97de
// 007f97bb  8b442410             mov eax, dword ptr [esp + 0x10]
// 007f97bf  8b10                 mov edx, dword ptr [eax]
// 007f97c1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007f97c5  52                   push edx
// 007f97c6  8b10                 mov edx, dword ptr [eax]
// 007f97c8  52                   push edx
// 007f97c9  680a020000           push 0x20a
// 007f97ce  83c1ac               add ecx, -0x54
// 007f97d1  e80aa2ffff           call 0x7f39e0
// 007f97d6  b801000000           mov eax, 1
// 007f97db  c21400               ret 0x14
// 007f97de  89442408             mov dword ptr [esp + 8], eax
// 007f97e2  e9b9d50000           jmp 0x806da0
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?OnHookMessage@CXTPControlComboBoxList@@MAEHPAUHWND__@@IAAIAAJ2@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
