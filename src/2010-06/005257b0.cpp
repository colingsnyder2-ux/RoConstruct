// from server: 100% by auto
// roc 2010-06 005257b0  unit: RBX::Mesh::Level  size: 442 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005257b0
//
// 005257b0  51                   push ecx
// 005257b1  56                   push esi
// 005257b2  8bf1                 mov esi, ecx
// 005257b4  8b560c               mov edx, dword ptr [esi + 0xc]
// 005257b7  57                   push edi
// 005257b8  85d2                 test edx, edx
// 005257ba  7504                 jne 0x5257c0
// 005257bc  33c9                 xor ecx, ecx
// 005257be  eb0a                 jmp 0x5257ca
// 005257c0  8b4614               mov eax, dword ptr [esi + 0x14]
// 005257c3  2bc2                 sub eax, edx
// 005257c5  c1f802               sar eax, 2
// 005257c8  8bc8                 mov ecx, eax
// 005257ca  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005257ce  85ff                 test edi, edi
// 005257d0  0f848e010000         je 0x525964
// 005257d6  53                   push ebx
// 005257d7  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005257da  8bc3                 mov eax, ebx
// 005257dc  2bc2                 sub eax, edx
// 005257de  c1f802               sar eax, 2
// 005257e1  baffffff3f           mov edx, 0x3fffffff
// 005257e6  2bd0                 sub edx, eax
// 005257e8  3bd7                 cmp edx, edi
// 005257ea  7305                 jae 0x5257f1
// 005257ec  e8ffe5efff           call 0x423df0
// 005257f1  8d1438               lea edx, [eax + edi]
// 005257f4  55                   push ebp
// 005257f5  3bca                 cmp ecx, edx
// 005257f7  0f83b5000000         jae 0x5258b2
// 005257fd  8bc1                 mov eax, ecx
// 005257ff  d1e8                 shr eax, 1
// 00525801  bbffffff3f           mov ebx, 0x3fffffff
// 00525806  2bd8                 sub ebx, eax
// 00525808  3bd9                 cmp ebx, ecx
// 0052580a  730e                 jae 0x52581a
// 0052580c  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00525814  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00525818  eb06                 jmp 0x525820
// 0052581a  03c8                 add ecx, eax
// 0052581c  894c2410             mov dword ptr [esp + 0x10], ecx
// 00525820  3bca                 cmp ecx, edx
// 00525822  7306                 jae 0x52582a
// 00525824  89542410             mov dword ptr [esp + 0x10], edx
// 00525828  8bca                 mov ecx, edx
// 0052582a  6a00                 push 0
// 0052582c  51                   push ecx
// 0052582d  e8defa3a00           call 0x8d5310
// 00525832  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00525836  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 00525839  83c408               add esp, 8
// 0052583c  8be8                 mov ebp, eax
// 0052583e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00525842  50                   push eax
// 00525843  c1fb02               sar ebx, 2
// 00525846  57                   push edi
// 00525847  8d4c9d00             lea ecx, [ebp + ebx*4]
// 0052584b  51                   push ecx
// 0052584c  8bce                 mov ecx, esi
// 0052584e  e82dffffff           call 0x525780
// 00525853  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00525857  8b460c               mov eax, dword ptr [esi + 0xc]
// 0052585a  55                   push ebp
// 0052585b  52                   push edx
// 0052585c  50                   push eax
// 0052585d  8bce                 mov ecx, esi
// 0052585f  e8fca53b00           call 0x8dfe60
// 00525864  8b5610               mov edx, dword ptr [esi + 0x10]
// 00525867  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0052586b  03df                 add ebx, edi
// 0052586d  8d4c9d00             lea ecx, [ebp + ebx*4]
// 00525871  51                   push ecx
// 00525872  52                   push edx
// 00525873  50                   push eax
// 00525874  8bce                 mov ecx, esi
// 00525876  e8e5a53b00           call 0x8dfe60
// 0052587b  8b460c               mov eax, dword ptr [esi + 0xc]
// 0052587e  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00525881  2bc8                 sub ecx, eax
// 00525883  c1f902               sar ecx, 2
// 00525886  03f9                 add edi, ecx
// 00525888  85c0                 test eax, eax
// 0052588a  7409                 je 0x525895
// 0052588c  50                   push eax
// 0052588d  e808212800           call 0x7a799a
// 00525892  83c404               add esp, 4
// 00525895  8b542410             mov edx, dword ptr [esp + 0x10]
// 00525899  8d4cbd00             lea ecx, [ebp + edi*4]
// 0052589d  8d449500             lea eax, [ebp + edx*4]
// 005258a1  896e0c               mov dword ptr [esi + 0xc], ebp
// 005258a4  5d                   pop ebp
// 005258a5  5b                   pop ebx
// 005258a6  5f                   pop edi
// 005258a7  894614               mov dword ptr [esi + 0x14], eax
// 005258aa  894e10               mov dword ptr [esi + 0x10], ecx
// 005258ad  5e                   pop esi
// 005258ae  59                   pop ecx
// 005258af  c21000               ret 0x10
// 005258b2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005258b6  8bd3                 mov edx, ebx
// 005258b8  2bd0                 sub edx, eax
// 005258ba  c1fa02               sar edx, 2
// 005258bd  8d2cbd00000000       lea ebp, [edi*4]
// 005258c4  3bd7                 cmp edx, edi
// 005258c6  735a                 jae 0x525922
// 005258c8  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005258cc  f30f1001             movss xmm0, dword ptr [ecx]
// 005258d0  8d1428               lea edx, [eax + ebp]
// 005258d3  52                   push edx
// 005258d4  53                   push ebx
// 005258d5  50                   push eax
// 005258d6  8bce                 mov ecx, esi
// 005258d8  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 005258de  e87da53b00           call 0x8dfe60
// 005258e3  8b4610               mov eax, dword ptr [esi + 0x10]
// 005258e6  8bd0                 mov edx, eax
// 005258e8  2b54241c             sub edx, dword ptr [esp + 0x1c]
// 005258ec  8d4c2424             lea ecx, [esp + 0x24]
// 005258f0  51                   push ecx
// 005258f1  c1fa02               sar edx, 2
// 005258f4  2bfa                 sub edi, edx
// 005258f6  57                   push edi
// 005258f7  50                   push eax
// 005258f8  8bce                 mov ecx, esi
// 005258fa  e881feffff           call 0x525780
// 005258ff  016e10               add dword ptr [esi + 0x10], ebp
// 00525902  8b7610               mov esi, dword ptr [esi + 0x10]
// 00525905  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00525909  8d442424             lea eax, [esp + 0x24]
// 0052590d  50                   push eax
// 0052590e  2bf5                 sub esi, ebp
// 00525910  56                   push esi
// 00525911  51                   push ecx
// 00525912  e839e4ffff           call 0x523d50
// 00525917  83c40c               add esp, 0xc
// 0052591a  5d                   pop ebp
// 0052591b  5b                   pop ebx
// 0052591c  5f                   pop edi
// 0052591d  5e                   pop esi
// 0052591e  59                   pop ecx
// 0052591f  c21000               ret 0x10
// 00525922  8b542424             mov edx, dword ptr [esp + 0x24]
// 00525926  f30f1002             movss xmm0, dword ptr [edx]
// 0052592a  53                   push ebx
// 0052592b  8bfb                 mov edi, ebx
// 0052592d  53                   push ebx
// 0052592e  2bfd                 sub edi, ebp
// 00525930  57                   push edi
// 00525931  8bce                 mov ecx, esi
// 00525933  f30f11442430         movss dword ptr [esp + 0x30], xmm0
// 00525939  e822a53b00           call 0x8dfe60
// 0052593e  53                   push ebx
// 0052593f  894610               mov dword ptr [esi + 0x10], eax
// 00525942  8b442420             mov eax, dword ptr [esp + 0x20]
// 00525946  57                   push edi
// 00525947  50                   push eax
// 00525948  e813f6f0ff           call 0x434f60
// 0052594d  8b442428             mov eax, dword ptr [esp + 0x28]
// 00525951  8d4c2430             lea ecx, [esp + 0x30]
// 00525955  51                   push ecx
// 00525956  03e8                 add ebp, eax
// 00525958  55                   push ebp
// 00525959  50                   push eax
// 0052595a  e8f1e3ffff           call 0x523d50
// 0052595f  83c418               add esp, 0x18
// 00525962  5d                   pop ebp
// 00525963  5b                   pop ebx
// 00525964  5f                   pop edi
// 00525965  5e                   pop esi
// 00525966  59                   pop ecx
// 00525967  c21000               ret 0x10
// library rbx2016-g3d/BinaryInput.cpp (function ?_Insert_n@?$vector@MV?$allocator@M@std@@@std@@IAEXV?$_Vector_const_iterator@MV?$allocator@M@std@@@2@IABM@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
