// from server: 100% by Xemicl
// roc 2012-06 004164c0  unit: CIDEBrowserView  size: 366 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004164c0
//
// 004164c0  6aff                 push -1
// 004164c2  6823aea900           push 0xa9ae23
// 004164c7  64a100000000         mov eax, dword ptr fs:[0]
// 004164cd  50                   push eax
// 004164ce  64892500000000       mov dword ptr fs:[0], esp
// 004164d5  83ec14               sub esp, 0x14
// 004164d8  53                   push ebx
// 004164d9  55                   push ebp
// 004164da  56                   push esi
// 004164db  57                   push edi
// 004164dc  33db                 xor ebx, ebx
// 004164de  68e8000000           push 0xe8
// 004164e3  895c2430             mov dword ptr [esp + 0x30], ebx
// 004164e7  e82ebc5600           call 0x98211a
// 004164ec  83c404               add esp, 4
// 004164ef  89442410             mov dword ptr [esp + 0x10], eax
// 004164f3  c644242c01           mov byte ptr [esp + 0x2c], 1
// 004164f8  3bc3                 cmp eax, ebx
// 004164fa  740b                 je 0x416507
// 004164fc  8bc8                 mov ecx, eax
// 004164fe  e8b7c15600           call 0x9826ba
// 00416503  8bf8                 mov edi, eax
// 00416505  eb02                 jmp 0x416509
// 00416507  33ff                 xor edi, edi
// 00416509  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0041650d  8b07                 mov eax, dword ptr [edi]
// 0041650f  8b8044010000         mov eax, dword ptr [eax + 0x144]
// 00416515  53                   push ebx
// 00416516  53                   push ebx
// 00416517  53                   push ebx
// 00416518  51                   push ecx
// 00416519  8d542424             lea edx, [esp + 0x24]
// 0041651d  52                   push edx
// 0041651e  680000cf00           push 0xcf0000
// 00416523  53                   push ebx
// 00416524  53                   push ebx
// 00416525  8bcf                 mov ecx, edi
// 00416527  885c244c             mov byte ptr [esp + 0x4c], bl
// 0041652b  895c2434             mov dword ptr [esp + 0x34], ebx
// 0041652f  895c2438             mov dword ptr [esp + 0x38], ebx
// 00416533  895c243c             mov dword ptr [esp + 0x3c], ebx
// 00416537  895c2440             mov dword ptr [esp + 0x40], ebx
// 0041653b  ffd0                 call eax
// 0041653d  53                   push ebx
// 0041653e  6880000000           push 0x80
// 00416543  6800020000           push 0x200
// 00416548  8bcf                 mov ecx, edi
// 0041654a  e865c15600           call 0x9826b4
// 0041654f  53                   push ebx
// 00416550  685032d600           push 0xd63250
// 00416555  6880f0d500           push 0xd5f080
// 0041655a  53                   push ebx
// 0041655b  6800e90000           push 0xe900
// 00416560  53                   push ebx
// 00416561  6800008050           push 0x50800000
// 00416566  53                   push ebx
// 00416567  53                   push ebx
// 00416568  688c50b400           push 0xb4508c
// 0041656d  57                   push edi
// 0041656e  e86dfb5800           call 0x9a60e0
// 00416573  50                   push eax
// 00416574  e8cfce5600           call 0x983448
// 00416579  8b6c2460             mov ebp, dword ptr [esp + 0x60]
// 0041657d  8bf0                 mov esi, eax
// 0041657f  83c414               add esp, 0x14
// 00416582  39aea8020000         cmp dword ptr [esi + 0x2a8], ebp
// 00416588  7425                 je 0x4165af
// 0041658a  3beb                 cmp ebp, ebx
// 0041658c  7409                 je 0x416597
// 0041658e  8b4d00               mov ecx, dword ptr [ebp]
// 00416591  8b5104               mov edx, dword ptr [ecx + 4]
// 00416594  55                   push ebp
// 00416595  ffd2                 call edx
// 00416597  8b86a8020000         mov eax, dword ptr [esi + 0x2a8]
// 0041659d  3bc3                 cmp eax, ebx
// 0041659f  7408                 je 0x4165a9
// 004165a1  8b08                 mov ecx, dword ptr [eax]
// 004165a3  8b5108               mov edx, dword ptr [ecx + 8]
// 004165a6  50                   push eax
// 004165a7  ffd2                 call edx
// 004165a9  89aea8020000         mov dword ptr [esi + 0x2a8], ebp
// 004165af  8d4c2448             lea ecx, [esp + 0x48]
// 004165b3  ff159847b200         call dword ptr [0xb24798]
// 004165b9  8be8                 mov ebp, eax
// 004165bb  55                   push ebp
// 004165bc  8d8eb0020000         lea ecx, [esi + 0x2b0]
// 004165c2  ff157847b200         call dword ptr [0xb24778]
// 004165c8  53                   push ebx
// 004165c9  53                   push ebx
// 004165ca  53                   push ebx
// 004165cb  53                   push ebx
// 004165cc  53                   push ebx
// 004165cd  55                   push ebp
// 004165ce  8bce                 mov ecx, esi
// 004165d0  e821be5600           call 0x9823f6
// 004165d5  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 004165d9  8d442434             lea eax, [esp + 0x34]
// 004165dd  50                   push eax
// 004165de  e8cbc05600           call 0x9826ae
// 004165e3  8b442438             mov eax, dword ptr [esp + 0x38]
// 004165e7  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 004165eb  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 004165ef  6a04                 push 4
// 004165f1  2bc8                 sub ecx, eax
// 004165f3  51                   push ecx
// 004165f4  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004165f8  2bd1                 sub edx, ecx
// 004165fa  52                   push edx
// 004165fb  50                   push eax
// 004165fc  51                   push ecx
// 004165fd  53                   push ebx
// 004165fe  8bcf                 mov ecx, edi
// 00416600  e8cfbe5600           call 0x9824d4
// 00416605  6a01                 push 1
// 00416607  53                   push ebx
// 00416608  8bcf                 mov ecx, edi
// 0041660a  e899c05600           call 0x9826a8
// 0041660f  8d4c2448             lea ecx, [esp + 0x48]
// 00416613  ff15d047b200         call dword ptr [0xb247d0]
// 00416619  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0041661d  5f                   pop edi
// 0041661e  8bc6                 mov eax, esi
// 00416620  5e                   pop esi
// 00416621  5d                   pop ebp
// 00416622  5b                   pop ebx
// 00416623  64890d00000000       mov dword ptr fs:[0], ecx
// 0041662a  83c420               add esp, 0x20
// 0041662d  c3                   ret 
// copied from an identical function in another client (function ?makeView@@YAPAUView@@URect@@PAUWindow@@UString@@PAUUnknown@@@Z)

