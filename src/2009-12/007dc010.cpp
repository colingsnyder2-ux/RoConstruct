// from server: 100% by auto
// roc 2009-12 007dc010  unit: RBX::GroupDragTool  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc010
//
// 007dc010  51                   push ecx
// 007dc011  55                   push ebp
// 007dc012  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007dc016  57                   push edi
// 007dc017  8bf8                 mov edi, eax
// 007dc019  83ffff               cmp edi, -1
// 007dc01c  0f84a4000000         je 0x7dc0c6
// 007dc022  53                   push ebx
// 007dc023  56                   push esi
// 007dc024  eb0a                 jmp 0x7dc030
// 007dc026  8da42400000000       lea esp, [esp]
// 007dc02d  8d4900               lea ecx, [ecx]
// 007dc030  8b4500               mov eax, dword ptr [ebp]
// 007dc033  8b480c               mov ecx, dword ptr [eax + 0xc]
// 007dc036  8d34bd00000000       lea esi, [edi*4]
// 007dc03d  8b040e               mov eax, dword ptr [esi + ecx]
// 007dc040  c1e80e               shr eax, 0xe
// 007dc043  2dffff0100           sub eax, 0x1ffff
// 007dc048  83f8ff               cmp eax, -1
// 007dc04b  7506                 jne 0x7dc053
// 007dc04d  89442410             mov dword ptr [esp + 0x10], eax
// 007dc051  eb08                 jmp 0x7dc05b
// 007dc053  8d543801             lea edx, [eax + edi + 1]
// 007dc057  89542410             mov dword ptr [esp + 0x10], edx
// 007dc05b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007dc05f  8bc7                 mov eax, edi
// 007dc061  8bd5                 mov edx, ebp
// 007dc063  e898feffff           call 0x7dbf00
// 007dc068  85c0                 test eax, eax
// 007dc06a  8b4500               mov eax, dword ptr [ebp]
// 007dc06d  8b580c               mov ebx, dword ptr [eax + 0xc]
// 007dc070  7408                 je 0x7dc07a
// 007dc072  03de                 add ebx, esi
// 007dc074  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007dc078  eb06                 jmp 0x7dc080
// 007dc07a  03de                 add ebx, esi
// 007dc07c  8b742424             mov esi, dword ptr [esp + 0x24]
// 007dc080  2bf7                 sub esi, edi
// 007dc082  4e                   dec esi
// 007dc083  8bc6                 mov eax, esi
// 007dc085  99                   cdq 
// 007dc086  33c2                 xor eax, edx
// 007dc088  2bc2                 sub eax, edx
// 007dc08a  3dffff0100           cmp eax, 0x1ffff
// 007dc08f  7e11                 jle 0x7dc0a2
// 007dc091  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 007dc094  6818fb9e00           push 0x9efb18
// 007dc099  51                   push ecx
// 007dc09a  e8a192ffff           call 0x7d5340
// 007dc09f  83c408               add esp, 8
// 007dc0a2  8b13                 mov edx, dword ptr [ebx]
// 007dc0a4  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007dc0a8  81c6ffff0100         add esi, 0x1ffff
// 007dc0ae  81e2ff3f0000         and edx, 0x3fff
// 007dc0b4  c1e60e               shl esi, 0xe
// 007dc0b7  33f2                 xor esi, edx
// 007dc0b9  8933                 mov dword ptr [ebx], esi
// 007dc0bb  83ffff               cmp edi, -1
// 007dc0be  0f856cffffff         jne 0x7dc030
// 007dc0c4  5e                   pop esi
// 007dc0c5  5b                   pop ebx
// 007dc0c6  5f                   pop edi
// 007dc0c7  5d                   pop ebp
// 007dc0c8  59                   pop ecx
// 007dc0c9  c3                   ret 
// library lua-5.1/lcode.c (function _patchlistaux)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
