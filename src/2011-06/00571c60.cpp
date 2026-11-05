// from server: 100% by auto
// roc 2011-06 00571c60  unit: seg_00570000  size: 392 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00571c60
//
// 00571c60  83ec0c               sub esp, 0xc
// 00571c63  55                   push ebp
// 00571c64  56                   push esi
// 00571c65  8b742418             mov esi, dword ptr [esp + 0x18]
// 00571c69  8b4668               mov eax, dword ptr [esi + 0x68]
// 00571c6c  c744240800000000     mov dword ptr [esp + 8], 0
// 00571c74  a804                 test al, 4
// 00571c76  7426                 je 0x571c9e
// 00571c78  8b8e1c010000         mov ecx, dword ptr [esi + 0x11c]
// 00571c7e  c644240c49           mov byte ptr [esp + 0xc], 0x49
// 00571c83  c644240d44           mov byte ptr [esp + 0xd], 0x44
// 00571c88  c644240e41           mov byte ptr [esp + 0xe], 0x41
// 00571c8d  c644240f54           mov byte ptr [esp + 0xf], 0x54
// 00571c92  3b4c240c             cmp ecx, dword ptr [esp + 0xc]
// 00571c96  7406                 je 0x571c9e
// 00571c98  83c808               or eax, 8
// 00571c9b  894668               mov dword ptr [esi + 0x68], eax
// 00571c9e  f6861c01000020       test byte ptr [esi + 0x11c], 0x20
// 00571ca5  8dae1c010000         lea ebp, [esi + 0x11c]
// 00571cab  7526                 jne 0x571cd3
// 00571cad  55                   push ebp
// 00571cae  56                   push esi
// 00571caf  e80cf0fdff           call 0x550cc0
// 00571cb4  83c408               add esp, 8
// 00571cb7  83f803               cmp eax, 3
// 00571cba  7417                 je 0x571cd3
// 00571cbc  83be1c02000000       cmp dword ptr [esi + 0x21c], 0
// 00571cc3  750e                 jne 0x571cd3
// 00571cc5  685c70a800           push 0xa8705c
// 00571cca  56                   push esi
// 00571ccb  e870f7feff           call 0x561440
// 00571cd0  83c408               add esp, 8
// 00571cd3  f7466c00800000       test dword ptr [esi + 0x6c], 0x8000
// 00571cda  751d                 jne 0x571cf9
// 00571cdc  83be1c02000000       cmp dword ptr [esi + 0x21c], 0
// 00571ce3  7514                 jne 0x571cf9
// 00571ce5  8b442420             mov eax, dword ptr [esp + 0x20]
// 00571ce9  50                   push eax
// 00571cea  56                   push esi
// 00571ceb  e850dbffff           call 0x56f840
// 00571cf0  83c408               add esp, 8
// 00571cf3  5e                   pop esi
// 00571cf4  5d                   pop ebp
// 00571cf5  83c40c               add esp, 0xc
// 00571cf8  c3                   ret 
// 00571cf9  8b5500               mov edx, dword ptr [ebp]
// 00571cfc  8a4504               mov al, byte ptr [ebp + 4]
// 00571cff  53                   push ebx
// 00571d00  8d9e6c020000         lea ebx, [esi + 0x26c]
// 00571d06  57                   push edi
// 00571d07  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00571d0b  8913                 mov dword ptr [ebx], edx
// 00571d0d  884304               mov byte ptr [ebx + 4], al
// 00571d10  c6867002000000       mov byte ptr [esi + 0x270], 0
// 00571d17  89be78020000         mov dword ptr [esi + 0x278], edi
// 00571d1d  85ff                 test edi, edi
// 00571d1f  7508                 jne 0x571d29
// 00571d21  89be74020000         mov dword ptr [esi + 0x274], edi
// 00571d27  eb28                 jmp 0x571d51
// 00571d29  57                   push edi
// 00571d2a  56                   push esi
// 00571d2b  e810f9feff           call 0x561640
// 00571d30  57                   push edi
// 00571d31  50                   push eax
// 00571d32  56                   push esi
// 00571d33  89442434             mov dword ptr [esp + 0x34], eax
// 00571d37  898674020000         mov dword ptr [esi + 0x274], eax
// 00571d3d  e82ef2feff           call 0x560f70
// 00571d42  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00571d46  57                   push edi
// 00571d47  51                   push ecx
// 00571d48  56                   push esi
// 00571d49  e802ebfdff           call 0x550850
// 00571d4e  83c420               add esp, 0x20
// 00571d51  8b861c020000         mov eax, dword ptr [esi + 0x21c]
// 00571d57  85c0                 test eax, eax
// 00571d59  744c                 je 0x571da7
// 00571d5b  53                   push ebx
// 00571d5c  56                   push esi
// 00571d5d  ffd0                 call eax
// 00571d5f  8bf8                 mov edi, eax
// 00571d61  83c408               add esp, 8
// 00571d64  85ff                 test edi, edi
// 00571d66  7d10                 jge 0x571d78
// 00571d68  684870a800           push 0xa87048
// 00571d6d  56                   push esi
// 00571d6e  e8cdf6feff           call 0x561440
// 00571d73  83c408               add esp, 8
// 00571d76  85ff                 test edi, edi
// 00571d78  753e                 jne 0x571db8
// 00571d7a  f6450020             test byte ptr [ebp], 0x20
// 00571d7e  751d                 jne 0x571d9d
// 00571d80  55                   push ebp
// 00571d81  56                   push esi
// 00571d82  e839effdff           call 0x550cc0
// 00571d87  83c408               add esp, 8
// 00571d8a  83f803               cmp eax, 3
// 00571d8d  740e                 je 0x571d9d
// 00571d8f  685c70a800           push 0xa8705c
// 00571d94  56                   push esi
// 00571d95  e8a6f6feff           call 0x561440
// 00571d9a  83c408               add esp, 8
// 00571d9d  8b542424             mov edx, dword ptr [esp + 0x24]
// 00571da1  6a01                 push 1
// 00571da3  53                   push ebx
// 00571da4  52                   push edx
// 00571da5  eb08                 jmp 0x571daf
// 00571da7  8b442424             mov eax, dword ptr [esp + 0x24]
// 00571dab  6a01                 push 1
// 00571dad  53                   push ebx
// 00571dae  50                   push eax
// 00571daf  56                   push esi
// 00571db0  e83b89feff           call 0x55a6f0
// 00571db5  83c410               add esp, 0x10
// 00571db8  8b8e74020000         mov ecx, dword ptr [esi + 0x274]
// 00571dbe  51                   push ecx
// 00571dbf  56                   push esi
// 00571dc0  e8dbf8feff           call 0x5616a0
// 00571dc5  8b442418             mov eax, dword ptr [esp + 0x18]
// 00571dc9  83c408               add esp, 8
// 00571dcc  5f                   pop edi
// 00571dcd  5b                   pop ebx
// 00571dce  50                   push eax
// 00571dcf  56                   push esi
// 00571dd0  c7867402000000000000 mov dword ptr [esi + 0x274], 0
// 00571dda  e861daffff           call 0x56f840
// 00571ddf  83c408               add esp, 8
// 00571de2  5e                   pop esi
// 00571de3  5d                   pop ebp
// 00571de4  83c40c               add esp, 0xc
// 00571de7  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_unknown)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