// from server: 100% by colin
// roc 2008-06 0040f050  unit: VCBrowserViewExternal::?$CProxy_IBrowserViewExternalEvents  size: 366 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040f050
//
// 0040f050  6aff                 push -1
// 0040f052  6883d47b00           push 0x7bd483
// 0040f057  64a100000000         mov eax, dword ptr fs:[0]
// 0040f05d  50                   push eax
// 0040f05e  64892500000000       mov dword ptr fs:[0], esp
// 0040f065  83ec14               sub esp, 0x14
// 0040f068  53                   push ebx
// 0040f069  55                   push ebp
// 0040f06a  56                   push esi
// 0040f06b  57                   push edi
// 0040f06c  33db                 xor ebx, ebx
// 0040f06e  68e8000000           push 0xe8
// 0040f073  895c2430             mov dword ptr [esp + 0x30], ebx
// 0040f077  e8a4182900           call 0x6a0920
// 0040f07c  83c404               add esp, 4
// 0040f07f  89442410             mov dword ptr [esp + 0x10], eax
// 0040f083  c644242c01           mov byte ptr [esp + 0x2c], 1
// 0040f088  3bc3                 cmp eax, ebx
// 0040f08a  740b                 je 0x40f097
// 0040f08c  8bc8                 mov ecx, eax
// 0040f08e  e8ab1b2900           call 0x6a0c3e
// 0040f093  8bf8                 mov edi, eax
// 0040f095  eb02                 jmp 0x40f099
// 0040f097  33ff                 xor edi, edi
// 0040f099  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0040f09d  8b07                 mov eax, dword ptr [edi]
// 0040f09f  8b8044010000         mov eax, dword ptr [eax + 0x144]
// 0040f0a5  53                   push ebx
// 0040f0a6  53                   push ebx
// 0040f0a7  53                   push ebx
// 0040f0a8  51                   push ecx
// 0040f0a9  8d542424             lea edx, [esp + 0x24]
// 0040f0ad  52                   push edx
// 0040f0ae  680000cf00           push 0xcf0000
// 0040f0b3  53                   push ebx
// 0040f0b4  53                   push ebx
// 0040f0b5  8bcf                 mov ecx, edi
// 0040f0b7  885c244c             mov byte ptr [esp + 0x4c], bl
// 0040f0bb  895c2434             mov dword ptr [esp + 0x34], ebx
// 0040f0bf  895c2438             mov dword ptr [esp + 0x38], ebx
// 0040f0c3  895c243c             mov dword ptr [esp + 0x3c], ebx
// 0040f0c7  895c2440             mov dword ptr [esp + 0x40], ebx
// 0040f0cb  ffd0                 call eax
// 0040f0cd  53                   push ebx
// 0040f0ce  6880000000           push 0x80
// 0040f0d3  6800020000           push 0x200
// 0040f0d8  8bcf                 mov ecx, edi
// 0040f0da  e8591b2900           call 0x6a0c38
// 0040f0df  53                   push ebx
// 0040f0e0  6828af9200           push 0x92af28
// 0040f0e5  687c809200           push 0x92807c
// 0040f0ea  53                   push ebx
// 0040f0eb  6800e90000           push 0xe900
// 0040f0f0  53                   push ebx
// 0040f0f1  6800008050           push 0x50800000
// 0040f0f6  53                   push ebx
// 0040f0f7  53                   push ebx
// 0040f0f8  6858cf8000           push 0x80cf58
// 0040f0fd  57                   push edi
// 0040f0fe  e85d5a2b00           call 0x6c4b60
// 0040f103  50                   push eax
// 0040f104  e8bd262900           call 0x6a17c6
// 0040f109  8b6c2460             mov ebp, dword ptr [esp + 0x60]
// 0040f10d  8bf0                 mov esi, eax
// 0040f10f  83c414               add esp, 0x14
// 0040f112  39aec4020000         cmp dword ptr [esi + 0x2c4], ebp
// 0040f118  7425                 je 0x40f13f
// 0040f11a  3beb                 cmp ebp, ebx
// 0040f11c  7409                 je 0x40f127
// 0040f11e  8b4d00               mov ecx, dword ptr [ebp]
// 0040f121  8b5104               mov edx, dword ptr [ecx + 4]
// 0040f124  55                   push ebp
// 0040f125  ffd2                 call edx
// 0040f127  8b86c4020000         mov eax, dword ptr [esi + 0x2c4]
// 0040f12d  3bc3                 cmp eax, ebx
// 0040f12f  7408                 je 0x40f139
// 0040f131  8b08                 mov ecx, dword ptr [eax]
// 0040f133  8b5108               mov edx, dword ptr [ecx + 8]
// 0040f136  50                   push eax
// 0040f137  ffd2                 call edx
// 0040f139  89aec4020000         mov dword ptr [esi + 0x2c4], ebp
// 0040f13f  8d4c2448             lea ecx, [esp + 0x48]
// 0040f143  ff15e03e8000         call dword ptr [0x803ee0]
// 0040f149  8be8                 mov ebp, eax
// 0040f14b  55                   push ebp
// 0040f14c  8d8ecc020000         lea ecx, [esi + 0x2cc]
// 0040f152  ff15b83e8000         call dword ptr [0x803eb8]
// 0040f158  53                   push ebx
// 0040f159  53                   push ebx
// 0040f15a  53                   push ebx
// 0040f15b  53                   push ebx
// 0040f15c  53                   push ebx
// 0040f15d  55                   push ebp
// 0040f15e  8bce                 mov ecx, esi
// 0040f160  e815182900           call 0x6a097a
// 0040f165  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0040f169  8d442434             lea eax, [esp + 0x34]
// 0040f16d  50                   push eax
// 0040f16e  e8bf1a2900           call 0x6a0c32
// 0040f173  8b442438             mov eax, dword ptr [esp + 0x38]
// 0040f177  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0040f17b  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0040f17f  6a04                 push 4
// 0040f181  2bc8                 sub ecx, eax
// 0040f183  51                   push ecx
// 0040f184  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0040f188  2bd1                 sub edx, ecx
// 0040f18a  52                   push edx
// 0040f18b  50                   push eax
// 0040f18c  51                   push ecx
// 0040f18d  53                   push ebx
// 0040f18e  8bcf                 mov ecx, edi
// 0040f190  e8b1182900           call 0x6a0a46
// 0040f195  6a01                 push 1
// 0040f197  53                   push ebx
// 0040f198  8bcf                 mov ecx, edi
// 0040f19a  e88d1a2900           call 0x6a0c2c
// 0040f19f  8d4c2448             lea ecx, [esp + 0x48]
// 0040f1a3  ff15143f8000         call dword ptr [0x803f14]
// 0040f1a9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0040f1ad  5f                   pop edi
// 0040f1ae  8bc6                 mov eax, esi
// 0040f1b0  5e                   pop esi
// 0040f1b1  5d                   pop ebp
// 0040f1b2  5b                   pop ebx
// 0040f1b3  64890d00000000       mov dword ptr fs:[0], ecx
// 0040f1ba  83c420               add esp, 0x20
// 0040f1bd  c3                   ret 

