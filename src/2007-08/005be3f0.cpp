// from server: 100% by auto
// roc 2007-08 005be3f0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be3f0
//
// 005be3f0  8b442408             mov eax, dword ptr [esp + 8]
// 005be3f4  53                   push ebx
// 005be3f5  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005be3f9  56                   push esi
// 005be3fa  8b7310               mov esi, dword ptr [ebx + 0x10]
// 005be3fd  57                   push edi
// 005be3fe  33ff                 xor edi, edi
// 005be400  83f807               cmp eax, 7
// 005be403  0f87ab000000         ja 0x5be4b4
// 005be409  ff2485c0e45b00       jmp dword ptr [eax*4 + 0x5be4c0]
// 005be410  8bc7                 mov eax, edi
// 005be412  5f                   pop edi
// 005be413  c74640fdffffff       mov dword ptr [esi + 0x40], 0xfffffffd
// 005be41a  5e                   pop esi
// 005be41b  5b                   pop ebx
// 005be41c  c3                   ret 
// 005be41d  8b4644               mov eax, dword ptr [esi + 0x44]
// 005be420  894640               mov dword ptr [esi + 0x40], eax
// 005be423  8bc7                 mov eax, edi
// 005be425  5f                   pop edi
// 005be426  5e                   pop esi
// 005be427  5b                   pop ebx
// 005be428  c3                   ret 
// 005be429  53                   push ebx
// 005be42a  e8511a0500           call 0x60fe80
// 005be42f  83c404               add esp, 4
// 005be432  8bc7                 mov eax, edi
// 005be434  5f                   pop edi
// 005be435  5e                   pop esi
// 005be436  5b                   pop ebx
// 005be437  c3                   ret 
// 005be438  8b7e44               mov edi, dword ptr [esi + 0x44]
// 005be43b  c1ef0a               shr edi, 0xa
// 005be43e  8bc7                 mov eax, edi
// 005be440  5f                   pop edi
// 005be441  5e                   pop esi
// 005be442  5b                   pop ebx
// 005be443  c3                   ret 
// 005be444  8b7e44               mov edi, dword ptr [esi + 0x44]
// 005be447  81e7ff030000         and edi, 0x3ff
// 005be44d  8bc7                 mov eax, edi
// 005be44f  5f                   pop edi
// 005be450  5e                   pop esi
// 005be451  5b                   pop ebx
// 005be452  c3                   ret 
// 005be453  8b442418             mov eax, dword ptr [esp + 0x18]
// 005be457  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 005be45a  c1e00a               shl eax, 0xa
// 005be45d  3bc1                 cmp eax, ecx
// 005be45f  7709                 ja 0x5be46a
// 005be461  8bd1                 mov edx, ecx
// 005be463  2bd0                 sub edx, eax
// 005be465  895640               mov dword ptr [esi + 0x40], edx
// 005be468  eb03                 jmp 0x5be46d
// 005be46a  897e40               mov dword ptr [esi + 0x40], edi
// 005be46d  394e40               cmp dword ptr [esi + 0x40], ecx
// 005be470  7711                 ja 0x5be483
// 005be472  53                   push ebx
// 005be473  e888190500           call 0x60fe00
// 005be478  8b4640               mov eax, dword ptr [esi + 0x40]
// 005be47b  83c404               add esp, 4
// 005be47e  3b4644               cmp eax, dword ptr [esi + 0x44]
// 005be481  76ef                 jbe 0x5be472
// 005be483  807e1500             cmp byte ptr [esi + 0x15], 0
// 005be487  752e                 jne 0x5be4b7
// 005be489  bf01000000           mov edi, 1
// 005be48e  8bc7                 mov eax, edi
// 005be490  5f                   pop edi
// 005be491  5e                   pop esi
// 005be492  5b                   pop ebx
// 005be493  c3                   ret 
// 005be494  8b7e50               mov edi, dword ptr [esi + 0x50]
// 005be497  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005be49b  8bc7                 mov eax, edi
// 005be49d  5f                   pop edi
// 005be49e  894e50               mov dword ptr [esi + 0x50], ecx
// 005be4a1  5e                   pop esi
// 005be4a2  5b                   pop ebx
// 005be4a3  c3                   ret 
// 005be4a4  8b7e54               mov edi, dword ptr [esi + 0x54]
// 005be4a7  8b542418             mov edx, dword ptr [esp + 0x18]
// 005be4ab  8bc7                 mov eax, edi
// 005be4ad  5f                   pop edi
// 005be4ae  895654               mov dword ptr [esi + 0x54], edx
// 005be4b1  5e                   pop esi
// 005be4b2  5b                   pop ebx
// 005be4b3  c3                   ret 
// 005be4b4  83cfff               or edi, 0xffffffff
// 005be4b7  8bc7                 mov eax, edi
// 005be4b9  5f                   pop edi
// 005be4ba  5e                   pop esi
// 005be4bb  5b                   pop ebx
// 005be4bc  c3                   ret 
// 005be4bd  8d4900               lea ecx, [ecx]
// 005be4c0  10e4                 adc ah, ah
// 005be4c2  5b                   pop ebx
// 005be4c3  001de45b0029         add byte ptr [0x29005be4], bl
// 005be4c9  e45b                 in al, 0x5b
// 005be4cb  0038                 add byte ptr [eax], bh
// 005be4cd  e45b                 in al, 0x5b
// 005be4cf  0044e45b             add byte ptr [esp + 0x5b], al
// 005be4d3  0053e4               add byte ptr [ebx - 0x1c], dl
// 005be4d6  5b                   pop ebx
// 005be4d7  0094e45b00a4e4       add byte ptr [esp - 0x1b5bffa5], dl
// 005be4de  5b                   pop ebx
// library lua-5.1/lapi.c (function _lua_gc)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
