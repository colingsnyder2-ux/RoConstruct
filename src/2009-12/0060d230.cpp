// from server: 100% by auto
// roc 2009-12 0060d230  unit: seg_00600000  size: 324 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060d230
//
// 0060d230  83ec20               sub esp, 0x20
// 0060d233  8b442428             mov eax, dword ptr [esp + 0x28]
// 0060d237  55                   push ebp
// 0060d238  56                   push esi
// 0060d239  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0060d23d  57                   push edi
// 0060d23e  33ff                 xor edi, edi
// 0060d240  c64424107a           mov byte ptr [esp + 0x10], 0x7a
// 0060d245  c644241154           mov byte ptr [esp + 0x11], 0x54
// 0060d24a  c644241258           mov byte ptr [esp + 0x12], 0x58
// 0060d24f  c644241374           mov byte ptr [esp + 0x13], 0x74
// 0060d254  c644241400           mov byte ptr [esp + 0x14], 0
// 0060d259  897c2420             mov dword ptr [esp + 0x20], edi
// 0060d25d  897c2424             mov dword ptr [esp + 0x24], edi
// 0060d261  897c2428             mov dword ptr [esp + 0x28], edi
// 0060d265  897c2418             mov dword ptr [esp + 0x18], edi
// 0060d269  897c241c             mov dword ptr [esp + 0x1c], edi
// 0060d26d  3bc7                 cmp eax, edi
// 0060d26f  0f84df000000         je 0x60d354
// 0060d275  8d4c240c             lea ecx, [esp + 0xc]
// 0060d279  51                   push ecx
// 0060d27a  50                   push eax
// 0060d27b  56                   push esi
// 0060d27c  e8effcffff           call 0x60cf70
// 0060d281  8be8                 mov ebp, eax
// 0060d283  83c40c               add esp, 0xc
// 0060d286  3bef                 cmp ebp, edi
// 0060d288  0f84c6000000         je 0x60d354
// 0060d28e  8b542438             mov edx, dword ptr [esp + 0x38]
// 0060d292  53                   push ebx
// 0060d293  3bd7                 cmp edx, edi
// 0060d295  0f849a000000         je 0x60d335
// 0060d29b  803a00               cmp byte ptr [edx], 0
// 0060d29e  0f8491000000         je 0x60d335
// 0060d2a4  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 0060d2a8  83fbff               cmp ebx, -1
// 0060d2ab  0f8484000000         je 0x60d335
// 0060d2b1  8bc2                 mov eax, edx
// 0060d2b3  8d7801               lea edi, [eax + 1]
// 0060d2b6  8a08                 mov cl, byte ptr [eax]
// 0060d2b8  40                   inc eax
// 0060d2b9  84c9                 test cl, cl
// 0060d2bb  75f9                 jne 0x60d2b6
// 0060d2bd  2bc7                 sub eax, edi
// 0060d2bf  8bc8                 mov ecx, eax
// 0060d2c1  52                   push edx
// 0060d2c2  8d7c2420             lea edi, [esp + 0x20]
// 0060d2c6  8bc3                 mov eax, ebx
// 0060d2c8  8bd6                 mov edx, esi
// 0060d2ca  e831f7ffff           call 0x60ca00
// 0060d2cf  8d542802             lea edx, [eax + ebp + 2]
// 0060d2d3  52                   push edx
// 0060d2d4  8d44241c             lea eax, [esp + 0x1c]
// 0060d2d8  50                   push eax
// 0060d2d9  56                   push esi
// 0060d2da  e831f6ffff           call 0x60c910
// 0060d2df  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0060d2e3  45                   inc ebp
// 0060d2e4  55                   push ebp
// 0060d2e5  57                   push edi
// 0060d2e6  56                   push esi
// 0060d2e7  e894f6ffff           call 0x60c980
// 0060d2ec  57                   push edi
// 0060d2ed  56                   push esi
// 0060d2ee  e8ed390000           call 0x610ce0
// 0060d2f3  83c424               add esp, 0x24
// 0060d2f6  885c2438             mov byte ptr [esp + 0x38], bl
// 0060d2fa  85f6                 test esi, esi
// 0060d2fc  741d                 je 0x60d31b
// 0060d2fe  6a01                 push 1
// 0060d300  8d4c243c             lea ecx, [esp + 0x3c]
// 0060d304  51                   push ecx
// 0060d305  56                   push esi
// 0060d306  e88560ffff           call 0x603390
// 0060d30b  6a01                 push 1
// 0060d30d  8d542448             lea edx, [esp + 0x48]
// 0060d311  52                   push edx
// 0060d312  56                   push esi
// 0060d313  e85863ffff           call 0x603670
// 0060d318  83c418               add esp, 0x18
// 0060d31b  8d44241c             lea eax, [esp + 0x1c]
// 0060d31f  e85cf9ffff           call 0x60cc80
// 0060d324  56                   push esi
// 0060d325  e896f6ffff           call 0x60c9c0
// 0060d32a  83c404               add esp, 4
// 0060d32d  5b                   pop ebx
// 0060d32e  5f                   pop edi
// 0060d32f  5e                   pop esi
// 0060d330  5d                   pop ebp
// 0060d331  83c420               add esp, 0x20
// 0060d334  c3                   ret 
// 0060d335  57                   push edi
// 0060d336  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0060d33a  52                   push edx
// 0060d33b  57                   push edi
// 0060d33c  56                   push esi
// 0060d33d  e80efeffff           call 0x60d150
// 0060d342  57                   push edi
// 0060d343  56                   push esi
// 0060d344  e897390000           call 0x610ce0
// 0060d349  83c418               add esp, 0x18
// 0060d34c  5b                   pop ebx
// 0060d34d  5f                   pop edi
// 0060d34e  5e                   pop esi
// 0060d34f  5d                   pop ebp
// 0060d350  83c420               add esp, 0x20
// 0060d353  c3                   ret 
// 0060d354  688c5b9c00           push 0x9c5b8c
// 0060d359  56                   push esi
// 0060d35a  e8e12e0000           call 0x610240
// 0060d35f  8b442414             mov eax, dword ptr [esp + 0x14]
// 0060d363  50                   push eax
// 0060d364  56                   push esi
// 0060d365  e876390000           call 0x610ce0
// 0060d36a  83c410               add esp, 0x10
// 0060d36d  5f                   pop edi
// 0060d36e  5e                   pop esi
// 0060d36f  5d                   pop ebp
// 0060d370  83c420               add esp, 0x20
// 0060d373  c3                   ret 
// library libpng-1.2.32/pngwutil.c (function _png_write_zTXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwutil.c
