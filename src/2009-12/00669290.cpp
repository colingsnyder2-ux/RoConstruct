// from server: 100% by auto
// roc 2009-12 00669290  unit: RBX::VInstance::?$NonFactoryProduct  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00669290
//
// 00669290  53                   push ebx
// 00669291  56                   push esi
// 00669292  8bf1                 mov esi, ecx
// 00669294  33db                 xor ebx, ebx
// 00669296  57                   push edi
// 00669297  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0066929a  746c                 je 0x669308
// 0066929c  8d642400             lea esp, [esp]
// 006692a0  8b461c               mov eax, dword ptr [esi + 0x1c]
// 006692a3  3bc3                 cmp eax, ebx
// 006692a5  745c                 je 0x669303
// 006692a7  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006692aa  8b5614               mov edx, dword ptr [esi + 0x14]
// 006692ad  8d4408ff             lea eax, [eax + ecx - 1]
// 006692b1  8bc8                 mov ecx, eax
// 006692b3  d1e9                 shr ecx, 1
// 006692b5  3bd1                 cmp edx, ecx
// 006692b7  7702                 ja 0x6692bb
// 006692b9  2bca                 sub ecx, edx
// 006692bb  8b5610               mov edx, dword ptr [esi + 0x10]
// 006692be  8b0c8a               mov ecx, dword ptr [edx + ecx*4]
// 006692c1  83e001               and eax, 1
// 006692c4  8b7cc104             mov edi, dword ptr [ecx + eax*8 + 4]
// 006692c8  8d44c104             lea eax, [ecx + eax*8 + 4]
// 006692cc  3bfb                 cmp edi, ebx
// 006692ce  742a                 je 0x6692fa
// 006692d0  8d5704               lea edx, [edi + 4]
// 006692d3  83c8ff               or eax, 0xffffffff
// 006692d6  f00fc102             lock xadd dword ptr [edx], eax
// 006692da  751e                 jne 0x6692fa
// 006692dc  8b17                 mov edx, dword ptr [edi]
// 006692de  8b4204               mov eax, dword ptr [edx + 4]
// 006692e1  8bcf                 mov ecx, edi
// 006692e3  ffd0                 call eax
// 006692e5  8d4f08               lea ecx, [edi + 8]
// 006692e8  83caff               or edx, 0xffffffff
// 006692eb  f00fc111             lock xadd dword ptr [ecx], edx
// 006692ef  7509                 jne 0x6692fa
// 006692f1  8b07                 mov eax, dword ptr [edi]
// 006692f3  8b5008               mov edx, dword ptr [eax + 8]
// 006692f6  8bcf                 mov ecx, edi
// 006692f8  ffd2                 call edx
// 006692fa  83461cff             add dword ptr [esi + 0x1c], -1
// 006692fe  7503                 jne 0x669303
// 00669300  895e18               mov dword ptr [esi + 0x18], ebx
// 00669303  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 00669306  7598                 jne 0x6692a0
// 00669308  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0066930b  3bfb                 cmp edi, ebx
// 0066930d  761c                 jbe 0x66932b
// 0066930f  90                   nop 
// 00669310  8b4610               mov eax, dword ptr [esi + 0x10]
// 00669313  4f                   dec edi
// 00669314  391cb8               cmp dword ptr [eax + edi*4], ebx
// 00669317  8d04b8               lea eax, [eax + edi*4]
// 0066931a  740b                 je 0x669327
// 0066931c  8b08                 mov ecx, dword ptr [eax]
// 0066931e  51                   push ecx
// 0066931f  e836a51800           call 0x7f385a
// 00669324  83c404               add esp, 4
// 00669327  3bfb                 cmp edi, ebx
// 00669329  77e5                 ja 0x669310
// 0066932b  8b4610               mov eax, dword ptr [esi + 0x10]
// 0066932e  3bc3                 cmp eax, ebx
// 00669330  7409                 je 0x66933b
// 00669332  50                   push eax
// 00669333  e822a51800           call 0x7f385a
// 00669338  83c404               add esp, 4
// 0066933b  5f                   pop edi
// 0066933c  895e10               mov dword ptr [esi + 0x10], ebx
// 0066933f  895e14               mov dword ptr [esi + 0x14], ebx
// 00669342  5e                   pop esi
// 00669343  5b                   pop ebx
// 00669344  c3                   ret 
// library templates-boost-1_34_1/deque_sp.cpp (function ?_Tidy@?$deque@V?$shared_ptr@UT@@@boost@@V?$allocator@V?$shared_ptr@UT@@@boost@@@std@@@std@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 deque_sp.cpp
