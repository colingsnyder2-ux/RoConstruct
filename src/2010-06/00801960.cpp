// from server: 100% by auto
// roc 2010-06 00801960  unit: CXTPPrintingDialog  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00801960
//
// 00801960  56                   push esi
// 00801961  8bf1                 mov esi, ecx
// 00801963  68c0178000           push 0x8017c0
// 00801968  b9985dc200           mov ecx, 0xc25d98
// 0080196d  e85eb91700           call 0x97d2d0
// 00801972  85c0                 test eax, eax
// 00801974  7505                 jne 0x80197b
// 00801976  e8d162faff           call 0x7a7c4c
// 0080197b  8bce                 mov ecx, esi
// 0080197d  c7400401000000       mov dword ptr [eax + 4], 1
// 00801984  5e                   pop esi
// 00801985  e9f061faff           jmp 0x7a7b7a
// library mfc-9.0/atlmfc\src\mfc\viewprnt.cpp (function ?OnCancel@CPrintingDialog@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewprnt.cpp
