// from server: 100% by auto
// roc 2010-06 00513710  unit: RBX::Network::InterpolatingPhysicsReceiver::Job  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00513710
//
// 00513710  56                   push esi
// 00513711  8b742410             mov esi, dword ptr [esp + 0x10]
// 00513715  8d46fe               lea eax, [esi - 2]
// 00513718  83f80e               cmp eax, 0xe
// 0051371b  7758                 ja 0x513775
// 0051371d  55                   push ebp
// 0051371e  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00513722  57                   push edi
// 00513723  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00513727  8bcf                 mov ecx, edi
// 00513729  8bc5                 mov eax, ebp
// 0051372b  eb03                 jmp 0x513730
// 0051372d  8d4900               lea ecx, [ecx]
// 00513730  99                   cdq 
// 00513731  f7fe                 idiv esi
// 00513733  85d2                 test edx, edx
// 00513735  7d02                 jge 0x513739
// 00513737  f7da                 neg edx
// 00513739  8a9218e3a100         mov dl, byte ptr [edx + 0xa1e318]
// 0051373f  8811                 mov byte ptr [ecx], dl
// 00513741  41                   inc ecx
// 00513742  85c0                 test eax, eax
// 00513744  75ea                 jne 0x513730
// 00513746  85ed                 test ebp, ebp
// 00513748  7d09                 jge 0x513753
// 0051374a  83fe0a               cmp esi, 0xa
// 0051374d  7504                 jne 0x513753
// 0051374f  c6012d               mov byte ptr [ecx], 0x2d
// 00513752  41                   inc ecx
// 00513753  c60100               mov byte ptr [ecx], 0
// 00513756  49                   dec ecx
// 00513757  8bc7                 mov eax, edi
// 00513759  3bf9                 cmp edi, ecx
// 0051375b  7312                 jae 0x51376f
// 0051375d  53                   push ebx
// 0051375e  8bff                 mov edi, edi
// 00513760  8a19                 mov bl, byte ptr [ecx]
// 00513762  8a10                 mov dl, byte ptr [eax]
// 00513764  8818                 mov byte ptr [eax], bl
// 00513766  8811                 mov byte ptr [ecx], dl
// 00513768  40                   inc eax
// 00513769  49                   dec ecx
// 0051376a  3bc1                 cmp eax, ecx
// 0051376c  72f2                 jb 0x513760
// 0051376e  5b                   pop ebx
// 0051376f  8bc7                 mov eax, edi
// 00513771  5f                   pop edi
// 00513772  5d                   pop ebp
// 00513773  5e                   pop esi
// 00513774  c3                   ret 
// 00513775  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00513779  c60000               mov byte ptr [eax], 0
// 0051377c  5e                   pop esi
// 0051377d  c3                   ret 
// library openrbx-raknet/RakNetTypes.cpp (function ?my_itoa@@YAPADHPADH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakNetTypes.cpp
