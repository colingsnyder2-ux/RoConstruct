// from server: 100% by auto
// roc 2009-12 007dd0d0  unit: RBX::GroupDragTool  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dd0d0
//
// 007dd0d0  56                   push esi
// 007dd0d1  57                   push edi
// 007dd0d2  8bf8                 mov edi, eax
// 007dd0d4  8bf1                 mov esi, ecx
// 007dd0d6  57                   push edi
// 007dd0d7  56                   push esi
// 007dd0d8  e8a3f7ffff           call 0x7dc880
// 007dd0dd  8b07                 mov eax, dword ptr [edi]
// 007dd0df  48                   dec eax
// 007dd0e0  83c408               add esp, 8
// 007dd0e3  83f809               cmp eax, 9
// 007dd0e6  7723                 ja 0x7dd10b
// 007dd0e8  0fb68054d17d00       movzx eax, byte ptr [eax + 0x7dd154]
// 007dd0ef  ff248544d17d00       jmp dword ptr [eax*4 + 0x7dd144]
// 007dd0f6  83c8ff               or eax, 0xffffffff
// 007dd0f9  eb1c                 jmp 0x7dd117
// 007dd0fb  56                   push esi
// 007dd0fc  e88ff6ffff           call 0x7dc790
// 007dd101  83c404               add esp, 4
// 007dd104  eb11                 jmp 0x7dd117
// 007dd106  8b4708               mov eax, dword ptr [edi + 8]
// 007dd109  eb0c                 jmp 0x7dd117
// 007dd10b  53                   push ebx
// 007dd10c  bb01000000           mov ebx, 1
// 007dd111  e89afeffff           call 0x7dcfb0
// 007dd116  5b                   pop ebx
// 007dd117  50                   push eax
// 007dd118  8d4f10               lea ecx, [edi + 0x10]
// 007dd11b  51                   push ecx
// 007dd11c  56                   push esi
// 007dd11d  e8aeefffff           call 0x7dc0d0
// 007dd122  8b4714               mov eax, dword ptr [edi + 0x14]
// 007dd125  8b5618               mov edx, dword ptr [esi + 0x18]
// 007dd128  50                   push eax
// 007dd129  8d4620               lea eax, [esi + 0x20]
// 007dd12c  50                   push eax
// 007dd12d  56                   push esi
// 007dd12e  89561c               mov dword ptr [esi + 0x1c], edx
// 007dd131  e89aefffff           call 0x7dc0d0
// 007dd136  83c418               add esp, 0x18
// 007dd139  c74714ffffffff       mov dword ptr [edi + 0x14], 0xffffffff
// 007dd140  5f                   pop edi
// 007dd141  5e                   pop esi
// 007dd142  c3                   ret 
// 007dd143  90                   nop 
// 007dd144  f6d0                 not al
// 007dd146  7d00                 jge 0x7dd148
// 007dd148  fb                   sti 
// 007dd149  d07d00               sar byte ptr [ebp], 1
// 007dd14c  06                   push es
// 007dd14d  d17d00               sar dword ptr [ebp], 1
// 007dd150  0bd1                 or edx, ecx
// 007dd152  7d00                 jge 0x7dd154
// 007dd154  0001                 add byte ptr [ecx], al
// 007dd156  0003                 add byte ptr [ebx], al
// 007dd158  0303                 add eax, dword ptr [ebx]
// 007dd15a  0303                 add eax, dword ptr [ebx]
// 007dd15c  0302                 add eax, dword ptr [edx]
// library lua-5.1/lcode.c (function _luaK_goiffalse)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
