// from server: 100% by auto
// roc 2009-12 007d3d20  unit: seg_007d0000  size: 278 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d3d20
//
// 007d3d20  83ec0c               sub esp, 0xc
// 007d3d23  55                   push ebp
// 007d3d24  56                   push esi
// 007d3d25  8bf0                 mov esi, eax
// 007d3d27  8b6e30               mov ebp, dword ptr [esi + 0x30]
// 007d3d2a  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 007d3d32  c644241201           mov byte ptr [esp + 0x12], 1
// 007d3d37  8a4532               mov al, byte ptr [ebp + 0x32]
// 007d3d3a  88442410             mov byte ptr [esp + 0x10], al
// 007d3d3e  c644241100           mov byte ptr [esp + 0x11], 0
// 007d3d43  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 007d3d46  8d542408             lea edx, [esp + 8]
// 007d3d4a  894c2408             mov dword ptr [esp + 8], ecx
// 007d3d4e  56                   push esi
// 007d3d4f  895514               mov dword ptr [ebp + 0x14], edx
// 007d3d52  e8d9290000           call 0x7d6730
// 007d3d57  83c404               add esp, 4
// 007d3d5a  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 007d3d61  7424                 je 0x7d3d87
// 007d3d63  681d010000           push 0x11d
// 007d3d68  56                   push esi
// 007d3d69  e8d2140000           call 0x7d5240
// 007d3d6e  50                   push eax
// 007d3d6f  8b4634               mov eax, dword ptr [esi + 0x34]
// 007d3d72  68d0ed9e00           push 0x9eedd0
// 007d3d77  50                   push eax
// 007d3d78  e80368fcff           call 0x79a580
// 007d3d7d  50                   push eax
// 007d3d7e  56                   push esi
// 007d3d7f  e8bc150000           call 0x7d5340
// 007d3d84  83c41c               add esp, 0x1c
// 007d3d87  57                   push edi
// 007d3d88  8b7e18               mov edi, dword ptr [esi + 0x18]
// 007d3d8b  56                   push esi
// 007d3d8c  e89f290000           call 0x7d6730
// 007d3d91  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d3d94  83c404               add esp, 4
// 007d3d97  83f82c               cmp eax, 0x2c
// 007d3d9a  742e                 je 0x7d3dca
// 007d3d9c  83f83d               cmp eax, 0x3d
// 007d3d9f  7417                 je 0x7d3db8
// 007d3da1  3d0b010000           cmp eax, 0x10b
// 007d3da6  7422                 je 0x7d3dca
// 007d3da8  6824f09e00           push 0x9ef024
// 007d3dad  56                   push esi
// 007d3dae  e88d150000           call 0x7d5340
// 007d3db3  83c408               add esp, 8
// 007d3db6  eb1f                 jmp 0x7d3dd7
// 007d3db8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007d3dbc  51                   push ecx
// 007d3dbd  57                   push edi
// 007d3dbe  8bfe                 mov edi, esi
// 007d3dc0  e8bbfaffff           call 0x7d3880
// 007d3dc5  83c408               add esp, 8
// 007d3dc8  eb0d                 jmp 0x7d3dd7
// 007d3dca  53                   push ebx
// 007d3dcb  57                   push edi
// 007d3dcc  8bde                 mov ebx, esi
// 007d3dce  e8ddfcffff           call 0x7d3ab0
// 007d3dd3  83c404               add esp, 4
// 007d3dd6  5b                   pop ebx
// 007d3dd7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007d3ddb  6808010000           push 0x108
// 007d3de0  bf06010000           mov edi, 0x106
// 007d3de5  e8f6daffff           call 0x7d18e0
// 007d3dea  8b7514               mov esi, dword ptr [ebp + 0x14]
// 007d3ded  8b16                 mov edx, dword ptr [esi]
// 007d3def  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007d3df2  895514               mov dword ptr [ebp + 0x14], edx
// 007d3df5  0fb65608             movzx edx, byte ptr [esi + 8]
// 007d3df9  83c404               add esp, 4
// 007d3dfc  e8afdcffff           call 0x7d1ab0
// 007d3e01  807e0900             cmp byte ptr [esi + 9], 0
// 007d3e05  5f                   pop edi
// 007d3e06  7414                 je 0x7d3e1c
// 007d3e08  0fb64608             movzx eax, byte ptr [esi + 8]
// 007d3e0c  6a00                 push 0
// 007d3e0e  6a00                 push 0
// 007d3e10  50                   push eax
// 007d3e11  6a23                 push 0x23
// 007d3e13  55                   push ebp
// 007d3e14  e8e7870000           call 0x7dc600
// 007d3e19  83c414               add esp, 0x14
// 007d3e1c  0fb64d32             movzx ecx, byte ptr [ebp + 0x32]
// 007d3e20  894d24               mov dword ptr [ebp + 0x24], ecx
// 007d3e23  8b5604               mov edx, dword ptr [esi + 4]
// 007d3e26  52                   push edx
// 007d3e27  55                   push ebp
// 007d3e28  e8338a0000           call 0x7dc860
// 007d3e2d  83c408               add esp, 8
// 007d3e30  5e                   pop esi
// 007d3e31  5d                   pop ebp
// 007d3e32  83c40c               add esp, 0xc
// 007d3e35  c3                   ret 
// library lua-5.1/lparser.c (function _forstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
