// roc 2012-06 005a23a0  unit: RBX::Network::ClientReplicator  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a23a0
//
// 005a23a0  56                   push esi
// 005a23a1  8b742410             mov esi, dword ptr [esp + 0x10]
// 005a23a5  8d46fe               lea eax, [esi - 2]
// 005a23a8  83f80e               cmp eax, 0xe
// 005a23ab  7758                 ja 0x5a2405
// 005a23ad  55                   push ebp
// 005a23ae  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005a23b2  57                   push edi
// 005a23b3  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005a23b7  8bcf                 mov ecx, edi
// 005a23b9  8bc5                 mov eax, ebp
// 005a23bb  eb03                 jmp 0x5a23c0
// 005a23bd  8d4900               lea ecx, [ecx]
// 005a23c0  99                   cdq 
// 005a23c1  f7fe                 idiv esi
// 005a23c3  85d2                 test edx, edx
// 005a23c5  7d02                 jge 0x5a23c9
// 005a23c7  f7da                 neg edx
// 005a23c9  8a9244aeb700         mov dl, byte ptr [edx + 0xb7ae44]
// 005a23cf  8811                 mov byte ptr [ecx], dl
// 005a23d1  41                   inc ecx
// 005a23d2  85c0                 test eax, eax
// 005a23d4  75ea                 jne 0x5a23c0
// 005a23d6  85ed                 test ebp, ebp
// 005a23d8  7d09                 jge 0x5a23e3
// 005a23da  83fe0a               cmp esi, 0xa
// 005a23dd  7504                 jne 0x5a23e3
// 005a23df  c6012d               mov byte ptr [ecx], 0x2d
// 005a23e2  41                   inc ecx
// 005a23e3  c60100               mov byte ptr [ecx], 0
// 005a23e6  49                   dec ecx
// 005a23e7  8bc7                 mov eax, edi
// 005a23e9  3bf9                 cmp edi, ecx
// 005a23eb  7312                 jae 0x5a23ff
// 005a23ed  53                   push ebx
// 005a23ee  8bff                 mov edi, edi
// 005a23f0  8a19                 mov bl, byte ptr [ecx]
// 005a23f2  8a10                 mov dl, byte ptr [eax]
// 005a23f4  8818                 mov byte ptr [eax], bl
// 005a23f6  8811                 mov byte ptr [ecx], dl
// 005a23f8  40                   inc eax
// 005a23f9  49                   dec ecx
// 005a23fa  3bc1                 cmp eax, ecx
// 005a23fc  72f2                 jb 0x5a23f0
// 005a23fe  5b                   pop ebx
// 005a23ff  8bc7                 mov eax, edi
// 005a2401  5f                   pop edi
// 005a2402  5d                   pop ebp
// 005a2403  5e                   pop esi
// 005a2404  c3                   ret 
// 005a2405  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005a2409  c60000               mov byte ptr [eax], 0
// 005a240c  5e                   pop esi
// 005a240d  c3                   ret 
// library openrbx-raknet/RakNetTypes.cpp (function ?my_itoa@@YAPADHPADH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakNetTypes.cpp