// from server: 96% by colin
// roc 2008-06 0040f050  unit: VCBrowserViewExternal::?$CProxy_IBrowserViewExternalEvents  size: 366 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040f050
//
// 0040f050  6aff                 push -1
// 0040f052  6883d47b00           push 0x7bd483
// 0040f057  64a100000000         mov eax, dword ptr fs:[0]
// 0040f05d  50                   push eax
// 0040f05e  64892500000000       mov dword ptr fs:[0], esp
// 0040f065  83ec14               sub esp, 0x14
// 0040f068  53                   push ebx
// 0040f069  55                   push ebp
// 0040f06a  56                   push esi
// 0040f06b  57                   push edi
// 0040f06c  33db                 xor ebx, ebx
// 0040f06e  68e8000000           push 0xe8
// 0040f073  895c2430             mov dword ptr [esp + 0x30], ebx
// 0040f077  e8a4182900           call 0x6a0920
// 0040f07c  83c404               add esp, 4
// 0040f07f  89442410             mov dword ptr [esp + 0x10], eax
// 0040f083  c644242c01           mov byte ptr [esp + 0x2c], 1
// 0040f088  3bc3                 cmp eax, ebx
// 0040f08a  740b                 je 0x40f097
// 0040f08c  8bc8                 mov ecx, eax
// 0040f08e  e8ab1b2900           call 0x6a0c3e
// 0040f093  8bf8                 mov edi, eax
// 0040f095  eb02                 jmp 0x40f099
// 0040f097  33ff                 xor edi, edi
// 0040f099  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0040f09d  8b07                 mov eax, dword ptr [edi]
// 0040f09f  8b8044010000         mov eax, dword ptr [eax + 0x144]
// 0040f0a5  53                   push ebx
// 0040f0a6  53                   push ebx
// 0040f0a7  53                   push ebx
// 0040f0a8  51                   push ecx
// 0040f0a9  8d542424             lea edx, [esp + 0x24]
// 0040f0ad  52                   push edx
// 0040f0ae  680000cf00           push 0xcf0000
// 0040f0b3  53                   push ebx
// 0040f0b4  53                   push ebx
// 0040f0b5  8bcf                 mov ecx, edi
// 0040f0b7  885c244c             mov byte ptr [esp + 0x4c], bl
// 0040f0bb  895c2434             mov dword ptr [esp + 0x34], ebx
// 0040f0bf  895c2438             mov dword ptr [esp + 0x38], ebx
// 0040f0c3  895c243c             mov dword ptr [esp + 0x3c], ebx
// 0040f0c7  895c2440             mov dword ptr [esp + 0x40], ebx
// 0040f0cb  ffd0                 call eax
// 0040f0cd  53                   push ebx
// 0040f0ce  6880000000           push 0x80
// 0040f0d3  6800020000           push 0x200
// 0040f0d8  8bcf                 mov ecx, edi
// 0040f0da  e8591b2900           call 0x6a0c38
// 0040f0df  53                   push ebx
// 0040f0e0  6828af9200           push 0x92af28
// 0040f0e5  687c809200           push 0x92807c
// 0040f0ea  53                   push ebx
// 0040f0eb  6800e90000           push 0xe900
// 0040f0f0  53                   push ebx
// 0040f0f1  6800008050           push 0x50800000
// 0040f0f6  53                   push ebx
// 0040f0f7  53                   push ebx
// 0040f0f8  6858cf8000           push 0x80cf58
// 0040f0fd  57                   push edi
// 0040f0fe  e85d5a2b00           call 0x6c4b60
// 0040f103  50                   push eax
// 0040f104  e8bd262900           call 0x6a17c6
// 0040f109  8b6c2460             mov ebp, dword ptr [esp + 0x60]
// 0040f10d  8bf0                 mov esi, eax
// 0040f10f  83c414               add esp, 0x14
// 0040f112  39aec4020000         cmp dword ptr [esi + 0x2c4], ebp
// 0040f118  7425                 je 0x40f13f
// 0040f11a  3beb                 cmp ebp, ebx
// 0040f11c  7409                 je 0x40f127
// 0040f11e  8b4d00               mov ecx, dword ptr [ebp]
// 0040f121  8b5104               mov edx, dword ptr [ecx + 4]
// 0040f124  55                   push ebp
// 0040f125  ffd2                 call edx
// 0040f127  8b86c4020000         mov eax, dword ptr [esi + 0x2c4]
// 0040f12d  3bc3                 cmp eax, ebx
// 0040f12f  7408                 je 0x40f139
// 0040f131  8b08                 mov ecx, dword ptr [eax]
// 0040f133  8b5108               mov edx, dword ptr [ecx + 8]
// 0040f136  50                   push eax
// 0040f137  ffd2                 call edx
// 0040f139  89aec4020000         mov dword ptr [esi + 0x2c4], ebp
// 0040f13f  8d4c2448             lea ecx, [esp + 0x48]
// 0040f143  ff15e03e8000         call dword ptr [0x803ee0]
// 0040f149  8be8                 mov ebp, eax
// 0040f14b  55                   push ebp
// 0040f14c  8d8ecc020000         lea ecx, [esi + 0x2cc]
// 0040f152  ff15b83e8000         call dword ptr [0x803eb8]
// 0040f158  53                   push ebx
// 0040f159  53                   push ebx
// 0040f15a  53                   push ebx
// 0040f15b  53                   push ebx
// 0040f15c  53                   push ebx
// 0040f15d  55                   push ebp
// 0040f15e  8bce                 mov ecx, esi
// 0040f160  e815182900           call 0x6a097a
// 0040f165  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0040f169  8d442434             lea eax, [esp + 0x34]
// 0040f16d  50                   push eax
// 0040f16e  e8bf1a2900           call 0x6a0c32
// 0040f173  8b442438             mov eax, dword ptr [esp + 0x38]
// 0040f177  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0040f17b  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0040f17f  6a04                 push 4
// 0040f181  2bc8                 sub ecx, eax
// 0040f183  51                   push ecx
// 0040f184  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0040f188  2bd1                 sub edx, ecx
// 0040f18a  52                   push edx
// 0040f18b  50                   push eax
// 0040f18c  51                   push ecx
// 0040f18d  53                   push ebx
// 0040f18e  8bcf                 mov ecx, edi
// 0040f190  e8b1182900           call 0x6a0a46
// 0040f195  6a01                 push 1
// 0040f197  53                   push ebx
// 0040f198  8bcf                 mov ecx, edi
// 0040f19a  e88d1a2900           call 0x6a0c2c
// 0040f19f  8d4c2448             lea ecx, [esp + 0x48]
// 0040f1a3  ff15143f8000         call dword ptr [0x803f14]
// 0040f1a9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0040f1ad  5f                   pop edi
// 0040f1ae  8bc6                 mov eax, esi
// 0040f1b0  5e                   pop esi
// 0040f1b1  5d                   pop ebp
// 0040f1b2  5b                   pop ebx
// 0040f1b3  64890d00000000       mov dword ptr fs:[0], ecx
// 0040f1ba  83c420               add esp, 0x20
// 0040f1bd  c3                   ret 

