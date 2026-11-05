// from server: 100% by auto
// roc 2010-06 0057a900  unit: seg_00570000  size: 392 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0057a900
//
// 0057a900  83ec0c               sub esp, 0xc
// 0057a903  55                   push ebp
// 0057a904  56                   push esi
// 0057a905  8b742418             mov esi, dword ptr [esp + 0x18]
// 0057a909  8b4668               mov eax, dword ptr [esi + 0x68]
// 0057a90c  c744240800000000     mov dword ptr [esp + 8], 0
// 0057a914  a804                 test al, 4
// 0057a916  7426                 je 0x57a93e
// 0057a918  8b8e1c010000         mov ecx, dword ptr [esi + 0x11c]
// 0057a91e  c644240c49           mov byte ptr [esp + 0xc], 0x49
// 0057a923  c644240d44           mov byte ptr [esp + 0xd], 0x44
// 0057a928  c644240e41           mov byte ptr [esp + 0xe], 0x41
// 0057a92d  c644240f54           mov byte ptr [esp + 0xf], 0x54
// 0057a932  3b4c240c             cmp ecx, dword ptr [esp + 0xc]
// 0057a936  7406                 je 0x57a93e
// 0057a938  83c808               or eax, 8
// 0057a93b  894668               mov dword ptr [esi + 0x68], eax
// 0057a93e  f6861c01000020       test byte ptr [esi + 0x11c], 0x20
// 0057a945  8dae1c010000         lea ebp, [esi + 0x11c]
// 0057a94b  7526                 jne 0x57a973
// 0057a94d  55                   push ebp
// 0057a94e  56                   push esi
// 0057a94f  e8fcaafeff           call 0x565450
// 0057a954  83c408               add esp, 8
// 0057a957  83f803               cmp eax, 3
// 0057a95a  7417                 je 0x57a973
// 0057a95c  83be1c02000000       cmp dword ptr [esi + 0x21c], 0
// 0057a963  750e                 jne 0x57a973
// 0057a965  68dc79a200           push 0xa279dc
// 0057a96a  56                   push esi
// 0057a96b  e85072ffff           call 0x571bc0
// 0057a970  83c408               add esp, 8
// 0057a973  f7466c00800000       test dword ptr [esi + 0x6c], 0x8000
// 0057a97a  751d                 jne 0x57a999
// 0057a97c  83be1c02000000       cmp dword ptr [esi + 0x21c], 0
// 0057a983  7514                 jne 0x57a999
// 0057a985  8b442420             mov eax, dword ptr [esp + 0x20]
// 0057a989  50                   push eax
// 0057a98a  56                   push esi
// 0057a98b  e880dbffff           call 0x578510
// 0057a990  83c408               add esp, 8
// 0057a993  5e                   pop esi
// 0057a994  5d                   pop ebp
// 0057a995  83c40c               add esp, 0xc
// 0057a998  c3                   ret 
// 0057a999  8b5500               mov edx, dword ptr [ebp]
// 0057a99c  8a4504               mov al, byte ptr [ebp + 4]
// 0057a99f  53                   push ebx
// 0057a9a0  8d9e6c020000         lea ebx, [esi + 0x26c]
// 0057a9a6  57                   push edi
// 0057a9a7  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0057a9ab  8913                 mov dword ptr [ebx], edx
// 0057a9ad  884304               mov byte ptr [ebx + 4], al
// 0057a9b0  c6867002000000       mov byte ptr [esi + 0x270], 0
// 0057a9b7  89be78020000         mov dword ptr [esi + 0x278], edi
// 0057a9bd  85ff                 test edi, edi
// 0057a9bf  7508                 jne 0x57a9c9
// 0057a9c1  89be74020000         mov dword ptr [esi + 0x274], edi
// 0057a9c7  eb28                 jmp 0x57a9f1
// 0057a9c9  57                   push edi
// 0057a9ca  56                   push esi
// 0057a9cb  e8d07bffff           call 0x5725a0
// 0057a9d0  57                   push edi
// 0057a9d1  50                   push eax
// 0057a9d2  56                   push esi
// 0057a9d3  89442434             mov dword ptr [esp + 0x34], eax
// 0057a9d7  898674020000         mov dword ptr [esi + 0x274], eax
// 0057a9dd  e82e1affff           call 0x56c410
// 0057a9e2  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0057a9e6  57                   push edi
// 0057a9e7  51                   push ecx
// 0057a9e8  56                   push esi
// 0057a9e9  e8f2a5feff           call 0x564fe0
// 0057a9ee  83c420               add esp, 0x20
// 0057a9f1  8b861c020000         mov eax, dword ptr [esi + 0x21c]
// 0057a9f7  85c0                 test eax, eax
// 0057a9f9  744c                 je 0x57aa47
// 0057a9fb  53                   push ebx
// 0057a9fc  56                   push esi
// 0057a9fd  ffd0                 call eax
// 0057a9ff  8bf8                 mov edi, eax
// 0057aa01  83c408               add esp, 8
// 0057aa04  85ff                 test edi, edi
// 0057aa06  7d10                 jge 0x57aa18
// 0057aa08  68c879a200           push 0xa279c8
// 0057aa0d  56                   push esi
// 0057aa0e  e8ad71ffff           call 0x571bc0
// 0057aa13  83c408               add esp, 8
// 0057aa16  85ff                 test edi, edi
// 0057aa18  753e                 jne 0x57aa58
// 0057aa1a  f6450020             test byte ptr [ebp], 0x20
// 0057aa1e  751d                 jne 0x57aa3d
// 0057aa20  55                   push ebp
// 0057aa21  56                   push esi
// 0057aa22  e829aafeff           call 0x565450
// 0057aa27  83c408               add esp, 8
// 0057aa2a  83f803               cmp eax, 3
// 0057aa2d  740e                 je 0x57aa3d
// 0057aa2f  68dc79a200           push 0xa279dc
// 0057aa34  56                   push esi
// 0057aa35  e88671ffff           call 0x571bc0
// 0057aa3a  83c408               add esp, 8
// 0057aa3d  8b542424             mov edx, dword ptr [esp + 0x24]
// 0057aa41  6a01                 push 1
// 0057aa43  53                   push ebx
// 0057aa44  52                   push edx
// 0057aa45  eb08                 jmp 0x57aa4f
// 0057aa47  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057aa4b  6a01                 push 1
// 0057aa4d  53                   push ebx
// 0057aa4e  50                   push eax
// 0057aa4f  56                   push esi
// 0057aa50  e85ba1feff           call 0x564bb0
// 0057aa55  83c410               add esp, 0x10
// 0057aa58  8b8e74020000         mov ecx, dword ptr [esi + 0x274]
// 0057aa5e  51                   push ecx
// 0057aa5f  56                   push esi
// 0057aa60  e89b7bffff           call 0x572600
// 0057aa65  8b442418             mov eax, dword ptr [esp + 0x18]
// 0057aa69  83c408               add esp, 8
// 0057aa6c  5f                   pop edi
// 0057aa6d  5b                   pop ebx
// 0057aa6e  50                   push eax
// 0057aa6f  56                   push esi
// 0057aa70  c7867402000000000000 mov dword ptr [esi + 0x274], 0
// 0057aa7a  e891daffff           call 0x578510
// 0057aa7f  83c408               add esp, 8
// 0057aa82  5e                   pop esi
// 0057aa83  5d                   pop ebp
// 0057aa84  83c40c               add esp, 0xc
// 0057aa87  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_unknown)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
