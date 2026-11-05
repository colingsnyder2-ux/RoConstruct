// roc 2009-12 0079b370  unit: seg_00790000  size: 334 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079b370
//
// 0079b370  51                   push ecx
// 0079b371  53                   push ebx
// 0079b372  55                   push ebp
// 0079b373  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0079b377  57                   push edi
// 0079b378  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0079b37c  33db                 xor ebx, ebx
// 0079b37e  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0079b386  3bfb                 cmp edi, ebx
// 0079b388  7543                 jne 0x79b3cd
// 0079b38a  b856fd9900           mov eax, 0x99fd56
// 0079b38f  894608               mov dword ptr [esi + 8], eax
// 0079b392  894604               mov dword ptr [esi + 4], eax
// 0079b395  83c8ff               or eax, 0xffffffff
// 0079b398  6a3c                 push 0x3c
// 0079b39a  894614               mov dword ptr [esi + 0x14], eax
// 0079b39d  89461c               mov dword ptr [esi + 0x1c], eax
// 0079b3a0  894620               mov dword ptr [esi + 0x20], eax
// 0079b3a3  8d4624               lea eax, [esi + 0x24]
// 0079b3a6  6884ab9e00           push 0x9eab84
// 0079b3ab  50                   push eax
// 0079b3ac  c7460c7cab9e00       mov dword ptr [esi + 0xc], 0x9eab7c
// 0079b3b3  c7461084ab9e00       mov dword ptr [esi + 0x10], 0x9eab84
// 0079b3ba  e8e1f1ffff           call 0x79a5a0
// 0079b3bf  83c40c               add esp, 0xc
// 0079b3c2  5f                   pop edi
// 0079b3c3  5d                   pop ebp
// 0079b3c4  895e18               mov dword ptr [esi + 0x18], ebx
// 0079b3c7  8d4301               lea eax, [ebx + 1]
// 0079b3ca  5b                   pop ebx
// 0079b3cb  59                   pop ecx
// 0079b3cc  c3                   ret 
// 0079b3cd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0079b3d1  8a01                 mov al, byte ptr [ecx]
// 0079b3d3  3ac3                 cmp al, bl
// 0079b3d5  0f8496000000         je 0x79b471
// 0079b3db  eb03                 jmp 0x79b3e0
// 0079b3dd  8d4900               lea ecx, [ecx]
// 0079b3e0  0fbec0               movsx eax, al
// 0079b3e3  83c0b4               add eax, -0x4c
// 0079b3e6  83f829               cmp eax, 0x29
// 0079b3e9  776f                 ja 0x79b45a
// 0079b3eb  0fb69094b47900       movzx edx, byte ptr [eax + 0x79b494]
// 0079b3f2  ff24957cb47900       jmp dword ptr [edx*4 + 0x79b47c]
// 0079b3f9  8bcf                 mov ecx, edi
// 0079b3fb  8bc6                 mov eax, esi
// 0079b3fd  e82ef5ffff           call 0x79a930
// 0079b402  eb5a                 jmp 0x79b45e
// 0079b404  3beb                 cmp ebp, ebx
// 0079b406  7410                 je 0x79b418
// 0079b408  8b542414             mov edx, dword ptr [esp + 0x14]
// 0079b40c  8bc5                 mov eax, ebp
// 0079b40e  e8ddf2ffff           call 0x79a6f0
// 0079b413  894614               mov dword ptr [esi + 0x14], eax
// 0079b416  eb46                 jmp 0x79b45e
// 0079b418  83c8ff               or eax, 0xffffffff
// 0079b41b  894614               mov dword ptr [esi + 0x14], eax
// 0079b41e  eb3e                 jmp 0x79b45e
// 0079b420  0fb64707             movzx eax, byte ptr [edi + 7]
// 0079b424  894618               mov dword ptr [esi + 0x18], eax
// 0079b427  eb35                 jmp 0x79b45e
// 0079b429  3beb                 cmp ebp, ebx
// 0079b42b  7418                 je 0x79b445
// 0079b42d  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0079b431  8d4e04               lea ecx, [esi + 4]
// 0079b434  51                   push ecx
// 0079b435  8bcd                 mov ecx, ebp
// 0079b437  e864fdffff           call 0x79b1a0
// 0079b43c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0079b440  83c404               add esp, 4
// 0079b443  eb02                 jmp 0x79b447
// 0079b445  33c0                 xor eax, eax
// 0079b447  894608               mov dword ptr [esi + 8], eax
// 0079b44a  3bc3                 cmp eax, ebx
// 0079b44c  7510                 jne 0x79b45e
// 0079b44e  c7460856fd9900       mov dword ptr [esi + 8], 0x99fd56
// 0079b455  895e04               mov dword ptr [esi + 4], ebx
// 0079b458  eb04                 jmp 0x79b45e
// 0079b45a  895c240c             mov dword ptr [esp + 0xc], ebx
// 0079b45e  8b442418             mov eax, dword ptr [esp + 0x18]
// 0079b462  40                   inc eax
// 0079b463  89442418             mov dword ptr [esp + 0x18], eax
// 0079b467  8a00                 mov al, byte ptr [eax]
// 0079b469  3ac3                 cmp al, bl
// 0079b46b  0f856fffffff         jne 0x79b3e0
// 0079b471  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0079b475  5f                   pop edi
// 0079b476  5d                   pop ebp
// 0079b477  5b                   pop ebx
// 0079b478  59                   pop ecx
// 0079b479  c3                   ret 
// 0079b47a  8bff                 mov edi, edi
// 0079b47c  5e                   pop esi
// 0079b47d  b479                 mov ah, 0x79
// 0079b47f  00f9                 add cl, bh
// 0079b481  b379                 mov bl, 0x79
// 0079b483  0004b4               add byte ptr [esp + esi*4], al
// 0079b486  7900                 jns 0x79b488
// 0079b488  29b4790020b479       sub dword ptr [ecx + edi*2 + 0x79b42000], esi
// 0079b48f  005ab4               add byte ptr [edx - 0x4c], bl
// 0079b492  7900                 jns 0x79b494
// 0079b494  000505050505         add byte ptr [0x5050505], al
// 0079b49a  0501050505           add eax, 0x5050501
// 0079b49f  0505050505           add eax, 0x5050505
// 0079b4a4  0505050505           add eax, 0x5050505
// 0079b4a9  0505050505           add eax, 0x5050505
// 0079b4ae  000505050505         add byte ptr [0x5050505], al
// 0079b4b4  020503050505         add al, byte ptr [0x5050503]
// library lua-5.1/ldebug.c (function _auxgetinfo)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
