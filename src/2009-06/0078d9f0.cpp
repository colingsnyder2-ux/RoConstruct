// from server: 100% by auto
// roc 2009-06 0078d9f0  unit: CXTPPropertyGridView  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078d9f0
//
// 0078d9f0  53                   push ebx
// 0078d9f1  56                   push esi
// 0078d9f2  57                   push edi
// 0078d9f3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0078d9f7  8bf1                 mov esi, ecx
// 0078d9f9  85ff                 test edi, edi
// 0078d9fb  7c36                 jl 0x78da33
// 0078d9fd  8b4620               mov eax, dword ptr [esi + 0x20]
// 0078da00  8b1d90ee8900         mov ebx, dword ptr [0x89ee90]
// 0078da06  6a00                 push 0
// 0078da08  6a00                 push 0
// 0078da0a  688b010000           push 0x18b
// 0078da0f  50                   push eax
// 0078da10  ffd3                 call ebx
// 0078da12  3bf8                 cmp edi, eax
// 0078da14  7d1d                 jge 0x78da33
// 0078da16  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0078da19  6a00                 push 0
// 0078da1b  57                   push edi
// 0078da1c  6899010000           push 0x199
// 0078da21  51                   push ecx
// 0078da22  ffd3                 call ebx
// 0078da24  8bc8                 mov ecx, eax
// 0078da26  40                   inc eax
// 0078da27  f7d8                 neg eax
// 0078da29  5f                   pop edi
// 0078da2a  1bc0                 sbb eax, eax
// 0078da2c  5e                   pop esi
// 0078da2d  23c1                 and eax, ecx
// 0078da2f  5b                   pop ebx
// 0078da30  c20400               ret 4
// 0078da33  5f                   pop edi
// 0078da34  5e                   pop esi
// 0078da35  33c0                 xor eax, eax
// 0078da37  5b                   pop ebx
// 0078da38  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetItem@CXTPPropertyGridView@@QBEPAVCXTPPropertyGridItem@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
