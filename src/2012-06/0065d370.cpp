// from server: 100% by auto
// roc 2012-06 0065d370  unit: seg_00650000  size: 392 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065d370
//
// 0065d370  83ec0c               sub esp, 0xc
// 0065d373  55                   push ebp
// 0065d374  56                   push esi
// 0065d375  8b742418             mov esi, dword ptr [esp + 0x18]
// 0065d379  8b4668               mov eax, dword ptr [esi + 0x68]
// 0065d37c  c744240800000000     mov dword ptr [esp + 8], 0
// 0065d384  a804                 test al, 4
// 0065d386  7426                 je 0x65d3ae
// 0065d388  8b8e1c010000         mov ecx, dword ptr [esi + 0x11c]
// 0065d38e  c644240c49           mov byte ptr [esp + 0xc], 0x49
// 0065d393  c644240d44           mov byte ptr [esp + 0xd], 0x44
// 0065d398  c644240e41           mov byte ptr [esp + 0xe], 0x41
// 0065d39d  c644240f54           mov byte ptr [esp + 0xf], 0x54
// 0065d3a2  3b4c240c             cmp ecx, dword ptr [esp + 0xc]
// 0065d3a6  7406                 je 0x65d3ae
// 0065d3a8  83c808               or eax, 8
// 0065d3ab  894668               mov dword ptr [esi + 0x68], eax
// 0065d3ae  f6861c01000020       test byte ptr [esi + 0x11c], 0x20
// 0065d3b5  8dae1c010000         lea ebp, [esi + 0x11c]
// 0065d3bb  7526                 jne 0x65d3e3
// 0065d3bd  55                   push ebp
// 0065d3be  56                   push esi
// 0065d3bf  e83c0ffeff           call 0x63e300
// 0065d3c4  83c408               add esp, 8
// 0065d3c7  83f803               cmp eax, 3
// 0065d3ca  7417                 je 0x65d3e3
// 0065d3cc  83be1c02000000       cmp dword ptr [esi + 0x21c], 0
// 0065d3d3  750e                 jne 0x65d3e3
// 0065d3d5  68acaeb800           push 0xb8aeac
// 0065d3da  56                   push esi
// 0065d3db  e8e00effff           call 0x64e2c0
// 0065d3e0  83c408               add esp, 8
// 0065d3e3  f7466c00800000       test dword ptr [esi + 0x6c], 0x8000
// 0065d3ea  751d                 jne 0x65d409
// 0065d3ec  83be1c02000000       cmp dword ptr [esi + 0x21c], 0
// 0065d3f3  7514                 jne 0x65d409
// 0065d3f5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065d3f9  50                   push eax
// 0065d3fa  56                   push esi
// 0065d3fb  e850dbffff           call 0x65af50
// 0065d400  83c408               add esp, 8
// 0065d403  5e                   pop esi
// 0065d404  5d                   pop ebp
// 0065d405  83c40c               add esp, 0xc
// 0065d408  c3                   ret 
// 0065d409  8b5500               mov edx, dword ptr [ebp]
// 0065d40c  8a4504               mov al, byte ptr [ebp + 4]
// 0065d40f  53                   push ebx
// 0065d410  8d9e6c020000         lea ebx, [esi + 0x26c]
// 0065d416  57                   push edi
// 0065d417  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0065d41b  8913                 mov dword ptr [ebx], edx
// 0065d41d  884304               mov byte ptr [ebx + 4], al
// 0065d420  c6867002000000       mov byte ptr [esi + 0x270], 0
// 0065d427  89be78020000         mov dword ptr [esi + 0x278], edi
// 0065d42d  85ff                 test edi, edi
// 0065d42f  7508                 jne 0x65d439
// 0065d431  89be74020000         mov dword ptr [esi + 0x274], edi
// 0065d437  eb28                 jmp 0x65d461
// 0065d439  57                   push edi
// 0065d43a  56                   push esi
// 0065d43b  e88010ffff           call 0x64e4c0
// 0065d440  57                   push edi
// 0065d441  50                   push eax
// 0065d442  56                   push esi
// 0065d443  89442434             mov dword ptr [esp + 0x34], eax
// 0065d447  898674020000         mov dword ptr [esi + 0x274], eax
// 0065d44d  e89e09ffff           call 0x64ddf0
// 0065d452  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0065d456  57                   push edi
// 0065d457  51                   push ecx
// 0065d458  56                   push esi
// 0065d459  e8320afeff           call 0x63de90
// 0065d45e  83c420               add esp, 0x20
// 0065d461  8b861c020000         mov eax, dword ptr [esi + 0x21c]
// 0065d467  85c0                 test eax, eax
// 0065d469  744c                 je 0x65d4b7
// 0065d46b  53                   push ebx
// 0065d46c  56                   push esi
// 0065d46d  ffd0                 call eax
// 0065d46f  8bf8                 mov edi, eax
// 0065d471  83c408               add esp, 8
// 0065d474  85ff                 test edi, edi
// 0065d476  7d10                 jge 0x65d488
// 0065d478  6898aeb800           push 0xb8ae98
// 0065d47d  56                   push esi
// 0065d47e  e83d0effff           call 0x64e2c0
// 0065d483  83c408               add esp, 8
// 0065d486  85ff                 test edi, edi
// 0065d488  753e                 jne 0x65d4c8
// 0065d48a  f6450020             test byte ptr [ebp], 0x20
// 0065d48e  751d                 jne 0x65d4ad
// 0065d490  55                   push ebp
// 0065d491  56                   push esi
// 0065d492  e8690efeff           call 0x63e300
// 0065d497  83c408               add esp, 8
// 0065d49a  83f803               cmp eax, 3
// 0065d49d  740e                 je 0x65d4ad
// 0065d49f  68acaeb800           push 0xb8aeac
// 0065d4a4  56                   push esi
// 0065d4a5  e8160effff           call 0x64e2c0
// 0065d4aa  83c408               add esp, 8
// 0065d4ad  8b542424             mov edx, dword ptr [esp + 0x24]
// 0065d4b1  6a01                 push 1
// 0065d4b3  53                   push ebx
// 0065d4b4  52                   push edx
// 0065d4b5  eb08                 jmp 0x65d4bf
// 0065d4b7  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065d4bb  6a01                 push 1
// 0065d4bd  53                   push ebx
// 0065d4be  50                   push eax
// 0065d4bf  56                   push esi
// 0065d4c0  e8aba0feff           call 0x647570
// 0065d4c5  83c410               add esp, 0x10
// 0065d4c8  8b8e74020000         mov ecx, dword ptr [esi + 0x274]
// 0065d4ce  51                   push ecx
// 0065d4cf  56                   push esi
// 0065d4d0  e84b10ffff           call 0x64e520
// 0065d4d5  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065d4d9  83c408               add esp, 8
// 0065d4dc  5f                   pop edi
// 0065d4dd  5b                   pop ebx
// 0065d4de  50                   push eax
// 0065d4df  56                   push esi
// 0065d4e0  c7867402000000000000 mov dword ptr [esi + 0x274], 0
// 0065d4ea  e861daffff           call 0x65af50
// 0065d4ef  83c408               add esp, 8
// 0065d4f2  5e                   pop esi
// 0065d4f3  5d                   pop ebp
// 0065d4f4  83c40c               add esp, 0xc
// 0065d4f7  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_unknown)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
