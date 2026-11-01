// from server: 100% by auto
// roc 2010-06 00733bd0  unit: seg_00730000  size: 334 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00733bd0
//
// 00733bd0  51                   push ecx
// 00733bd1  53                   push ebx
// 00733bd2  55                   push ebp
// 00733bd3  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00733bd7  57                   push edi
// 00733bd8  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00733bdc  33db                 xor ebx, ebx
// 00733bde  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00733be6  3bfb                 cmp edi, ebx
// 00733be8  7543                 jne 0x733c2d
// 00733bea  b8fe08a000           mov eax, 0xa008fe
// 00733bef  894608               mov dword ptr [esi + 8], eax
// 00733bf2  894604               mov dword ptr [esi + 4], eax
// 00733bf5  83c8ff               or eax, 0xffffffff
// 00733bf8  6a3c                 push 0x3c
// 00733bfa  894614               mov dword ptr [esi + 0x14], eax
// 00733bfd  89461c               mov dword ptr [esi + 0x1c], eax
// 00733c00  894620               mov dword ptr [esi + 0x20], eax
// 00733c03  8d4624               lea eax, [esi + 0x24]
// 00733c06  68d8dda400           push 0xa4ddd8
// 00733c0b  50                   push eax
// 00733c0c  c7460cd0dda400       mov dword ptr [esi + 0xc], 0xa4ddd0
// 00733c13  c74610d8dda400       mov dword ptr [esi + 0x10], 0xa4ddd8
// 00733c1a  e8e1f1ffff           call 0x732e00
// 00733c1f  83c40c               add esp, 0xc
// 00733c22  5f                   pop edi
// 00733c23  5d                   pop ebp
// 00733c24  895e18               mov dword ptr [esi + 0x18], ebx
// 00733c27  8d4301               lea eax, [ebx + 1]
// 00733c2a  5b                   pop ebx
// 00733c2b  59                   pop ecx
// 00733c2c  c3                   ret 
// 00733c2d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00733c31  8a01                 mov al, byte ptr [ecx]
// 00733c33  3ac3                 cmp al, bl
// 00733c35  0f8496000000         je 0x733cd1
// 00733c3b  eb03                 jmp 0x733c40
// 00733c3d  8d4900               lea ecx, [ecx]
// 00733c40  0fbec0               movsx eax, al
// 00733c43  83c0b4               add eax, -0x4c
// 00733c46  83f829               cmp eax, 0x29
// 00733c49  776f                 ja 0x733cba
// 00733c4b  0fb690f43c7300       movzx edx, byte ptr [eax + 0x733cf4]
// 00733c52  ff2495dc3c7300       jmp dword ptr [edx*4 + 0x733cdc]
// 00733c59  8bcf                 mov ecx, edi
// 00733c5b  8bc6                 mov eax, esi
// 00733c5d  e82ef5ffff           call 0x733190
// 00733c62  eb5a                 jmp 0x733cbe
// 00733c64  3beb                 cmp ebp, ebx
// 00733c66  7410                 je 0x733c78
// 00733c68  8b542414             mov edx, dword ptr [esp + 0x14]
// 00733c6c  8bc5                 mov eax, ebp
// 00733c6e  e8ddf2ffff           call 0x732f50
// 00733c73  894614               mov dword ptr [esi + 0x14], eax
// 00733c76  eb46                 jmp 0x733cbe
// 00733c78  83c8ff               or eax, 0xffffffff
// 00733c7b  894614               mov dword ptr [esi + 0x14], eax
// 00733c7e  eb3e                 jmp 0x733cbe
// 00733c80  0fb64707             movzx eax, byte ptr [edi + 7]
// 00733c84  894618               mov dword ptr [esi + 0x18], eax
// 00733c87  eb35                 jmp 0x733cbe
// 00733c89  3beb                 cmp ebp, ebx
// 00733c8b  7418                 je 0x733ca5
// 00733c8d  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00733c91  8d4e04               lea ecx, [esi + 4]
// 00733c94  51                   push ecx
// 00733c95  8bcd                 mov ecx, ebp
// 00733c97  e864fdffff           call 0x733a00
// 00733c9c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00733ca0  83c404               add esp, 4
// 00733ca3  eb02                 jmp 0x733ca7
// 00733ca5  33c0                 xor eax, eax
// 00733ca7  894608               mov dword ptr [esi + 8], eax
// 00733caa  3bc3                 cmp eax, ebx
// 00733cac  7510                 jne 0x733cbe
// 00733cae  c74608fe08a000       mov dword ptr [esi + 8], 0xa008fe
// 00733cb5  895e04               mov dword ptr [esi + 4], ebx
// 00733cb8  eb04                 jmp 0x733cbe
// 00733cba  895c240c             mov dword ptr [esp + 0xc], ebx
// 00733cbe  8b442418             mov eax, dword ptr [esp + 0x18]
// 00733cc2  40                   inc eax
// 00733cc3  89442418             mov dword ptr [esp + 0x18], eax
// 00733cc7  8a00                 mov al, byte ptr [eax]
// 00733cc9  3ac3                 cmp al, bl
// 00733ccb  0f856fffffff         jne 0x733c40
// 00733cd1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00733cd5  5f                   pop edi
// 00733cd6  5d                   pop ebp
// 00733cd7  5b                   pop ebx
// 00733cd8  59                   pop ecx
// 00733cd9  c3                   ret 
// 00733cda  8bff                 mov edi, edi
// 00733cdc  be3c730059           mov esi, 0x5900733c
// 00733ce1  3c73                 cmp al, 0x73
// 00733ce3  00643c73             add byte ptr [esp + edi + 0x73], ah
// 00733ce7  00893c730080         add byte ptr [ecx - 0x7fff8cc4], cl
// 00733ced  3c73                 cmp al, 0x73
// 00733cef  00ba3c730000         add byte ptr [edx + 0x733c], bh
// 00733cf5  0505050505           add eax, 0x5050505
// 00733cfa  0501050505           add eax, 0x5050501
// 00733cff  0505050505           add eax, 0x5050505
// 00733d04  0505050505           add eax, 0x5050505
// 00733d09  0505050505           add eax, 0x5050505
// 00733d0e  000505050505         add byte ptr [0x5050505], al
// 00733d14  020503050505         add al, byte ptr [0x5050503]
// library lua-5.1/ldebug.c (function _auxgetinfo)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
