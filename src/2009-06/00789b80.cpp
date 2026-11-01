// from server: 100% by auto
// roc 2009-06 00789b80  unit: CPropertyGridItemBrickColor  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00789b80
//
// 00789b80  56                   push esi
// 00789b81  8b742418             mov esi, dword ptr [esp + 0x18]
// 00789b85  85f6                 test esi, esi
// 00789b87  7428                 je 0x789bb1
// 00789b89  8d542408             lea edx, [esp + 8]
// 00789b8d  33c0                 xor eax, eax
// 00789b8f  52                   push edx
// 00789b90  668906               mov word ptr [esi], ax
// 00789b93  e83870fdff           call 0x760bd0
// 00789b98  85c0                 test eax, eax
// 00789b9a  7515                 jne 0x789bb1
// 00789b9c  b803000000           mov eax, 3
// 00789ba1  668906               mov word ptr [esi], ax
// 00789ba4  c746081c000000       mov dword ptr [esi + 8], 0x1c
// 00789bab  33c0                 xor eax, eax
// 00789bad  5e                   pop esi
// 00789bae  c21400               ret 0x14
// 00789bb1  b857000780           mov eax, 0x80070057
// 00789bb6  5e                   pop esi
// 00789bb7  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItem.cpp (function ?GetAccessibleRole@CXTPPropertyGridItem@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItem.cpp
