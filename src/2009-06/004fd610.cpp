// from server: 100% by auto
// roc 2009-06 004fd610  unit: RBX::Network::NetworkOwnerJob  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fd610
//
// 004fd610  56                   push esi
// 004fd611  8b742410             mov esi, dword ptr [esp + 0x10]
// 004fd615  8d46fe               lea eax, [esi - 2]
// 004fd618  83f80e               cmp eax, 0xe
// 004fd61b  7758                 ja 0x4fd675
// 004fd61d  55                   push ebp
// 004fd61e  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 004fd622  57                   push edi
// 004fd623  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004fd627  8bcf                 mov ecx, edi
// 004fd629  8bc5                 mov eax, ebp
// 004fd62b  eb03                 jmp 0x4fd630
// 004fd62d  8d4900               lea ecx, [ecx]
// 004fd630  99                   cdq 
// 004fd631  f7fe                 idiv esi
// 004fd633  85d2                 test edx, edx
// 004fd635  7d02                 jge 0x4fd639
// 004fd637  f7da                 neg edx
// 004fd639  8a92bc8d8c00         mov dl, byte ptr [edx + 0x8c8dbc]
// 004fd63f  8811                 mov byte ptr [ecx], dl
// 004fd641  41                   inc ecx
// 004fd642  85c0                 test eax, eax
// 004fd644  75ea                 jne 0x4fd630
// 004fd646  85ed                 test ebp, ebp
// 004fd648  7d09                 jge 0x4fd653
// 004fd64a  83fe0a               cmp esi, 0xa
// 004fd64d  7504                 jne 0x4fd653
// 004fd64f  c6012d               mov byte ptr [ecx], 0x2d
// 004fd652  41                   inc ecx
// 004fd653  c60100               mov byte ptr [ecx], 0
// 004fd656  49                   dec ecx
// 004fd657  8bc7                 mov eax, edi
// 004fd659  3bf9                 cmp edi, ecx
// 004fd65b  7312                 jae 0x4fd66f
// 004fd65d  53                   push ebx
// 004fd65e  8bff                 mov edi, edi
// 004fd660  8a19                 mov bl, byte ptr [ecx]
// 004fd662  8a10                 mov dl, byte ptr [eax]
// 004fd664  8818                 mov byte ptr [eax], bl
// 004fd666  8811                 mov byte ptr [ecx], dl
// 004fd668  40                   inc eax
// 004fd669  49                   dec ecx
// 004fd66a  3bc1                 cmp eax, ecx
// 004fd66c  72f2                 jb 0x4fd660
// 004fd66e  5b                   pop ebx
// 004fd66f  8bc7                 mov eax, edi
// 004fd671  5f                   pop edi
// 004fd672  5d                   pop ebp
// 004fd673  5e                   pop esi
// 004fd674  c3                   ret 
// 004fd675  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004fd679  c60000               mov byte ptr [eax], 0
// 004fd67c  5e                   pop esi
// 004fd67d  c3                   ret 
// library openrbx-raknet/RakNetTypes.cpp (function ?my_itoa@@YAPADHPADH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakNetTypes.cpp
