// from server: 100% by auto
// roc 2008-06 004d23c0  unit: seg_004d0000  size: 279 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d23c0
//
// 004d23c0  53                   push ebx
// 004d23c1  56                   push esi
// 004d23c2  8bf1                 mov esi, ecx
// 004d23c4  33db                 xor ebx, ebx
// 004d23c6  399ea8000000         cmp dword ptr [esi + 0xa8], ebx
// 004d23cc  0f8600010000         jbe 0x4d24d2
// 004d23d2  55                   push ebp
// 004d23d3  57                   push edi
// 004d23d4  eb0a                 jmp 0x4d23e0
// 004d23d6  8da42400000000       lea esp, [esp]
// 004d23dd  8d4900               lea ecx, [ecx]
// 004d23e0  8b86a4000000         mov eax, dword ptr [esi + 0xa4]
// 004d23e6  8b0c98               mov ecx, dword ptr [eax + ebx*4]
// 004d23e9  8b86d8030000         mov eax, dword ptr [esi + 0x3d8]
// 004d23ef  bae8030000           mov edx, 0x3e8
// 004d23f4  f7e2                 mul edx
// 004d23f6  0301                 add eax, dword ptr [ecx]
// 004d23f8  135104               adc edx, dword ptr [ecx + 4]
// 004d23fb  39542418             cmp dword ptr [esp + 0x18], edx
// 004d23ff  0f8cbe000000         jl 0x4d24c3
// 004d2405  7f0a                 jg 0x4d2411
// 004d2407  39442414             cmp dword ptr [esp + 0x14], eax
// 004d240b  0f86b2000000         jbe 0x4d24c3
// 004d2411  8b4108               mov eax, dword ptr [ecx + 8]
// 004d2414  8b10                 mov edx, dword ptr [eax]
// 004d2416  8b4210               mov eax, dword ptr [edx + 0x10]
// 004d2419  85c0                 test eax, eax
// 004d241b  7409                 je 0x4d2426
// 004d241d  83f801               cmp eax, 1
// 004d2420  0f859d000000         jne 0x4d24c3
// 004d2426  33ff                 xor edi, edi
// 004d2428  39790c               cmp dword ptr [ecx + 0xc], edi
// 004d242b  763e                 jbe 0x4d246b
// 004d242d  8daeb0070000         lea ebp, [esi + 0x7b0]
// 004d2433  8b4108               mov eax, dword ptr [ecx + 8]
// 004d2436  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 004d2439  8b513c               mov edx, dword ptr [ecx + 0x3c]
// 004d243c  52                   push edx
// 004d243d  e838e21c00           call 0x6a067a
// 004d2442  8b86a4000000         mov eax, dword ptr [esi + 0xa4]
// 004d2448  8b0c98               mov ecx, dword ptr [eax + ebx*4]
// 004d244b  8b5108               mov edx, dword ptr [ecx + 8]
// 004d244e  8b04ba               mov eax, dword ptr [edx + edi*4]
// 004d2451  83c404               add esp, 4
// 004d2454  50                   push eax
// 004d2455  8bcd                 mov ecx, ebp
// 004d2457  e844d5ffff           call 0x4cf9a0
// 004d245c  8b8ea4000000         mov ecx, dword ptr [esi + 0xa4]
// 004d2462  8b0c99               mov ecx, dword ptr [ecx + ebx*4]
// 004d2465  47                   inc edi
// 004d2466  3b790c               cmp edi, dword ptr [ecx + 0xc]
// 004d2469  72c8                 jb 0x4d2433
// 004d246b  8b96a4000000         mov edx, dword ptr [esi + 0xa4]
// 004d2471  8b3c9a               mov edi, dword ptr [edx + ebx*4]
// 004d2474  85ff                 test edi, edi
// 004d2476  7411                 je 0x4d2489
// 004d2478  8d4f08               lea ecx, [edi + 8]
// 004d247b  e8807ffeff           call 0x4ba400
// 004d2480  57                   push edi
// 004d2481  e8f4e11c00           call 0x6a067a
// 004d2486  83c404               add esp, 4
// 004d2489  8b8ea8000000         mov ecx, dword ptr [esi + 0xa8]
// 004d248f  3bd9                 cmp ebx, ecx
// 004d2491  7331                 jae 0x4d24c4
// 004d2493  49                   dec ecx
// 004d2494  8bc3                 mov eax, ebx
// 004d2496  3bd9                 cmp ebx, ecx
// 004d2498  7321                 jae 0x4d24bb
// 004d249a  8d9b00000000         lea ebx, [ebx]
// 004d24a0  8b8ea4000000         mov ecx, dword ptr [esi + 0xa4]
// 004d24a6  8b548104             mov edx, dword ptr [ecx + eax*4 + 4]
// 004d24aa  8d0c81               lea ecx, [ecx + eax*4]
// 004d24ad  8911                 mov dword ptr [ecx], edx
// 004d24af  8b8ea8000000         mov ecx, dword ptr [esi + 0xa8]
// 004d24b5  40                   inc eax
// 004d24b6  49                   dec ecx
// 004d24b7  3bc1                 cmp eax, ecx
// 004d24b9  72e5                 jb 0x4d24a0
// 004d24bb  ff8ea8000000         dec dword ptr [esi + 0xa8]
// 004d24c1  eb01                 jmp 0x4d24c4
// 004d24c3  43                   inc ebx
// 004d24c4  3b9ea8000000         cmp ebx, dword ptr [esi + 0xa8]
// 004d24ca  0f8210ffffff         jb 0x4d23e0
// 004d24d0  5f                   pop edi
// 004d24d1  5d                   pop ebp
// 004d24d2  5e                   pop esi
// 004d24d3  5b                   pop ebx
// 004d24d4  c20800               ret 8
// library openrbx-raknet/ReliabilityLayer.cpp (function ?DeleteOldUnreliableSplitPackets@ReliabilityLayer@@AAEX_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
