// from server: 100% by auto
// roc 2010-06 00824ae0  unit: CXTPControlGallery  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00824ae0
//
// 00824ae0  56                   push esi
// 00824ae1  8b742418             mov esi, dword ptr [esp + 0x18]
// 00824ae5  8d542408             lea edx, [esp + 8]
// 00824ae9  b803000000           mov eax, 3
// 00824aee  52                   push edx
// 00824aef  668906               mov word ptr [esi], ax
// 00824af2  e8f9affcff           call 0x7efaf0
// 00824af7  f7d8                 neg eax
// 00824af9  1bc0                 sbb eax, eax
// 00824afb  83c022               add eax, 0x22
// 00824afe  894608               mov dword ptr [esi + 8], eax
// 00824b01  33c0                 xor eax, eax
// 00824b03  5e                   pop esi
// 00824b04  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?GetAccessibleRole@CXTPControlGallery@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlGallery.cpp
