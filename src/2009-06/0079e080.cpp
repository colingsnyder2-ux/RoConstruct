// from server: 100% by auto
// roc 2009-06 0079e080  unit: CXTPControlGalleryPaintManager  size: 302 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079e080
//
// 0079e080  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0079e084  8b442410             mov eax, dword ptr [esp + 0x10]
// 0079e088  83ec08               sub esp, 8
// 0079e08b  53                   push ebx
// 0079e08c  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0079e090  56                   push esi
// 0079e091  57                   push edi
// 0079e092  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0079e096  2bc3                 sub eax, ebx
// 0079e098  2bcf                 sub ecx, edi
// 0079e09a  3bc1                 cmp eax, ecx
// 0079e09c  8bf0                 mov esi, eax
// 0079e09e  7c02                 jl 0x79e0a2
// 0079e0a0  8bf1                 mov esi, ecx
// 0079e0a2  83fe06               cmp esi, 6
// 0079e0a5  0f8cfc000000         jl 0x79e1a7
// 0079e0ab  2bc6                 sub eax, esi
// 0079e0ad  99                   cdq 
// 0079e0ae  2bc2                 sub eax, edx
// 0079e0b0  d1f8                 sar eax, 1
// 0079e0b2  55                   push ebp
// 0079e0b3  8d6c1802             lea ebp, [eax + ebx + 2]
// 0079e0b7  8bc1                 mov eax, ecx
// 0079e0b9  2bc6                 sub eax, esi
// 0079e0bb  99                   cdq 
// 0079e0bc  2bc2                 sub eax, edx
// 0079e0be  d1f8                 sar eax, 1
// 0079e0c0  8d443802             lea eax, [eax + edi + 2]
// 0079e0c4  83ee04               sub esi, 4
// 0079e0c7  837c243800           cmp dword ptr [esp + 0x38], 0
// 0079e0cc  89442410             mov dword ptr [esp + 0x10], eax
// 0079e0d0  7404                 je 0x79e0d6
// 0079e0d2  33ff                 xor edi, edi
// 0079e0d4  eb0a                 jmp 0x79e0e0
// 0079e0d6  6a10                 push 0x10
// 0079e0d8  ff15e4ee8900         call dword ptr [0x89eee4]
// 0079e0de  8bf8                 mov edi, eax
// 0079e0e0  6894199000           push 0x901994
// 0079e0e5  6a00                 push 0
// 0079e0e7  6a00                 push 0
// 0079e0e9  6a00                 push 0
// 0079e0eb  6a00                 push 0
// 0079e0ed  6a02                 push 2
// 0079e0ef  6a00                 push 0
// 0079e0f1  6a00                 push 0
// 0079e0f3  6a00                 push 0
// 0079e0f5  6890010000           push 0x190
// 0079e0fa  6a00                 push 0
// 0079e0fc  6a00                 push 0
// 0079e0fe  6a00                 push 0
// 0079e100  56                   push esi
// 0079e101  ff1530e18900         call dword ptr [0x89e130]
// 0079e107  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0079e10b  8bd8                 mov ebx, eax
// 0079e10d  85f6                 test esi, esi
// 0079e10f  7504                 jne 0x79e115
// 0079e111  33c0                 xor eax, eax
// 0079e113  eb03                 jmp 0x79e118
// 0079e115  8b4604               mov eax, dword ptr [esi + 4]
// 0079e118  53                   push ebx
// 0079e119  50                   push eax
// 0079e11a  ff1524e18900         call dword ptr [0x89e124]
// 0079e120  89442414             mov dword ptr [esp + 0x14], eax
// 0079e124  85f6                 test esi, esi
// 0079e126  7504                 jne 0x79e12c
// 0079e128  33c0                 xor eax, eax
// 0079e12a  eb03                 jmp 0x79e12f
// 0079e12c  8b4604               mov eax, dword ptr [esi + 4]
// 0079e12f  57                   push edi
// 0079e130  50                   push eax
// 0079e131  ff15bce08900         call dword ptr [0x89e0bc]
// 0079e137  6a01                 push 1
// 0079e139  8bce                 mov ecx, esi
// 0079e13b  e8c6dd0a00           call 0x84bf06
// 0079e140  837c243000           cmp dword ptr [esp + 0x30], 0
// 0079e145  7415                 je 0x79e15c
// 0079e147  837c243400           cmp dword ptr [esp + 0x34], 0
// 0079e14c  7407                 je 0x79e155
// 0079e14e  b990199000           mov ecx, 0x901990
// 0079e153  eb18                 jmp 0x79e16d
// 0079e155  b9b8638b00           mov ecx, 0x8b63b8
// 0079e15a  eb11                 jmp 0x79e16d
// 0079e15c  837c243400           cmp dword ptr [esp + 0x34], 0
// 0079e161  b98c199000           mov ecx, 0x90198c
// 0079e166  7505                 jne 0x79e16d
// 0079e168  b988199000           mov ecx, 0x901988
// 0079e16d  85f6                 test esi, esi
// 0079e16f  7504                 jne 0x79e175
// 0079e171  33c0                 xor eax, eax
// 0079e173  eb03                 jmp 0x79e178
// 0079e175  8b4604               mov eax, dword ptr [esi + 4]
// 0079e178  6a01                 push 1
// 0079e17a  51                   push ecx
// 0079e17b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0079e17f  51                   push ecx
// 0079e180  55                   push ebp
// 0079e181  50                   push eax
// 0079e182  ff15a8e08900         call dword ptr [0x89e0a8]
// 0079e188  5d                   pop ebp
// 0079e189  85f6                 test esi, esi
// 0079e18b  7504                 jne 0x79e191
// 0079e18d  33f6                 xor esi, esi
// 0079e18f  eb03                 jmp 0x79e194
// 0079e191  8b7604               mov esi, dword ptr [esi + 4]
// 0079e194  8b542410             mov edx, dword ptr [esp + 0x10]
// 0079e198  52                   push edx
// 0079e199  56                   push esi
// 0079e19a  ff1524e18900         call dword ptr [0x89e124]
// 0079e1a0  53                   push ebx
// 0079e1a1  ff1560e18900         call dword ptr [0x89e160]
// 0079e1a7  5f                   pop edi
// 0079e1a8  5e                   pop esi
// 0079e1a9  5b                   pop ebx
// 0079e1aa  83c408               add esp, 8
// 0079e1ad  c3                   ret 
// library xtp-15.2.1/Source\Controls\Scroll\XTPScrollBar.cpp (function ?DrawArrowGlyph@@YAXPAVCDC@@VCRect@@HHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Scroll/XTPScrollBar.cpp
