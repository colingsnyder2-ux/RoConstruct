// from server: 100% by auto
// roc 2009-12 0079dd60  unit: seg_00790000  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079dd60
//
// 0079dd60  81ec18010000         sub esp, 0x118
// 0079dd66  53                   push ebx
// 0079dd67  55                   push ebp
// 0079dd68  56                   push esi
// 0079dd69  57                   push edi
// 0079dd6a  8bbc242c010000       mov edi, dword ptr [esp + 0x12c]
// 0079dd71  8d442414             lea eax, [esp + 0x14]
// 0079dd75  50                   push eax
// 0079dd76  68edd8ffff           push 0xffffd8ed
// 0079dd7b  57                   push edi
// 0079dd7c  e81faefeff           call 0x788ba0
// 0079dd81  6a00                 push 0
// 0079dd83  68ecd8ffff           push 0xffffd8ec
// 0079dd88  57                   push edi
// 0079dd89  8bd8                 mov ebx, eax
// 0079dd8b  e810aefeff           call 0x788ba0
// 0079dd90  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0079dd94  03cb                 add ecx, ebx
// 0079dd96  68ebd8ffff           push 0xffffd8eb
// 0079dd9b  57                   push edi
// 0079dd9c  8be8                 mov ebp, eax
// 0079dd9e  897c2440             mov dword ptr [esp + 0x40], edi
// 0079dda2  895c2438             mov dword ptr [esp + 0x38], ebx
// 0079dda6  894c243c             mov dword ptr [esp + 0x3c], ecx
// 0079ddaa  e881adfeff           call 0x788b30
// 0079ddaf  8bf0                 mov esi, eax
// 0079ddb1  03f3                 add esi, ebx
// 0079ddb3  83c420               add esp, 0x20
// 0079ddb6  3b74241c             cmp esi, dword ptr [esp + 0x1c]
// 0079ddba  772c                 ja 0x79dde8
// 0079ddbc  8d642400             lea esp, [esp]
// 0079ddc0  55                   push ebp
// 0079ddc1  8d54241c             lea edx, [esp + 0x1c]
// 0079ddc5  56                   push esi
// 0079ddc6  52                   push edx
// 0079ddc7  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0079ddcf  e86cf9ffff           call 0x79d740
// 0079ddd4  8bc8                 mov ecx, eax
// 0079ddd6  83c40c               add esp, 0xc
// 0079ddd9  894c2410             mov dword ptr [esp + 0x10], ecx
// 0079dddd  85c9                 test ecx, ecx
// 0079dddf  7514                 jne 0x79ddf5
// 0079dde1  46                   inc esi
// 0079dde2  3b74241c             cmp esi, dword ptr [esp + 0x1c]
// 0079dde6  76d8                 jbe 0x79ddc0
// 0079dde8  5f                   pop edi
// 0079dde9  5e                   pop esi
// 0079ddea  5d                   pop ebp
// 0079ddeb  33c0                 xor eax, eax
// 0079dded  5b                   pop ebx
// 0079ddee  81c418010000         add esp, 0x118
// 0079ddf4  c3                   ret 
// 0079ddf5  8bc1                 mov eax, ecx
// 0079ddf7  2bc3                 sub eax, ebx
// 0079ddf9  3bce                 cmp ecx, esi
// 0079ddfb  7501                 jne 0x79ddfe
// 0079ddfd  40                   inc eax
// 0079ddfe  50                   push eax
// 0079ddff  57                   push edi
// 0079de00  e87baffeff           call 0x788d80
// 0079de05  68ebd8ffff           push 0xffffd8eb
// 0079de0a  57                   push edi
// 0079de0b  e890aafeff           call 0x7888a0
// 0079de10  8b442434             mov eax, dword ptr [esp + 0x34]
// 0079de14  83c410               add esp, 0x10
// 0079de17  85c0                 test eax, eax
// 0079de19  7507                 jne 0x79de22
// 0079de1b  8d6801               lea ebp, [eax + 1]
// 0079de1e  85f6                 test esi, esi
// 0079de20  7502                 jne 0x79de24
// 0079de22  8be8                 mov ebp, eax
// 0079de24  8b442420             mov eax, dword ptr [esp + 0x20]
// 0079de28  6840b19e00           push 0x9eb140
// 0079de2d  55                   push ebp
// 0079de2e  50                   push eax
// 0079de2f  e84cbffeff           call 0x789d80
// 0079de34  83c40c               add esp, 0xc
// 0079de37  33ff                 xor edi, edi
// 0079de39  85ed                 test ebp, ebp
// 0079de3b  7e5e                 jle 0x79de9b
// 0079de3d  8d4900               lea ecx, [ecx]
// 0079de40  3b7c2424             cmp edi, dword ptr [esp + 0x24]
// 0079de44  7c22                 jl 0x79de68
// 0079de46  85ff                 test edi, edi
// 0079de48  750a                 jne 0x79de54
// 0079de4a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0079de4e  2bce                 sub ecx, esi
// 0079de50  51                   push ecx
// 0079de51  56                   push esi
// 0079de52  eb35                 jmp 0x79de89
// 0079de54  8b442420             mov eax, dword ptr [esp + 0x20]
// 0079de58  68b8b09e00           push 0x9eb0b8
// 0079de5d  50                   push eax
// 0079de5e  e88dbefeff           call 0x789cf0
// 0079de63  83c408               add esp, 8
// 0079de66  eb2e                 jmp 0x79de96
// 0079de68  8b5cfc2c             mov ebx, dword ptr [esp + edi*8 + 0x2c]
// 0079de6c  83fbff               cmp ebx, -1
// 0079de6f  7537                 jne 0x79dea8
// 0079de71  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0079de75  6878b19e00           push 0x9eb178
// 0079de7a  51                   push ecx
// 0079de7b  e870befeff           call 0x789cf0
// 0079de80  83c408               add esp, 8
// 0079de83  8b4cfc28             mov ecx, dword ptr [esp + edi*8 + 0x28]
// 0079de87  53                   push ebx
// 0079de88  51                   push ecx
// 0079de89  8b542428             mov edx, dword ptr [esp + 0x28]
// 0079de8d  52                   push edx
// 0079de8e  e80daffeff           call 0x788da0
// 0079de93  83c40c               add esp, 0xc
// 0079de96  47                   inc edi
// 0079de97  3bfd                 cmp edi, ebp
// 0079de99  7ca5                 jl 0x79de40
// 0079de9b  5f                   pop edi
// 0079de9c  5e                   pop esi
// 0079de9d  8bc5                 mov eax, ebp
// 0079de9f  5d                   pop ebp
// 0079dea0  5b                   pop ebx
// 0079dea1  81c418010000         add esp, 0x118
// 0079dea7  c3                   ret 
// 0079dea8  83fbfe               cmp ebx, -2
// 0079deab  75d6                 jne 0x79de83
// 0079dead  8b54fc28             mov edx, dword ptr [esp + edi*8 + 0x28]
// 0079deb1  2b542418             sub edx, dword ptr [esp + 0x18]
// 0079deb5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0079deb9  42                   inc edx
// 0079deba  52                   push edx
// 0079debb  50                   push eax
// 0079debc  e8bfaefeff           call 0x788d80
// 0079dec1  83c408               add esp, 8
// 0079dec4  ebd0                 jmp 0x79de96
// library lua-5.1/lstrlib.c (function _gmatch_aux)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
