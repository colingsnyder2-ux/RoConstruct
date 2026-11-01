// from server: 100% by auto
// roc 2009-12 00869bf0  unit: CXTPPropertyGridView  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00869bf0
//
// 00869bf0  56                   push esi
// 00869bf1  8b742408             mov esi, dword ptr [esp + 8]
// 00869bf5  85f6                 test esi, esi
// 00869bf7  7509                 jne 0x869c02
// 00869bf9  b857000780           mov eax, 0x80070057
// 00869bfe  5e                   pop esi
// 00869bff  c20400               ret 4
// 00869c02  8b41cc               mov eax, dword ptr [ecx - 0x34]
// 00869c05  6a00                 push 0
// 00869c07  6a00                 push 0
// 00869c09  688b010000           push 0x18b
// 00869c0e  50                   push eax
// 00869c0f  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00869c15  8906                 mov dword ptr [esi], eax
// 00869c17  33c0                 xor eax, eax
// 00869c19  5e                   pop esi
// 00869c1a  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleChildCount@CXTPPropertyGridView@@MAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
