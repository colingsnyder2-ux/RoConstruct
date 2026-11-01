// from server: 100% by auto
// roc 2009-12 008f07d0  unit: CXTPRibbonControlTab  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f07d0
//
// 008f07d0  56                   push esi
// 008f07d1  8b742418             mov esi, dword ptr [esp + 0x18]
// 008f07d5  8d542408             lea edx, [esp + 8]
// 008f07d9  b803000000           mov eax, 3
// 008f07de  52                   push edx
// 008f07df  668906               mov word ptr [esi], ax
// 008f07e2  e8b9b1f4ff           call 0x83b9a0
// 008f07e7  f7d8                 neg eax
// 008f07e9  1bc0                 sbb eax, eax
// 008f07eb  83e0e9               and eax, 0xffffffe9
// 008f07ee  83c03c               add eax, 0x3c
// 008f07f1  894608               mov dword ptr [esi + 8], eax
// 008f07f4  33c0                 xor eax, eax
// 008f07f6  5e                   pop esi
// 008f07f7  c21400               ret 0x14
// library xtp-15.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?GetAccessibleRole@CXTPRibbonControlTab@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
