// from server: 100% by auto
// roc 2009-12 007d0b90  unit: RBX::PartDropTool  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d0b90
//
// 007d0b90  53                   push ebx
// 007d0b91  55                   push ebp
// 007d0b92  56                   push esi
// 007d0b93  57                   push edi
// 007d0b94  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 007d0b98  8bc7                 mov eax, edi
// 007d0b9a  c1e805               shr eax, 5
// 007d0b9d  40                   inc eax
// 007d0b9e  8bdf                 mov ebx, edi
// 007d0ba0  8bcf                 mov ecx, edi
// 007d0ba2  3bf8                 cmp edi, eax
// 007d0ba4  7229                 jb 0x7d0bcf
// 007d0ba6  eb08                 jmp 0x7d0bb0
// 007d0ba8  8da42400000000       lea esp, [esp]
// 007d0baf  90                   nop 
// 007d0bb0  8b542418             mov edx, dword ptr [esp + 0x18]
// 007d0bb4  0fb6540aff           movzx edx, byte ptr [edx + ecx - 1]
// 007d0bb9  8bf3                 mov esi, ebx
// 007d0bbb  c1e605               shl esi, 5
// 007d0bbe  03d6                 add edx, esi
// 007d0bc0  8bf3                 mov esi, ebx
// 007d0bc2  c1ee02               shr esi, 2
// 007d0bc5  03d6                 add edx, esi
// 007d0bc7  2bc8                 sub ecx, eax
// 007d0bc9  33da                 xor ebx, edx
// 007d0bcb  3bc8                 cmp ecx, eax
// 007d0bcd  73e1                 jae 0x7d0bb0
// 007d0bcf  8b442414             mov eax, dword ptr [esp + 0x14]
// 007d0bd3  8b4010               mov eax, dword ptr [eax + 0x10]
// 007d0bd6  8b4808               mov ecx, dword ptr [eax + 8]
// 007d0bd9  8b10                 mov edx, dword ptr [eax]
// 007d0bdb  49                   dec ecx
// 007d0bdc  23cb                 and ecx, ebx
// 007d0bde  8b2c8a               mov ebp, dword ptr [edx + ecx*4]
// 007d0be1  85ed                 test ebp, ebp
// 007d0be3  7452                 je 0x7d0c37
// 007d0be5  397d0c               cmp dword ptr [ebp + 0xc], edi
// 007d0be8  7546                 jne 0x7d0c30
// 007d0bea  8b742418             mov esi, dword ptr [esp + 0x18]
// 007d0bee  8bcf                 mov ecx, edi
// 007d0bf0  8d5510               lea edx, [ebp + 0x10]
// 007d0bf3  83ff04               cmp edi, 4
// 007d0bf6  7214                 jb 0x7d0c0c
// 007d0bf8  8b06                 mov eax, dword ptr [esi]
// 007d0bfa  3b02                 cmp eax, dword ptr [edx]
// 007d0bfc  7532                 jne 0x7d0c30
// 007d0bfe  83e904               sub ecx, 4
// 007d0c01  83c204               add edx, 4
// 007d0c04  83c604               add esi, 4
// 007d0c07  83f904               cmp ecx, 4
// 007d0c0a  73ec                 jae 0x7d0bf8
// 007d0c0c  85c9                 test ecx, ecx
// 007d0c0e  743e                 je 0x7d0c4e
// 007d0c10  8a02                 mov al, byte ptr [edx]
// 007d0c12  3a06                 cmp al, byte ptr [esi]
// 007d0c14  751a                 jne 0x7d0c30
// 007d0c16  83f901               cmp ecx, 1
// 007d0c19  7633                 jbe 0x7d0c4e
// 007d0c1b  8a4201               mov al, byte ptr [edx + 1]
// 007d0c1e  3a4601               cmp al, byte ptr [esi + 1]
// 007d0c21  750d                 jne 0x7d0c30
// 007d0c23  83f902               cmp ecx, 2
// 007d0c26  7626                 jbe 0x7d0c4e
// 007d0c28  8a4a02               mov cl, byte ptr [edx + 2]
// 007d0c2b  3a4e02               cmp cl, byte ptr [esi + 2]
// 007d0c2e  741e                 je 0x7d0c4e
// 007d0c30  8b6d00               mov ebp, dword ptr [ebp]
// 007d0c33  85ed                 test ebp, ebp
// 007d0c35  75ae                 jne 0x7d0be5
// 007d0c37  8b542418             mov edx, dword ptr [esp + 0x18]
// 007d0c3b  53                   push ebx
// 007d0c3c  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007d0c40  52                   push edx
// 007d0c41  e8aafeffff           call 0x7d0af0
// 007d0c46  83c408               add esp, 8
// 007d0c49  5f                   pop edi
// 007d0c4a  5e                   pop esi
// 007d0c4b  5d                   pop ebp
// 007d0c4c  5b                   pop ebx
// 007d0c4d  c3                   ret 
// 007d0c4e  8b542414             mov edx, dword ptr [esp + 0x14]
// 007d0c52  8b4a10               mov ecx, dword ptr [edx + 0x10]
// 007d0c55  0fb65114             movzx edx, byte ptr [ecx + 0x14]
// 007d0c59  8a4505               mov al, byte ptr [ebp + 5]
// 007d0c5c  0fb6c8               movzx ecx, al
// 007d0c5f  f7d2                 not edx
// 007d0c61  83e103               and ecx, 3
// 007d0c64  84d1                 test cl, dl
// 007d0c66  7405                 je 0x7d0c6d
// 007d0c68  3403                 xor al, 3
// 007d0c6a  884505               mov byte ptr [ebp + 5], al
// 007d0c6d  5f                   pop edi
// 007d0c6e  5e                   pop esi
// 007d0c6f  8bc5                 mov eax, ebp
// 007d0c71  5d                   pop ebp
// 007d0c72  5b                   pop ebx
// 007d0c73  c3                   ret 
// library lua-5.1/lstring.c (function _luaS_newlstr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstring.c
