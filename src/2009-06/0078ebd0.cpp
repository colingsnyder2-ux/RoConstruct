// from server: 100% by auto
// roc 2009-06 0078ebd0  unit: CXTPPropertyGridView  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078ebd0
//
// 0078ebd0  56                   push esi
// 0078ebd1  8b742408             mov esi, dword ptr [esp + 8]
// 0078ebd5  85f6                 test esi, esi
// 0078ebd7  7509                 jne 0x78ebe2
// 0078ebd9  b857000780           mov eax, 0x80070057
// 0078ebde  5e                   pop esi
// 0078ebdf  c20400               ret 4
// 0078ebe2  8b41cc               mov eax, dword ptr [ecx - 0x34]
// 0078ebe5  6a00                 push 0
// 0078ebe7  6a00                 push 0
// 0078ebe9  688b010000           push 0x18b
// 0078ebee  50                   push eax
// 0078ebef  ff1590ee8900         call dword ptr [0x89ee90]
// 0078ebf5  8906                 mov dword ptr [esi], eax
// 0078ebf7  33c0                 xor eax, eax
// 0078ebf9  5e                   pop esi
// 0078ebfa  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleChildCount@CXTPPropertyGridView@@MAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