// from server: 94% by king_originala
// roc 2008-06 0040f050  unit: VCBrowserViewExternal::?$CProxy_IBrowserViewExternalEvents  size: 366 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040f050
//
// 0040f050  6aff                 push -1
// 0040f052  6883d47b00           push 0x7bd483
// 0040f057  64a100000000         mov eax, dword ptr fs:[0]
// 0040f05d  50                   push eax
// 0040f05e  64892500000000       mov dword ptr fs:[0], esp
// 0040f065  83ec14               sub esp, 0x14
// 0040f068  53                   push ebx
// 0040f069  55                   push ebp
// 0040f06a  56                   push esi
// 0040f06b  57                   push edi
// 0040f06c  33db                 xor ebx, ebx
// 0040f06e  68e8000000           push 0xe8
// 0040f073  895c2430             mov dword ptr [esp + 0x30], ebx
// 0040f077  e8a4182900           call 0x6a0920
// 0040f07c  83c404               add esp, 4
// 0040f07f  89442410             mov dword ptr [esp + 0x10], eax
// 0040f083  c644242c01           mov byte ptr [esp + 0x2c], 1
// 0040f088  3bc3                 cmp eax, ebx
// 0040f08a  740b                 je 0x40f097
// 0040f08c  8bc8                 mov ecx, eax
// 0040f08e  e8ab1b2900           call 0x6a0c3e
// 0040f093  8bf8                 mov edi, eax
// 0040f095  eb02                 jmp 0x40f099
// 0040f097  33ff                 xor edi, edi
// 0040f099  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0040f09d  8b07                 mov eax, dword ptr [edi]
// 0040f09f  8b8044010000         mov eax, dword ptr [eax + 0x144]
// 0040f0a5  53                   push ebx
// 0040f0a6  53                   push ebx
// 0040f0a7  53                   push ebx
// 0040f0a8  51                   push ecx
// 0040f0a9  8d542424             lea edx, [esp + 0x24]
// 0040f0ad  52                   push edx
// 0040f0ae  680000cf00           push 0xcf0000
// 0040f0b3  53                   push ebx
// 0040f0b4  53                   push ebx
// 0040f0b5  8bcf                 mov ecx, edi
// 0040f0b7  885c244c             mov byte ptr [esp + 0x4c], bl
// 0040f0bb  895c2434             mov dword ptr [esp + 0x34], ebx
// 0040f0bf  895c2438             mov dword ptr [esp + 0x38], ebx
// 0040f0c3  895c243c             mov dword ptr [esp + 0x3c], ebx
// 0040f0c7  895c2440             mov dword ptr [esp + 0x40], ebx
// 0040f0cb  ffd0                 call eax
// 0040f0cd  53                   push ebx
// 0040f0ce  6880000000           push 0x80
// 0040f0d3  6800020000           push 0x200
// 0040f0d8  8bcf                 mov ecx, edi
// 0040f0da  e8591b2900           call 0x6a0c38
// 0040f0df  53                   push ebx
// 0040f0e0  6828af9200           push 0x92af28
// 0040f0e5  687c809200           push 0x92807c
// 0040f0ea  53                   push ebx
// 0040f0eb  6800e90000           push 0xe900
// 0040f0f0  53                   push ebx
// 0040f0f1  6800008050           push 0x50800000
// 0040f0f6  53                   push ebx
// 0040f0f7  53                   push ebx
// 0040f0f8  6858cf8000           push 0x80cf58
// 0040f0fd  57                   push edi
// 0040f0fe  e85d5a2b00           call 0x6c4b60
// 0040f103  50                   push eax
// 0040f104  e8bd262900           call 0x6a17c6
// 0040f109  8b6c2460             mov ebp, dword ptr [esp + 0x60]
// 0040f10d  8bf0                 mov esi, eax
// 0040f10f  83c414               add esp, 0x14
// 0040f112  39aec4020000         cmp dword ptr [esi + 0x2c4], ebp
// 0040f118  7425                 je 0x40f13f
// 0040f11a  3beb                 cmp ebp, ebx
// 0040f11c  7409                 je 0x40f127
// 0040f11e  8b4d00               mov ecx, dword ptr [ebp]
// 0040f121  8b5104               mov edx, dword ptr [ecx + 4]
// 0040f124  55                   push ebp
// 0040f125  ffd2                 call edx
// 0040f127  8b86c4020000         mov eax, dword ptr [esi + 0x2c4]
// 0040f12d  3bc3                 cmp eax, ebx
// 0040f12f  7408                 je 0x40f139
// 0040f131  8b08                 mov ecx, dword ptr [eax]
// 0040f133  8b5108               mov edx, dword ptr [ecx + 8]
// 0040f136  50                   push eax
// 0040f137  ffd2                 call edx
// 0040f139  89aec4020000         mov dword ptr [esi + 0x2c4], ebp
// 0040f13f  8d4c2448             lea ecx, [esp + 0x48]
// 0040f143  ff15e03e8000         call dword ptr [0x803ee0]
// 0040f149  8be8                 mov ebp, eax
// 0040f14b  55                   push ebp
// 0040f14c  8d8ecc020000         lea ecx, [esi + 0x2cc]
// 0040f152  ff15b83e8000         call dword ptr [0x803eb8]
// 0040f158  53                   push ebx
// 0040f159  53                   push ebx
// 0040f15a  53                   push ebx
// 0040f15b  53                   push ebx
// 0040f15c  53                   push ebx
// 0040f15d  55                   push ebp
// 0040f15e  8bce                 mov ecx, esi
// 0040f160  e815182900           call 0x6a097a
// 0040f165  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0040f169  8d442434             lea eax, [esp + 0x34]
// 0040f16d  50                   push eax
// 0040f16e  e8bf1a2900           call 0x6a0c32
// 0040f173  8b442438             mov eax, dword ptr [esp + 0x38]
// 0040f177  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0040f17b  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0040f17f  6a04                 push 4
// 0040f181  2bc8                 sub ecx, eax
// 0040f183  51                   push ecx
// 0040f184  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0040f188  2bd1                 sub edx, ecx
// 0040f18a  52                   push edx
// 0040f18b  50                   push eax
// 0040f18c  51                   push ecx
// 0040f18d  53                   push ebx
// 0040f18e  8bcf                 mov ecx, edi
// 0040f190  e8b1182900           call 0x6a0a46
// 0040f195  6a01                 push 1
// 0040f197  53                   push ebx
// 0040f198  8bcf                 mov ecx, edi
// 0040f19a  e88d1a2900           call 0x6a0c2c
// 0040f19f  8d4c2448             lea ecx, [esp + 0x48]
// 0040f1a3  ff15143f8000         call dword ptr [0x803f14]
// 0040f1a9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0040f1ad  5f                   pop edi
// 0040f1ae  8bc6                 mov eax, esi
// 0040f1b0  5e                   pop esi
// 0040f1b1  5d                   pop ebp
// 0040f1b2  5b                   pop ebx
// 0040f1b3  64890d00000000       mov dword ptr fs:[0], ecx
// 0040f1ba  83c420               add esp, 0x20
// 0040f1bd  c3                   ret 

