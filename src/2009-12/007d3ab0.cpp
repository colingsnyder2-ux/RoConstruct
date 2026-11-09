// from server: 100% by auto
// roc 2009-12 007d3ab0  unit: seg_007d0000  size: 619 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d3ab0
//
// 007d3ab0  83ec24               sub esp, 0x24
// 007d3ab3  8b4330               mov eax, dword ptr [ebx + 0x30]
// 007d3ab6  55                   push ebp
// 007d3ab7  56                   push esi
// 007d3ab8  57                   push edi
// 007d3ab9  6a0f                 push 0xf
// 007d3abb  89442414             mov dword ptr [esp + 0x14], eax
// 007d3abf  8b4024               mov eax, dword ptr [eax + 0x24]
// 007d3ac2  6814f09e00           push 0x9ef014
// 007d3ac7  53                   push ebx
// 007d3ac8  89442420             mov dword ptr [esp + 0x20], eax
// 007d3acc  e88f180000           call 0x7d5360
// 007d3ad1  8b7330               mov esi, dword ptr [ebx + 0x30]
// 007d3ad4  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007d3ad8  41                   inc ecx
// 007d3ad9  83c40c               add esp, 0xc
// 007d3adc  81f9c8000000         cmp ecx, 0xc8
// 007d3ae2  8bf8                 mov edi, eax
// 007d3ae4  7e0f                 jle 0x7d3af5
// 007d3ae6  b974ee9e00           mov ecx, 0x9eee74
// 007d3aeb  bac8000000           mov edx, 0xc8
// 007d3af0  e89bddffff           call 0x7d1890
// 007d3af5  57                   push edi
// 007d3af6  53                   push ebx
// 007d3af7  e8d4deffff           call 0x7d19d0
// 007d3afc  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 007d3b00  6a0b                 push 0xb
// 007d3b02  6808f09e00           push 0x9ef008
// 007d3b07  53                   push ebx
// 007d3b08  66898456ac000000     mov word ptr [esi + edx*2 + 0xac], ax
// 007d3b10  e84b180000           call 0x7d5360
// 007d3b15  8b7330               mov esi, dword ptr [ebx + 0x30]
// 007d3b18  8bf8                 mov edi, eax
// 007d3b1a  0fb64632             movzx eax, byte ptr [esi + 0x32]
// 007d3b1e  83c002               add eax, 2
// 007d3b21  83c414               add esp, 0x14
// 007d3b24  3dc8000000           cmp eax, 0xc8
// 007d3b29  7e0f                 jle 0x7d3b3a
// 007d3b2b  b974ee9e00           mov ecx, 0x9eee74
// 007d3b30  bac8000000           mov edx, 0xc8
// 007d3b35  e856ddffff           call 0x7d1890
// 007d3b3a  57                   push edi
// 007d3b3b  53                   push ebx
// 007d3b3c  e88fdeffff           call 0x7d19d0
// 007d3b41  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007d3b45  6a0d                 push 0xd
// 007d3b47  68f8ef9e00           push 0x9eeff8
// 007d3b4c  53                   push ebx
// 007d3b4d  6689844eae000000     mov word ptr [esi + ecx*2 + 0xae], ax
// 007d3b55  e806180000           call 0x7d5360
// 007d3b5a  8b7330               mov esi, dword ptr [ebx + 0x30]
// 007d3b5d  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 007d3b61  83c203               add edx, 3
// 007d3b64  83c414               add esp, 0x14
// 007d3b67  81fac8000000         cmp edx, 0xc8
// 007d3b6d  8bf8                 mov edi, eax
// 007d3b6f  7e0f                 jle 0x7d3b80
// 007d3b71  b974ee9e00           mov ecx, 0x9eee74
// 007d3b76  bac8000000           mov edx, 0xc8
// 007d3b7b  e810ddffff           call 0x7d1890
// 007d3b80  57                   push edi
// 007d3b81  53                   push ebx
// 007d3b82  e849deffff           call 0x7d19d0
// 007d3b87  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007d3b8b  6689844eb0000000     mov word ptr [esi + ecx*2 + 0xb0], ax
// 007d3b93  8b7330               mov esi, dword ptr [ebx + 0x30]
// 007d3b96  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 007d3b9a  83c204               add edx, 4
// 007d3b9d  83c408               add esp, 8
// 007d3ba0  81fac8000000         cmp edx, 0xc8
// 007d3ba6  7e0f                 jle 0x7d3bb7
// 007d3ba8  b974ee9e00           mov ecx, 0x9eee74
// 007d3bad  bac8000000           mov edx, 0xc8
// 007d3bb2  e8d9dcffff           call 0x7d1890
// 007d3bb7  8b442434             mov eax, dword ptr [esp + 0x34]
// 007d3bbb  50                   push eax
// 007d3bbc  53                   push ebx
// 007d3bbd  e80edeffff           call 0x7d19d0
// 007d3bc2  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007d3bc6  83c408               add esp, 8
// 007d3bc9  6689844eb2000000     mov word ptr [esi + ecx*2 + 0xb2], ax
// 007d3bd1  bf04000000           mov edi, 4
// 007d3bd6  837b102c             cmp dword ptr [ebx + 0x10], 0x2c
// 007d3bda  0f85ba000000         jne 0x7d3c9a
// 007d3be0  53                   push ebx
// 007d3be1  e84a2b0000           call 0x7d6730
// 007d3be6  83c404               add esp, 4
// 007d3be9  817b101d010000       cmp dword ptr [ebx + 0x10], 0x11d
// 007d3bf0  7424                 je 0x7d3c16
// 007d3bf2  681d010000           push 0x11d
// 007d3bf7  53                   push ebx
// 007d3bf8  e843160000           call 0x7d5240
// 007d3bfd  8b5334               mov edx, dword ptr [ebx + 0x34]
// 007d3c00  50                   push eax
// 007d3c01  68d0ed9e00           push 0x9eedd0
// 007d3c06  52                   push edx
// 007d3c07  e87469fcff           call 0x79a580
// 007d3c0c  50                   push eax
// 007d3c0d  53                   push ebx
// 007d3c0e  e82d170000           call 0x7d5340
// 007d3c13  83c41c               add esp, 0x1c
// 007d3c16  8b6b18               mov ebp, dword ptr [ebx + 0x18]
// 007d3c19  53                   push ebx
// 007d3c1a  e8112b0000           call 0x7d6730
// 007d3c1f  8b7330               mov esi, dword ptr [ebx + 0x30]
// 007d3c22  0fb64632             movzx eax, byte ptr [esi + 0x32]
// 007d3c26  8d4c3801             lea ecx, [eax + edi + 1]
// 007d3c2a  83c404               add esp, 4
// 007d3c2d  81f9c8000000         cmp ecx, 0xc8
// 007d3c33  7e47                 jle 0x7d3c7c
// 007d3c35  8b16                 mov edx, dword ptr [esi]
// 007d3c37  8b423c               mov eax, dword ptr [edx + 0x3c]
// 007d3c3a  6874ee9e00           push 0x9eee74
// 007d3c3f  68c8000000           push 0xc8
// 007d3c44  85c0                 test eax, eax
// 007d3c46  7513                 jne 0x7d3c5b
// 007d3c48  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d3c4b  6808ee9e00           push 0x9eee08
// 007d3c50  50                   push eax
// 007d3c51  e82a69fcff           call 0x79a580
// 007d3c56  83c410               add esp, 0x10
// 007d3c59  eb12                 jmp 0x7d3c6d
// 007d3c5b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007d3c5e  50                   push eax
// 007d3c5f  68e0ed9e00           push 0x9eede0
// 007d3c64  51                   push ecx
// 007d3c65  e81669fcff           call 0x79a580
// 007d3c6a  83c414               add esp, 0x14
// 007d3c6d  8b560c               mov edx, dword ptr [esi + 0xc]
// 007d3c70  6a00                 push 0
// 007d3c72  50                   push eax
// 007d3c73  52                   push edx
// 007d3c74  e827160000           call 0x7d52a0
// 007d3c79  83c40c               add esp, 0xc
// 007d3c7c  55                   push ebp
// 007d3c7d  53                   push ebx
// 007d3c7e  e84dddffff           call 0x7d19d0
// 007d3c83  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007d3c87  03cf                 add ecx, edi
// 007d3c89  83c408               add esp, 8
// 007d3c8c  6689844eac000000     mov word ptr [esi + ecx*2 + 0xac], ax
// 007d3c94  47                   inc edi
// 007d3c95  e93cffffff           jmp 0x7d3bd6
// 007d3c9a  817b100b010000       cmp dword ptr [ebx + 0x10], 0x10b
// 007d3ca1  897c240c             mov dword ptr [esp + 0xc], edi
// 007d3ca5  7424                 je 0x7d3ccb
// 007d3ca7  680b010000           push 0x10b
// 007d3cac  53                   push ebx
// 007d3cad  e88e150000           call 0x7d5240
// 007d3cb2  8b5334               mov edx, dword ptr [ebx + 0x34]
// 007d3cb5  50                   push eax
// 007d3cb6  68d0ed9e00           push 0x9eedd0
// 007d3cbb  52                   push edx
// 007d3cbc  e8bf68fcff           call 0x79a580
// 007d3cc1  50                   push eax
// 007d3cc2  53                   push ebx
// 007d3cc3  e878160000           call 0x7d5340
// 007d3cc8  83c41c               add esp, 0x1c
// 007d3ccb  53                   push ebx
// 007d3ccc  e85f2a0000           call 0x7d6730
// 007d3cd1  8b6b04               mov ebp, dword ptr [ebx + 4]
// 007d3cd4  8d7c241c             lea edi, [esp + 0x1c]
// 007d3cd8  8bf3                 mov esi, ebx
// 007d3cda  e861ebffff           call 0x7d2840
// 007d3cdf  50                   push eax
// 007d3ce0  8bcf                 mov ecx, edi
// 007d3ce2  ba03000000           mov edx, 3
// 007d3ce7  8bc3                 mov eax, ebx
// 007d3ce9  e882e0ffff           call 0x7d1d70
// 007d3cee  8b442418             mov eax, dword ptr [esp + 0x18]
// 007d3cf2  6a03                 push 3
// 007d3cf4  50                   push eax
// 007d3cf5  e826840000           call 0x7dc120
// 007d3cfa  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007d3cfe  8b542424             mov edx, dword ptr [esp + 0x24]
// 007d3d02  6a00                 push 0
// 007d3d04  83c1fd               add ecx, -3
// 007d3d07  51                   push ecx
// 007d3d08  55                   push ebp
// 007d3d09  52                   push edx
// 007d3d0a  8bc3                 mov eax, ebx
// 007d3d0c  e8cff9ffff           call 0x7d36e0
// 007d3d11  83c420               add esp, 0x20
// 007d3d14  5f                   pop edi
// 007d3d15  5e                   pop esi
// 007d3d16  5d                   pop ebp
// 007d3d17  83c424               add esp, 0x24
// 007d3d1a  c3                   ret 
// library lua-5.1/lparser.c (function _forlist)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
