// from server: 100% by auto
// roc 2009-12 00868a00  unit: CXTPPropertyGridView  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00868a00
//
// 00868a00  53                   push ebx
// 00868a01  56                   push esi
// 00868a02  57                   push edi
// 00868a03  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00868a07  8bf1                 mov esi, ecx
// 00868a09  85ff                 test edi, edi
// 00868a0b  7c36                 jl 0x868a43
// 00868a0d  8b4620               mov eax, dword ptr [esi + 0x20]
// 00868a10  8b1dc4cb9800         mov ebx, dword ptr [0x98cbc4]
// 00868a16  6a00                 push 0
// 00868a18  6a00                 push 0
// 00868a1a  688b010000           push 0x18b
// 00868a1f  50                   push eax
// 00868a20  ffd3                 call ebx
// 00868a22  3bf8                 cmp edi, eax
// 00868a24  7d1d                 jge 0x868a43
// 00868a26  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00868a29  6a00                 push 0
// 00868a2b  57                   push edi
// 00868a2c  6899010000           push 0x199
// 00868a31  51                   push ecx
// 00868a32  ffd3                 call ebx
// 00868a34  8bc8                 mov ecx, eax
// 00868a36  40                   inc eax
// 00868a37  f7d8                 neg eax
// 00868a39  5f                   pop edi
// 00868a3a  1bc0                 sbb eax, eax
// 00868a3c  5e                   pop esi
// 00868a3d  23c1                 and eax, ecx
// 00868a3f  5b                   pop ebx
// 00868a40  c20400               ret 4
// 00868a43  5f                   pop edi
// 00868a44  5e                   pop esi
// 00868a45  33c0                 xor eax, eax
// 00868a47  5b                   pop ebx
// 00868a48  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetItem@CXTPPropertyGridView@@QBEPAVCXTPPropertyGridItem@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
