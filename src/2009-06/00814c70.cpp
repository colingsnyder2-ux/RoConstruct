// from server: 100% by auto
// roc 2009-06 00814c70  unit: CXTPRibbonControlTab  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00814c70
//
// 00814c70  56                   push esi
// 00814c71  8b742418             mov esi, dword ptr [esp + 0x18]
// 00814c75  8d542408             lea edx, [esp + 8]
// 00814c79  b803000000           mov eax, 3
// 00814c7e  52                   push edx
// 00814c7f  668906               mov word ptr [esi], ax
// 00814c82  e849bff4ff           call 0x760bd0
// 00814c87  f7d8                 neg eax
// 00814c89  1bc0                 sbb eax, eax
// 00814c8b  83e0e9               and eax, 0xffffffe9
// 00814c8e  83c03c               add eax, 0x3c
// 00814c91  894608               mov dword ptr [esi + 8], eax
// 00814c94  33c0                 xor eax, eax
// 00814c96  5e                   pop esi
// 00814c97  c21400               ret 0x14
// library xtp-15.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?GetAccessibleRole@CXTPRibbonControlTab@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
