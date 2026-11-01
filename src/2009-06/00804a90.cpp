// from server: 100% by auto
// roc 2009-06 00804a90  unit: CXTColorPageCustom  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00804a90
//
// 00804a90  56                   push esi
// 00804a91  6a01                 push 1
// 00804a93  8bf1                 mov esi, ecx
// 00804a95  e82642f1ff           call 0x718cc0
// 00804a9a  0fb6866c070000       movzx eax, byte ptr [esi + 0x76c]
// 00804aa1  0fb68e70070000       movzx ecx, byte ptr [esi + 0x770]
// 00804aa8  0fb69668070000       movzx edx, byte ptr [esi + 0x768]
// 00804aaf  c1e008               shl eax, 8
// 00804ab2  0bc1                 or eax, ecx
// 00804ab4  c1e008               shl eax, 8
// 00804ab7  6a00                 push 0
// 00804ab9  0bc2                 or eax, edx
// 00804abb  50                   push eax
// 00804abc  8bce                 mov ecx, esi
// 00804abe  e81dfaffff           call 0x8044e0
// 00804ac3  5e                   pop esi
// 00804ac4  c3                   ret 
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnChangeEdit@CXTPColorPageCustom@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
