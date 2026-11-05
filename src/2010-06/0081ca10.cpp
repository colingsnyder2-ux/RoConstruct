// from server: 100% by auto
// roc 2010-06 0081ca10  unit: CXTPPropertyGridView  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081ca10
//
// 0081ca10  53                   push ebx
// 0081ca11  56                   push esi
// 0081ca12  57                   push edi
// 0081ca13  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0081ca17  8bf1                 mov esi, ecx
// 0081ca19  85ff                 test edi, edi
// 0081ca1b  7c36                 jl 0x81ca53
// 0081ca1d  8b4620               mov eax, dword ptr [esi + 0x20]
// 0081ca20  8b1d54ba9e00         mov ebx, dword ptr [0x9eba54]
// 0081ca26  6a00                 push 0
// 0081ca28  6a00                 push 0
// 0081ca2a  688b010000           push 0x18b
// 0081ca2f  50                   push eax
// 0081ca30  ffd3                 call ebx
// 0081ca32  3bf8                 cmp edi, eax
// 0081ca34  7d1d                 jge 0x81ca53
// 0081ca36  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0081ca39  6a00                 push 0
// 0081ca3b  57                   push edi
// 0081ca3c  6899010000           push 0x199
// 0081ca41  51                   push ecx
// 0081ca42  ffd3                 call ebx
// 0081ca44  8bc8                 mov ecx, eax
// 0081ca46  40                   inc eax
// 0081ca47  f7d8                 neg eax
// 0081ca49  5f                   pop edi
// 0081ca4a  1bc0                 sbb eax, eax
// 0081ca4c  5e                   pop esi
// 0081ca4d  23c1                 and eax, ecx
// 0081ca4f  5b                   pop ebx
// 0081ca50  c20400               ret 4
// 0081ca53  5f                   pop edi
// 0081ca54  5e                   pop esi
// 0081ca55  33c0                 xor eax, eax
// 0081ca57  5b                   pop ebx
// 0081ca58  c20400               ret 4
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetItem@CXTPPropertyGridView@@QBEPAVCXTPPropertyGridItem@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
