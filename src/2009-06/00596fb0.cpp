// from server: 100% by auto
// roc 2009-06 00596fb0  unit: seg_00590000  size: 392 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00596fb0
//
// 00596fb0  83ec0c               sub esp, 0xc
// 00596fb3  55                   push ebp
// 00596fb4  56                   push esi
// 00596fb5  8b742418             mov esi, dword ptr [esp + 0x18]
// 00596fb9  8b4668               mov eax, dword ptr [esi + 0x68]
// 00596fbc  c744240800000000     mov dword ptr [esp + 8], 0
// 00596fc4  a804                 test al, 4
// 00596fc6  7426                 je 0x596fee
// 00596fc8  8b8e1c010000         mov ecx, dword ptr [esi + 0x11c]
// 00596fce  c644240c49           mov byte ptr [esp + 0xc], 0x49
// 00596fd3  c644240d44           mov byte ptr [esp + 0xd], 0x44
// 00596fd8  c644240e41           mov byte ptr [esp + 0xe], 0x41
// 00596fdd  c644240f54           mov byte ptr [esp + 0xf], 0x54
// 00596fe2  3b4c240c             cmp ecx, dword ptr [esp + 0xc]
// 00596fe6  7406                 je 0x596fee
// 00596fe8  83c808               or eax, 8
// 00596feb  894668               mov dword ptr [esi + 0x68], eax
// 00596fee  f6861c01000020       test byte ptr [esi + 0x11c], 0x20
// 00596ff5  8dae1c010000         lea ebp, [esi + 0x11c]
// 00596ffb  7526                 jne 0x597023
// 00596ffd  55                   push ebp
// 00596ffe  56                   push esi
// 00596fff  e82cadfeff           call 0x581d30
// 00597004  83c408               add esp, 8
// 00597007  83f803               cmp eax, 3
// 0059700a  7417                 je 0x597023
// 0059700c  83be1c02000000       cmp dword ptr [esi + 0x21c], 0
// 00597013  750e                 jne 0x597023
// 00597015  68d42d8d00           push 0x8d2dd4
// 0059701a  56                   push esi
// 0059701b  e85072ffff           call 0x58e270
// 00597020  83c408               add esp, 8
// 00597023  f7466c00800000       test dword ptr [esi + 0x6c], 0x8000
// 0059702a  751d                 jne 0x597049
// 0059702c  83be1c02000000       cmp dword ptr [esi + 0x21c], 0
// 00597033  7514                 jne 0x597049
// 00597035  8b442420             mov eax, dword ptr [esp + 0x20]
// 00597039  50                   push eax
// 0059703a  56                   push esi
// 0059703b  e8a0dbffff           call 0x594be0
// 00597040  83c408               add esp, 8
// 00597043  5e                   pop esi
// 00597044  5d                   pop ebp
// 00597045  83c40c               add esp, 0xc
// 00597048  c3                   ret 
// 00597049  8b5500               mov edx, dword ptr [ebp]
// 0059704c  8a4504               mov al, byte ptr [ebp + 4]
// 0059704f  53                   push ebx
// 00597050  8d9e6c020000         lea ebx, [esi + 0x26c]
// 00597056  57                   push edi
// 00597057  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0059705b  8913                 mov dword ptr [ebx], edx
// 0059705d  884304               mov byte ptr [ebx + 4], al
// 00597060  c6867002000000       mov byte ptr [esi + 0x270], 0
// 00597067  89be78020000         mov dword ptr [esi + 0x278], edi
// 0059706d  85ff                 test edi, edi
// 0059706f  7508                 jne 0x597079
// 00597071  89be74020000         mov dword ptr [esi + 0x274], edi
// 00597077  eb28                 jmp 0x5970a1
// 00597079  57                   push edi
// 0059707a  56                   push esi
// 0059707b  e8d07bffff           call 0x58ec50
// 00597080  57                   push edi
// 00597081  50                   push eax
// 00597082  56                   push esi
// 00597083  89442434             mov dword ptr [esp + 0x34], eax
// 00597087  898674020000         mov dword ptr [esi + 0x274], eax
// 0059708d  e86e1cffff           call 0x588d00
// 00597092  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00597096  57                   push edi
// 00597097  51                   push ecx
// 00597098  56                   push esi
// 00597099  e822a8feff           call 0x5818c0
// 0059709e  83c420               add esp, 0x20
// 005970a1  8b861c020000         mov eax, dword ptr [esi + 0x21c]
// 005970a7  85c0                 test eax, eax
// 005970a9  744c                 je 0x5970f7
// 005970ab  53                   push ebx
// 005970ac  56                   push esi
// 005970ad  ffd0                 call eax
// 005970af  8bf8                 mov edi, eax
// 005970b1  83c408               add esp, 8
// 005970b4  85ff                 test edi, edi
// 005970b6  7d10                 jge 0x5970c8
// 005970b8  68c02d8d00           push 0x8d2dc0
// 005970bd  56                   push esi
// 005970be  e8ad71ffff           call 0x58e270
// 005970c3  83c408               add esp, 8
// 005970c6  85ff                 test edi, edi
// 005970c8  753e                 jne 0x597108
// 005970ca  f6450020             test byte ptr [ebp], 0x20
// 005970ce  751d                 jne 0x5970ed
// 005970d0  55                   push ebp
// 005970d1  56                   push esi
// 005970d2  e859acfeff           call 0x581d30
// 005970d7  83c408               add esp, 8
// 005970da  83f803               cmp eax, 3
// 005970dd  740e                 je 0x5970ed
// 005970df  68d42d8d00           push 0x8d2dd4
// 005970e4  56                   push esi
// 005970e5  e88671ffff           call 0x58e270
// 005970ea  83c408               add esp, 8
// 005970ed  8b542424             mov edx, dword ptr [esp + 0x24]
// 005970f1  6a01                 push 1
// 005970f3  53                   push ebx
// 005970f4  52                   push edx
// 005970f5  eb08                 jmp 0x5970ff
// 005970f7  8b442424             mov eax, dword ptr [esp + 0x24]
// 005970fb  6a01                 push 1
// 005970fd  53                   push ebx
// 005970fe  50                   push eax
// 005970ff  56                   push esi
// 00597100  e88ba3feff           call 0x581490
// 00597105  83c410               add esp, 0x10
// 00597108  8b8e74020000         mov ecx, dword ptr [esi + 0x274]
// 0059710e  51                   push ecx
// 0059710f  56                   push esi
// 00597110  e89b7bffff           call 0x58ecb0
// 00597115  8b442418             mov eax, dword ptr [esp + 0x18]
// 00597119  83c408               add esp, 8
// 0059711c  5f                   pop edi
// 0059711d  5b                   pop ebx
// 0059711e  50                   push eax
// 0059711f  56                   push esi
// 00597120  c7867402000000000000 mov dword ptr [esi + 0x274], 0
// 0059712a  e8b1daffff           call 0x594be0
// 0059712f  83c408               add esp, 8
// 00597132  5e                   pop esi
// 00597133  5d                   pop ebp
// 00597134  83c40c               add esp, 0xc
// 00597137  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_unknown)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
