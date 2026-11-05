// from server: 100% by auto
// roc 2009-12 00618fe0  unit: seg_00610000  size: 392 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00618fe0
//
// 00618fe0  83ec0c               sub esp, 0xc
// 00618fe3  55                   push ebp
// 00618fe4  56                   push esi
// 00618fe5  8b742418             mov esi, dword ptr [esp + 0x18]
// 00618fe9  8b4668               mov eax, dword ptr [esi + 0x68]
// 00618fec  c744240800000000     mov dword ptr [esp + 8], 0
// 00618ff4  a804                 test al, 4
// 00618ff6  7426                 je 0x61901e
// 00618ff8  8b8e1c010000         mov ecx, dword ptr [esi + 0x11c]
// 00618ffe  c644240c49           mov byte ptr [esp + 0xc], 0x49
// 00619003  c644240d44           mov byte ptr [esp + 0xd], 0x44
// 00619008  c644240e41           mov byte ptr [esp + 0xe], 0x41
// 0061900d  c644240f54           mov byte ptr [esp + 0xf], 0x54
// 00619012  3b4c240c             cmp ecx, dword ptr [esp + 0xc]
// 00619016  7406                 je 0x61901e
// 00619018  83c808               or eax, 8
// 0061901b  894668               mov dword ptr [esi + 0x68], eax
// 0061901e  f6861c01000020       test byte ptr [esi + 0x11c], 0x20
// 00619025  8dae1c010000         lea ebp, [esi + 0x11c]
// 0061902b  7526                 jne 0x619053
// 0061902d  55                   push ebp
// 0061902e  56                   push esi
// 0061902f  e8acaafeff           call 0x603ae0
// 00619034  83c408               add esp, 8
// 00619037  83f803               cmp eax, 3
// 0061903a  7417                 je 0x619053
// 0061903c  83be1c02000000       cmp dword ptr [esi + 0x21c], 0
// 00619043  750e                 jne 0x619053
// 00619045  68649c9c00           push 0x9c9c64
// 0061904a  56                   push esi
// 0061904b  e85072ffff           call 0x6102a0
// 00619050  83c408               add esp, 8
// 00619053  f7466c00800000       test dword ptr [esi + 0x6c], 0x8000
// 0061905a  751d                 jne 0x619079
// 0061905c  83be1c02000000       cmp dword ptr [esi + 0x21c], 0
// 00619063  7514                 jne 0x619079
// 00619065  8b442420             mov eax, dword ptr [esp + 0x20]
// 00619069  50                   push eax
// 0061906a  56                   push esi
// 0061906b  e880dbffff           call 0x616bf0
// 00619070  83c408               add esp, 8
// 00619073  5e                   pop esi
// 00619074  5d                   pop ebp
// 00619075  83c40c               add esp, 0xc
// 00619078  c3                   ret 
// 00619079  8b5500               mov edx, dword ptr [ebp]
// 0061907c  8a4504               mov al, byte ptr [ebp + 4]
// 0061907f  53                   push ebx
// 00619080  8d9e6c020000         lea ebx, [esi + 0x26c]
// 00619086  57                   push edi
// 00619087  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0061908b  8913                 mov dword ptr [ebx], edx
// 0061908d  884304               mov byte ptr [ebx + 4], al
// 00619090  c6867002000000       mov byte ptr [esi + 0x270], 0
// 00619097  89be78020000         mov dword ptr [esi + 0x278], edi
// 0061909d  85ff                 test edi, edi
// 0061909f  7508                 jne 0x6190a9
// 006190a1  89be74020000         mov dword ptr [esi + 0x274], edi
// 006190a7  eb28                 jmp 0x6190d1
// 006190a9  57                   push edi
// 006190aa  56                   push esi
// 006190ab  e8d07bffff           call 0x610c80
// 006190b0  57                   push edi
// 006190b1  50                   push eax
// 006190b2  56                   push esi
// 006190b3  89442434             mov dword ptr [esp + 0x34], eax
// 006190b7  898674020000         mov dword ptr [esi + 0x274], eax
// 006190bd  e8ce19ffff           call 0x60aa90
// 006190c2  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 006190c6  57                   push edi
// 006190c7  51                   push ecx
// 006190c8  56                   push esi
// 006190c9  e8a2a5feff           call 0x603670
// 006190ce  83c420               add esp, 0x20
// 006190d1  8b861c020000         mov eax, dword ptr [esi + 0x21c]
// 006190d7  85c0                 test eax, eax
// 006190d9  744c                 je 0x619127
// 006190db  53                   push ebx
// 006190dc  56                   push esi
// 006190dd  ffd0                 call eax
// 006190df  8bf8                 mov edi, eax
// 006190e1  83c408               add esp, 8
// 006190e4  85ff                 test edi, edi
// 006190e6  7d10                 jge 0x6190f8
// 006190e8  68509c9c00           push 0x9c9c50
// 006190ed  56                   push esi
// 006190ee  e8ad71ffff           call 0x6102a0
// 006190f3  83c408               add esp, 8
// 006190f6  85ff                 test edi, edi
// 006190f8  753e                 jne 0x619138
// 006190fa  f6450020             test byte ptr [ebp], 0x20
// 006190fe  751d                 jne 0x61911d
// 00619100  55                   push ebp
// 00619101  56                   push esi
// 00619102  e8d9a9feff           call 0x603ae0
// 00619107  83c408               add esp, 8
// 0061910a  83f803               cmp eax, 3
// 0061910d  740e                 je 0x61911d
// 0061910f  68649c9c00           push 0x9c9c64
// 00619114  56                   push esi
// 00619115  e88671ffff           call 0x6102a0
// 0061911a  83c408               add esp, 8
// 0061911d  8b542424             mov edx, dword ptr [esp + 0x24]
// 00619121  6a01                 push 1
// 00619123  53                   push ebx
// 00619124  52                   push edx
// 00619125  eb08                 jmp 0x61912f
// 00619127  8b442424             mov eax, dword ptr [esp + 0x24]
// 0061912b  6a01                 push 1
// 0061912d  53                   push ebx
// 0061912e  50                   push eax
// 0061912f  56                   push esi
// 00619130  e80ba1feff           call 0x603240
// 00619135  83c410               add esp, 0x10
// 00619138  8b8e74020000         mov ecx, dword ptr [esi + 0x274]
// 0061913e  51                   push ecx
// 0061913f  56                   push esi
// 00619140  e89b7bffff           call 0x610ce0
// 00619145  8b442418             mov eax, dword ptr [esp + 0x18]
// 00619149  83c408               add esp, 8
// 0061914c  5f                   pop edi
// 0061914d  5b                   pop ebx
// 0061914e  50                   push eax
// 0061914f  56                   push esi
// 00619150  c7867402000000000000 mov dword ptr [esi + 0x274], 0
// 0061915a  e891daffff           call 0x616bf0
// 0061915f  83c408               add esp, 8
// 00619162  5e                   pop esi
// 00619163  5d                   pop ebp
// 00619164  83c40c               add esp, 0xc
// 00619167  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_unknown)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
