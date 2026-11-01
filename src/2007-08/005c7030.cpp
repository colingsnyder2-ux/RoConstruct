// from server: 100% by auto
// roc 2007-08 005c7030  unit: lua_exception  size: 334 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c7030
//
// 005c7030  51                   push ecx
// 005c7031  53                   push ebx
// 005c7032  55                   push ebp
// 005c7033  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 005c7037  57                   push edi
// 005c7038  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005c703c  33db                 xor ebx, ebx
// 005c703e  3bfb                 cmp edi, ebx
// 005c7040  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 005c7048  7545                 jne 0x5c708f
// 005c704a  b854597800           mov eax, 0x785954
// 005c704f  894608               mov dword ptr [esi + 8], eax
// 005c7052  894604               mov dword ptr [esi + 4], eax
// 005c7055  83c8ff               or eax, 0xffffffff
// 005c7058  6a3c                 push 0x3c
// 005c705a  894614               mov dword ptr [esi + 0x14], eax
// 005c705d  89461c               mov dword ptr [esi + 0x1c], eax
// 005c7060  894620               mov dword ptr [esi + 0x20], eax
// 005c7063  8d4624               lea eax, [esi + 0x24]
// 005c7066  6848977b00           push 0x7b9748
// 005c706b  50                   push eax
// 005c706c  c7460c40977b00       mov dword ptr [esi + 0xc], 0x7b9740
// 005c7073  c7461048977b00       mov dword ptr [esi + 0x10], 0x7b9748
// 005c707a  e8317e0400           call 0x60eeb0
// 005c707f  83c40c               add esp, 0xc
// 005c7082  5f                   pop edi
// 005c7083  5d                   pop ebp
// 005c7084  895e18               mov dword ptr [esi + 0x18], ebx
// 005c7087  b801000000           mov eax, 1
// 005c708c  5b                   pop ebx
// 005c708d  59                   pop ecx
// 005c708e  c3                   ret 
// 005c708f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005c7093  8a01                 mov al, byte ptr [ecx]
// 005c7095  3ac3                 cmp al, bl
// 005c7097  0f8496000000         je 0x5c7133
// 005c709d  8d4900               lea ecx, [ecx]
// 005c70a0  0fbec0               movsx eax, al
// 005c70a3  83c0b4               add eax, -0x4c
// 005c70a6  83f829               cmp eax, 0x29
// 005c70a9  776f                 ja 0x5c711a
// 005c70ab  0fb69054715c00       movzx edx, byte ptr [eax + 0x5c7154]
// 005c70b2  ff24953c715c00       jmp dword ptr [edx*4 + 0x5c713c]
// 005c70b9  8bcf                 mov ecx, edi
// 005c70bb  8bc6                 mov eax, esi
// 005c70bd  e8cef5ffff           call 0x5c6690
// 005c70c2  eb5a                 jmp 0x5c711e
// 005c70c4  3beb                 cmp ebp, ebx
// 005c70c6  7410                 je 0x5c70d8
// 005c70c8  8b542414             mov edx, dword ptr [esp + 0x14]
// 005c70cc  8bc5                 mov eax, ebp
// 005c70ce  e8edf4ffff           call 0x5c65c0
// 005c70d3  894614               mov dword ptr [esi + 0x14], eax
// 005c70d6  eb46                 jmp 0x5c711e
// 005c70d8  83c8ff               or eax, 0xffffffff
// 005c70db  894614               mov dword ptr [esi + 0x14], eax
// 005c70de  eb3e                 jmp 0x5c711e
// 005c70e0  0fb64707             movzx eax, byte ptr [edi + 7]
// 005c70e4  894618               mov dword ptr [esi + 0x18], eax
// 005c70e7  eb35                 jmp 0x5c711e
// 005c70e9  3beb                 cmp ebp, ebx
// 005c70eb  7418                 je 0x5c7105
// 005c70ed  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005c70f1  8d4e04               lea ecx, [esi + 4]
// 005c70f4  51                   push ecx
// 005c70f5  8bcd                 mov ecx, ebp
// 005c70f7  e864fdffff           call 0x5c6e60
// 005c70fc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005c7100  83c404               add esp, 4
// 005c7103  eb02                 jmp 0x5c7107
// 005c7105  33c0                 xor eax, eax
// 005c7107  3bc3                 cmp eax, ebx
// 005c7109  894608               mov dword ptr [esi + 8], eax
// 005c710c  7510                 jne 0x5c711e
// 005c710e  c7460854597800       mov dword ptr [esi + 8], 0x785954
// 005c7115  895e04               mov dword ptr [esi + 4], ebx
// 005c7118  eb04                 jmp 0x5c711e
// 005c711a  895c240c             mov dword ptr [esp + 0xc], ebx
// 005c711e  8b442418             mov eax, dword ptr [esp + 0x18]
// 005c7122  83c001               add eax, 1
// 005c7125  89442418             mov dword ptr [esp + 0x18], eax
// 005c7129  8a00                 mov al, byte ptr [eax]
// 005c712b  3ac3                 cmp al, bl
// 005c712d  0f856dffffff         jne 0x5c70a0
// 005c7133  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005c7137  5f                   pop edi
// 005c7138  5d                   pop ebp
// 005c7139  5b                   pop ebx
// 005c713a  59                   pop ecx
// 005c713b  c3                   ret 
// 005c713c  1e                   push ds
// 005c713d  715c                 jno 0x5c719b
// 005c713f  00b9705c00c4         add byte ptr [ecx - 0x3bffa390], bh
// 005c7145  705c                 jo 0x5c71a3
// 005c7147  00e9                 add cl, ch
// 005c7149  705c                 jo 0x5c71a7
// 005c714b  00e0                 add al, ah
// 005c714d  705c                 jo 0x5c71ab
// 005c714f  001a                 add byte ptr [edx], bl
// 005c7151  715c                 jno 0x5c71af
// 005c7153  0000                 add byte ptr [eax], al
// 005c7155  0505050505           add eax, 0x5050505
// 005c715a  0501050505           add eax, 0x5050501
// 005c715f  0505050505           add eax, 0x5050505
// 005c7164  0505050505           add eax, 0x5050505
// 005c7169  0505050505           add eax, 0x5050505
// 005c716e  000505050505         add byte ptr [0x5050505], al
// 005c7174  020503050505         add al, byte ptr [0x5050503]
// library lua-5.1/ldebug.c (function _auxgetinfo)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
