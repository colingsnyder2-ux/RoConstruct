// from server: 100% by auto
// roc 2009-12 00864ba0  unit: CPropertyGridItemBrickColor  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00864ba0
//
// 00864ba0  56                   push esi
// 00864ba1  8b742418             mov esi, dword ptr [esp + 0x18]
// 00864ba5  85f6                 test esi, esi
// 00864ba7  7428                 je 0x864bd1
// 00864ba9  8d542408             lea edx, [esp + 8]
// 00864bad  33c0                 xor eax, eax
// 00864baf  52                   push edx
// 00864bb0  668906               mov word ptr [esi], ax
// 00864bb3  e8e86dfdff           call 0x83b9a0
// 00864bb8  85c0                 test eax, eax
// 00864bba  7515                 jne 0x864bd1
// 00864bbc  b803000000           mov eax, 3
// 00864bc1  668906               mov word ptr [esi], ax
// 00864bc4  c746081c000000       mov dword ptr [esi + 8], 0x1c
// 00864bcb  33c0                 xor eax, eax
// 00864bcd  5e                   pop esi
// 00864bce  c21400               ret 0x14
// 00864bd1  b857000780           mov eax, 0x80070057
// 00864bd6  5e                   pop esi
// 00864bd7  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?GetAccessibleRole@CXTPPropertyGridItem@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
