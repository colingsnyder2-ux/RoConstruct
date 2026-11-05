// from server: 100% by auto
// roc 2010-06 00818b50  unit: CPropertyGridItemBrickColor  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00818b50
//
// 00818b50  56                   push esi
// 00818b51  8b742418             mov esi, dword ptr [esp + 0x18]
// 00818b55  85f6                 test esi, esi
// 00818b57  7428                 je 0x818b81
// 00818b59  8d542408             lea edx, [esp + 8]
// 00818b5d  33c0                 xor eax, eax
// 00818b5f  52                   push edx
// 00818b60  668906               mov word ptr [esi], ax
// 00818b63  e8886ffdff           call 0x7efaf0
// 00818b68  85c0                 test eax, eax
// 00818b6a  7515                 jne 0x818b81
// 00818b6c  b803000000           mov eax, 3
// 00818b71  668906               mov word ptr [esi], ax
// 00818b74  c746081c000000       mov dword ptr [esi + 8], 0x1c
// 00818b7b  33c0                 xor eax, eax
// 00818b7d  5e                   pop esi
// 00818b7e  c21400               ret 0x14
// 00818b81  b857000780           mov eax, 0x80070057
// 00818b86  5e                   pop esi
// 00818b87  c21400               ret 0x14
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?GetAccessibleRole@CXTPPropertyGridItem@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
