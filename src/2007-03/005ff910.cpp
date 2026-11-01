// from server: 100% by auto
// roc 2007-03 005ff910  unit: seg_005f0000  size: 278 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ff910
//
// 005ff910  83ec0c               sub esp, 0xc
// 005ff913  55                   push ebp
// 005ff914  56                   push esi
// 005ff915  8bf0                 mov esi, eax
// 005ff917  8b6e30               mov ebp, dword ptr [esi + 0x30]
// 005ff91a  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 005ff922  c644241201           mov byte ptr [esp + 0x12], 1
// 005ff927  8a4532               mov al, byte ptr [ebp + 0x32]
// 005ff92a  88442410             mov byte ptr [esp + 0x10], al
// 005ff92e  c644241100           mov byte ptr [esp + 0x11], 0
// 005ff933  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005ff936  8d542408             lea edx, [esp + 8]
// 005ff93a  894c2408             mov dword ptr [esp + 8], ecx
// 005ff93e  56                   push esi
// 005ff93f  895514               mov dword ptr [ebp + 0x14], edx
// 005ff942  e8592a0000           call 0x6023a0
// 005ff947  83c404               add esp, 4
// 005ff94a  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 005ff951  7424                 je 0x5ff977
// 005ff953  681d010000           push 0x11d
// 005ff958  56                   push esi
// 005ff959  e812150000           call 0x600e70
// 005ff95e  50                   push eax
// 005ff95f  8b4634               mov eax, dword ptr [esi + 0x34]
// 005ff962  6828047c00           push 0x7c0428
// 005ff967  50                   push eax
// 005ff968  e8d38effff           call 0x5f8840
// 005ff96d  50                   push eax
// 005ff96e  56                   push esi
// 005ff96f  e8fc150000           call 0x600f70
// 005ff974  83c41c               add esp, 0x1c
// 005ff977  57                   push edi
// 005ff978  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005ff97b  56                   push esi
// 005ff97c  e81f2a0000           call 0x6023a0
// 005ff981  8b4610               mov eax, dword ptr [esi + 0x10]
// 005ff984  83c404               add esp, 4
// 005ff987  83f82c               cmp eax, 0x2c
// 005ff98a  742e                 je 0x5ff9ba
// 005ff98c  83f83d               cmp eax, 0x3d
// 005ff98f  7417                 je 0x5ff9a8
// 005ff991  3d0b010000           cmp eax, 0x10b
// 005ff996  7422                 je 0x5ff9ba
// 005ff998  6864067c00           push 0x7c0664
// 005ff99d  56                   push esi
// 005ff99e  e8cd150000           call 0x600f70
// 005ff9a3  83c408               add esp, 8
// 005ff9a6  eb1f                 jmp 0x5ff9c7
// 005ff9a8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005ff9ac  51                   push ecx
// 005ff9ad  57                   push edi
// 005ff9ae  8bfe                 mov edi, esi
// 005ff9b0  e8abfaffff           call 0x5ff460
// 005ff9b5  83c408               add esp, 8
// 005ff9b8  eb0d                 jmp 0x5ff9c7
// 005ff9ba  53                   push ebx
// 005ff9bb  57                   push edi
// 005ff9bc  8bde                 mov ebx, esi
// 005ff9be  e8cdfcffff           call 0x5ff690
// 005ff9c3  83c404               add esp, 4
// 005ff9c6  5b                   pop ebx
// 005ff9c7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005ff9cb  6808010000           push 0x108
// 005ff9d0  bf06010000           mov edi, 0x106
// 005ff9d5  e8f6daffff           call 0x5fd4d0
// 005ff9da  8b7514               mov esi, dword ptr [ebp + 0x14]
// 005ff9dd  8b16                 mov edx, dword ptr [esi]
// 005ff9df  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005ff9e2  895514               mov dword ptr [ebp + 0x14], edx
// 005ff9e5  0fb65608             movzx edx, byte ptr [esi + 8]
// 005ff9e9  83c404               add esp, 4
// 005ff9ec  e8bfdcffff           call 0x5fd6b0
// 005ff9f1  807e0900             cmp byte ptr [esi + 9], 0
// 005ff9f5  5f                   pop edi
// 005ff9f6  7414                 je 0x5ffa0c
// 005ff9f8  0fb64608             movzx eax, byte ptr [esi + 8]
// 005ff9fc  6a00                 push 0
// 005ff9fe  6a00                 push 0
// 005ffa00  50                   push eax
// 005ffa01  6a23                 push 0x23
// 005ffa03  55                   push ebp
// 005ffa04  e8a7510100           call 0x614bb0
// 005ffa09  83c414               add esp, 0x14
// 005ffa0c  0fb64d32             movzx ecx, byte ptr [ebp + 0x32]
// 005ffa10  894d24               mov dword ptr [ebp + 0x24], ecx
// 005ffa13  8b5604               mov edx, dword ptr [esi + 4]
// 005ffa16  52                   push edx
// 005ffa17  55                   push ebp
// 005ffa18  e8f3530100           call 0x614e10
// 005ffa1d  83c408               add esp, 8
// 005ffa20  5e                   pop esi
// 005ffa21  5d                   pop ebp
// 005ffa22  83c40c               add esp, 0xc
// 005ffa25  c3                   ret 
// library lua-5.1.1/lparser.c (function _forstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
