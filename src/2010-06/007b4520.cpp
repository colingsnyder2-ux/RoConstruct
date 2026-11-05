// from server: 100% by auto
// roc 2010-06 007b4520  unit: CXTPControlComboBoxList  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b4520
//
// 007b4520  8b442408             mov eax, dword ptr [esp + 8]
// 007b4524  3d0a020000           cmp eax, 0x20a
// 007b4529  7523                 jne 0x7b454e
// 007b452b  8b442410             mov eax, dword ptr [esp + 0x10]
// 007b452f  8b10                 mov edx, dword ptr [eax]
// 007b4531  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007b4535  52                   push edx
// 007b4536  8b10                 mov edx, dword ptr [eax]
// 007b4538  52                   push edx
// 007b4539  680a020000           push 0x20a
// 007b453e  83c1ac               add ecx, -0x54
// 007b4541  e8da35ffff           call 0x7a7b20
// 007b4546  b801000000           mov eax, 1
// 007b454b  c21400               ret 0x14
// 007b454e  89442408             mov dword ptr [esp + 8], eax
// 007b4552  e9b9690000           jmp 0x7baf10
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?OnHookMessage@CXTPControlComboBoxList@@MAEHPAUHWND__@@IAAIAAJ2@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
