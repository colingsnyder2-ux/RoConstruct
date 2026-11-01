// from server: 100% by auto
// roc 2009-12 008778e0  unit: CXTPControlGallery  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008778e0
//
// 008778e0  56                   push esi
// 008778e1  8b742418             mov esi, dword ptr [esp + 0x18]
// 008778e5  8d542408             lea edx, [esp + 8]
// 008778e9  b803000000           mov eax, 3
// 008778ee  52                   push edx
// 008778ef  668906               mov word ptr [esi], ax
// 008778f2  e8a940fcff           call 0x83b9a0
// 008778f7  f7d8                 neg eax
// 008778f9  1bc0                 sbb eax, eax
// 008778fb  83c022               add eax, 0x22
// 008778fe  894608               mov dword ptr [esi + 8], eax
// 00877901  33c0                 xor eax, eax
// 00877903  5e                   pop esi
// 00877904  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?GetAccessibleRole@CXTPControlGallery@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlGallery.cpp
