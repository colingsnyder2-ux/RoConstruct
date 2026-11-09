// from server: 100% by auto
// roc 2009-12 007d4450  unit: seg_007d0000  size: 324 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d4450
//
// 007d4450  53                   push ebx
// 007d4451  56                   push esi
// 007d4452  8bf0                 mov esi, eax
// 007d4454  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d4457  05fefeffff           add eax, 0xfffffefe
// 007d445c  57                   push edi
// 007d445d  8b7e04               mov edi, dword ptr [esi + 4]
// 007d4460  83f813               cmp eax, 0x13
// 007d4463  0f87e2000000         ja 0x7d454b
// 007d4469  0fb68080457d00       movzx eax, byte ptr [eax + 0x7d4580]
// 007d4470  ff248558457d00       jmp dword ptr [eax*4 + 0x7d4558]
// 007d4477  57                   push edi
// 007d4478  8bc6                 mov eax, esi
// 007d447a  e841faffff           call 0x7d3ec0
// 007d447f  83c404               add esp, 4
// 007d4482  5f                   pop edi
// 007d4483  5e                   pop esi
// 007d4484  33c0                 xor eax, eax
// 007d4486  5b                   pop ebx
// 007d4487  c3                   ret 
// 007d4488  57                   push edi
// 007d4489  8bc6                 mov eax, esi
// 007d448b  e8d0efffff           call 0x7d3460
// 007d4490  83c404               add esp, 4
// 007d4493  5f                   pop edi
// 007d4494  5e                   pop esi
// 007d4495  33c0                 xor eax, eax
// 007d4497  5b                   pop ebx
// 007d4498  c3                   ret 
// 007d4499  56                   push esi
// 007d449a  e891220000           call 0x7d6730
// 007d449f  8bc6                 mov eax, esi
// 007d44a1  e81aedffff           call 0x7d31c0
// 007d44a6  8bc7                 mov eax, edi
// 007d44a8  6803010000           push 0x103
// 007d44ad  bf06010000           mov edi, 0x106
// 007d44b2  e829d4ffff           call 0x7d18e0
// 007d44b7  83c408               add esp, 8
// 007d44ba  5f                   pop edi
// 007d44bb  5e                   pop esi
// 007d44bc  33c0                 xor eax, eax
// 007d44be  5b                   pop ebx
// 007d44bf  c3                   ret 
// 007d44c0  57                   push edi
// 007d44c1  8bc6                 mov eax, esi
// 007d44c3  e858f8ffff           call 0x7d3d20
// 007d44c8  83c404               add esp, 4
// 007d44cb  5f                   pop edi
// 007d44cc  5e                   pop esi
// 007d44cd  33c0                 xor eax, eax
// 007d44cf  5b                   pop ebx
// 007d44d0  c3                   ret 
// 007d44d1  57                   push edi
// 007d44d2  8bde                 mov ebx, esi
// 007d44d4  e8b7f0ffff           call 0x7d3590
// 007d44d9  83c404               add esp, 4
// 007d44dc  5f                   pop edi
// 007d44dd  5e                   pop esi
// 007d44de  33c0                 xor eax, eax
// 007d44e0  5b                   pop ebx
// 007d44e1  c3                   ret 
// 007d44e2  e899fdffff           call 0x7d4280
// 007d44e7  5f                   pop edi
// 007d44e8  5e                   pop esi
// 007d44e9  33c0                 xor eax, eax
// 007d44eb  5b                   pop ebx
// 007d44ec  c3                   ret 
// 007d44ed  56                   push esi
// 007d44ee  e83d220000           call 0x7d6730
// 007d44f3  83c404               add esp, 4
// 007d44f6  817e1009010000       cmp dword ptr [esi + 0x10], 0x109
// 007d44fd  7516                 jne 0x7d4515
// 007d44ff  56                   push esi
// 007d4500  e82b220000           call 0x7d6730
// 007d4505  83c404               add esp, 4
// 007d4508  8bde                 mov ebx, esi
// 007d450a  e871faffff           call 0x7d3f80
// 007d450f  5f                   pop edi
// 007d4510  5e                   pop esi
// 007d4511  33c0                 xor eax, eax
// 007d4513  5b                   pop ebx
// 007d4514  c3                   ret 
// 007d4515  8bc6                 mov eax, esi
// 007d4517  e864fbffff           call 0x7d4080
// 007d451c  5f                   pop edi
// 007d451d  5e                   pop esi
// 007d451e  33c0                 xor eax, eax
// 007d4520  5b                   pop ebx
// 007d4521  c3                   ret 
// 007d4522  8bc6                 mov eax, esi
// 007d4524  e807feffff           call 0x7d4330
// 007d4529  5f                   pop edi
// 007d452a  5e                   pop esi
// 007d452b  b801000000           mov eax, 1
// 007d4530  5b                   pop ebx
// 007d4531  c3                   ret 
// 007d4532  56                   push esi
// 007d4533  e8f8210000           call 0x7d6730
// 007d4538  83c404               add esp, 4
// 007d453b  8bc6                 mov eax, esi
// 007d453d  e8beeeffff           call 0x7d3400
// 007d4542  5f                   pop edi
// 007d4543  5e                   pop esi
// 007d4544  b801000000           mov eax, 1
// 007d4549  5b                   pop ebx
// 007d454a  c3                   ret 
// 007d454b  8bc6                 mov eax, esi
// 007d454d  e87efdffff           call 0x7d42d0
// 007d4552  5f                   pop edi
// 007d4553  5e                   pop esi
// 007d4554  33c0                 xor eax, eax
// 007d4556  5b                   pop ebx
// 007d4557  c3                   ret 
// 007d4558  32457d               xor al, byte ptr [ebp + 0x7d]
// 007d455b  0099447d00c0         add byte ptr [ecx - 0x3fff82bc], bl
// 007d4561  44                   inc esp
// 007d4562  7d00                 jge 0x7d4564
// 007d4564  e244                 loop 0x7d45aa
// 007d4566  7d00                 jge 0x7d4568
// 007d4568  7744                 ja 0x7d45ae
// 007d456a  7d00                 jge 0x7d456c
// 007d456c  ed                   in eax, dx
// 007d456d  44                   inc esp
// 007d456e  7d00                 jge 0x7d4570
// 007d4570  d1447d00             rol dword ptr [ebp + edi*2], 1
// 007d4574  22457d               and al, byte ptr [ebp + 0x7d]
// 007d4577  0088447d004b         add byte ptr [eax + 0x4b007d44], cl
// 007d457d  45                   inc ebp
// 007d457e  7d00                 jge 0x7d4580
// 007d4580  0001                 add byte ptr [ecx], al
// 007d4582  0909                 or dword ptr [ecx], ecx
// 007d4584  0909                 or dword ptr [ecx], ecx
// 007d4586  0203                 add al, byte ptr [ebx]
// 007d4588  0409                 add al, 9
// 007d458a  0509090906           add eax, 0x6090909
// 007d458f  07                   pop es
// 007d4590  0909                 or dword ptr [ecx], ecx
// 007d4592  0908                 or dword ptr [eax], ecx
// library lua-5.1/lparser.c (function _statement)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