typedef unsigned long DWORD;

void *__cdecl operator new(unsigned int);
void __cdecl operator delete(void *);

struct Rect {
    int left, top, right, bottom;
    Rect(int, int, int, int);
};

inline Rect::Rect(int l, int t, int r, int b)
    : left(l), top(t), right(r), bottom(b)
{
}

struct Window;
struct View;
struct Unknown;
struct String;

extern const char windowClass[];
extern const char windowType[];
extern const char viewType[];

extern const char *(__thiscall *stringData)(const String *);
extern void (__thiscall *stringAssign)(String *, const char *);
extern void (__thiscall *stringDestroy)(String *) throw();

struct String {
    void *data;
    __declspec(dllimport) ~String() throw();
};

struct UnknownTable {
    long (__stdcall *query)(Unknown *, const void *, void **);
    unsigned long (__stdcall *addRef)(Unknown *);
    unsigned long (__stdcall *release)(Unknown *);
};

struct Unknown {
    UnknownTable *table;
};

struct WindowTable {
    void *unused[81];
    int (__thiscall *create)(Window *, const char *, const char *,
                            DWORD, const Rect &, Window *, unsigned int,
                            void *, void *);
};

struct Window {
    WindowTable *table;
    unsigned char storage[228];

    Window();
    void modifyStyle(DWORD, DWORD, unsigned int);
    void getClientRect(Rect *);
    void setWindowPos(Window *, int, int, int, int, unsigned int);
    void showWindow(int, int);
};

