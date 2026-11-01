// from server: 100% by auto
// roc 2009-06 0071b5d0  unit: CXTPControlComboBoxList  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071b5d0
//
// 0071b5d0  8b442408             mov eax, dword ptr [esp + 8]
// 0071b5d4  3d0a020000           cmp eax, 0x20a
// 0071b5d9  7523                 jne 0x71b5fe
// 0071b5db  8b442410             mov eax, dword ptr [esp + 0x10]
// 0071b5df  8b10                 mov edx, dword ptr [eax]
// 0071b5e1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0071b5e5  52                   push edx
// 0071b5e6  8b10                 mov edx, dword ptr [eax]
// 0071b5e8  52                   push edx
// 0071b5e9  680a020000           push 0x20a
// 0071b5ee  83c1ac               add ecx, -0x54
// 0071b5f1  e8c2d5ffff           call 0x718bb8
// 0071b5f6  b801000000           mov eax, 1
// 0071b5fb  c21400               ret 0x14
// 0071b5fe  89442408             mov dword ptr [esp + 8], eax
// 0071b602  e939460100           jmp 0x72fc40
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?OnHookMessage@CXTPControlComboBoxList@@MAEHPAUHWND__@@IAAIAAJ2@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
