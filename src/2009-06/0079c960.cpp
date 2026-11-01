// from server: 100% by auto
// roc 2009-06 0079c960  unit: CXTPControlGallery  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079c960
//
// 0079c960  56                   push esi
// 0079c961  8b742418             mov esi, dword ptr [esp + 0x18]
// 0079c965  8d542408             lea edx, [esp + 8]
// 0079c969  b803000000           mov eax, 3
// 0079c96e  52                   push edx
// 0079c96f  668906               mov word ptr [esi], ax
// 0079c972  e85942fcff           call 0x760bd0
// 0079c977  f7d8                 neg eax
// 0079c979  1bc0                 sbb eax, eax
// 0079c97b  83c022               add eax, 0x22
// 0079c97e  894608               mov dword ptr [esi + 8], eax
// 0079c981  33c0                 xor eax, eax
// 0079c983  5e                   pop esi
// 0079c984  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?GetAccessibleRole@CXTPControlGallery@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlGallery.cpp