struct View {
    unsigned char storage[680];
    Unknown *object;
    unsigned long reserved;
    String text;

    void navigate(const char *, DWORD, const char *, const char *,
                  void *, DWORD);
};

extern Window *__stdcall createView(Window *, const char *, const char *,
                                     void *, DWORD, unsigned int,
                                     unsigned int);
extern View *__cdecl castView(Window *, int, const void *, const void *, int);

View *__cdecl makeView(Rect rect, Window *parent, String text, Unknown *object)
{
    Window *window = new Window;

    int (__thiscall *createProc)(Window *, const char *, const char *,
                                 DWORD, const Rect &, Window *, unsigned int,
                                 void *, void *) = window->table->create;
    createProc(window, 0, 0, 0x00cf0000, Rect(0, 0, 0, 0),
               parent, 0, 0, 0);
    window->modifyStyle(0x200, 0x80, 0);

    View *view = castView(
        createView(window, windowClass, 0, 0, 0x50800000, 0, 0xe900),
        0, windowType, viewType, 0);

    if (view->object != object) {
        if (object)
            object->table->addRef(object);
        if (view->object)
            view->object->table->release(view->object);
        view->object = object;
    }

    const char *value = stringData(&text);
    stringAssign(&view->text, value);
    view->navigate(value, 0, 0, 0, 0, 0);

    parent->getClientRect(&rect);
    window->setWindowPos(0, rect.left, rect.top,
                         rect.right - rect.left,
                         rect.bottom - rect.top, 4);
    window->showWindow(0, 1);
    return view;
}