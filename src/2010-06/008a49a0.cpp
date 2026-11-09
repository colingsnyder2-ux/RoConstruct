// from server: 100% by auto
// roc 2010-06 008a49a0  unit: CXTPRibbonControlTab  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a49a0
//
// 008a49a0  56                   push esi
// 008a49a1  8b742418             mov esi, dword ptr [esp + 0x18]
// 008a49a5  8d542408             lea edx, [esp + 8]
// 008a49a9  b803000000           mov eax, 3
// 008a49ae  52                   push edx
// 008a49af  668906               mov word ptr [esi], ax
// 008a49b2  e839b1f4ff           call 0x7efaf0
// 008a49b7  f7d8                 neg eax
// 008a49b9  1bc0                 sbb eax, eax
// 008a49bb  83e0e9               and eax, 0xffffffe9
// 008a49be  83c03c               add eax, 0x3c
// 008a49c1  894608               mov dword ptr [esi + 8], eax
// 008a49c4  33c0                 xor eax, eax
// 008a49c6  5e                   pop esi
// 008a49c7  c21400               ret 0x14
// library xtp-13.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?GetAccessibleRole@CXTPRibbonControlTab@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
