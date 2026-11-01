// from server: 100% by auto
// roc 2007-03 00688db0  unit: seg_00680000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00688db0
//
// 00688db0  56                   push esi
// 00688db1  8b742408             mov esi, dword ptr [esp + 8]
// 00688db5  85f6                 test esi, esi
// 00688db7  7509                 jne 0x688dc2
// 00688db9  b857000780           mov eax, 0x80070057
// 00688dbe  5e                   pop esi
// 00688dbf  c20400               ret 4
// 00688dc2  8b41cc               mov eax, dword ptr [ecx - 0x34]
// 00688dc5  6a00                 push 0
// 00688dc7  6a00                 push 0
// 00688dc9  688b010000           push 0x18b
// 00688dce  50                   push eax
// 00688dcf  ff1550ee7700         call dword ptr [0x77ee50]
// 00688dd5  8906                 mov dword ptr [esi], eax
// 00688dd7  33c0                 xor eax, eax
// 00688dd9  5e                   pop esi
// 00688dda  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleChildCount@CXTPPropertyGridView@@MAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
