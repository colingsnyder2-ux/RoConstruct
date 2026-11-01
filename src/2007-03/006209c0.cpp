// from server: 100% by auto
// roc 2007-03 006209c0  unit: seg_00620000  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006209c0
//
// 006209c0  8b442408             mov eax, dword ptr [esp + 8]
// 006209c4  3d0a020000           cmp eax, 0x20a
// 006209c9  7523                 jne 0x6209ee
// 006209cb  8b442410             mov eax, dword ptr [esp + 0x10]
// 006209cf  8b10                 mov edx, dword ptr [eax]
// 006209d1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006209d5  52                   push edx
// 006209d6  8b10                 mov edx, dword ptr [eax]
// 006209d8  52                   push edx
// 006209d9  680a020000           push 0x20a
// 006209de  83c1ac               add ecx, -0x54
// 006209e1  e890d8ffff           call 0x61e276
// 006209e6  b801000000           mov eax, 1
// 006209eb  c21400               ret 0x14
// 006209ee  89442408             mov dword ptr [esp + 8], eax
// 006209f2  e9d9ab0100           jmp 0x63b5d0
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?OnHookMessage@CXTPControlComboBoxList@@MAEHPAUHWND__@@IAAIAAJ2@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
