// from server: 100% by auto
// roc 2009-12 007d3460  unit: seg_007d0000  size: 296 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d3460
//
// 007d3460  83ec24               sub esp, 0x24
// 007d3463  55                   push ebp
// 007d3464  56                   push esi
// 007d3465  8bf0                 mov esi, eax
// 007d3467  8b6e30               mov ebp, dword ptr [esi + 0x30]
// 007d346a  57                   push edi
// 007d346b  56                   push esi
// 007d346c  e8bf320000           call 0x7d6730
// 007d3471  55                   push ebp
// 007d3472  e8198a0000           call 0x7dbe90
// 007d3477  8bf8                 mov edi, eax
// 007d3479  6a00                 push 0
// 007d347b  8d442424             lea eax, [esp + 0x24]
// 007d347f  50                   push eax
// 007d3480  56                   push esi
// 007d3481  e82afcffff           call 0x7d30b0
// 007d3486  83c414               add esp, 0x14
// 007d3489  837c241801           cmp dword ptr [esp + 0x18], 1
// 007d348e  7508                 jne 0x7d3498
// 007d3490  c744241803000000     mov dword ptr [esp + 0x18], 3
// 007d3498  8b5630               mov edx, dword ptr [esi + 0x30]
// 007d349b  8d4c2418             lea ecx, [esp + 0x18]
// 007d349f  51                   push ecx
// 007d34a0  52                   push edx
// 007d34a1  e88a9b0000           call 0x7dd030
// 007d34a6  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 007d34ae  c644241e01           mov byte ptr [esp + 0x1e], 1
// 007d34b3  8a4532               mov al, byte ptr [ebp + 0x32]
// 007d34b6  8844241c             mov byte ptr [esp + 0x1c], al
// 007d34ba  c644241d00           mov byte ptr [esp + 0x1d], 0
// 007d34bf  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 007d34c2  8d542414             lea edx, [esp + 0x14]
// 007d34c6  894c2414             mov dword ptr [esp + 0x14], ecx
// 007d34ca  83c408               add esp, 8
// 007d34cd  895514               mov dword ptr [ebp + 0x14], edx
// 007d34d0  817e1003010000       cmp dword ptr [esi + 0x10], 0x103
// 007d34d7  7424                 je 0x7d34fd
// 007d34d9  6803010000           push 0x103
// 007d34de  56                   push esi
// 007d34df  e85c1d0000           call 0x7d5240
// 007d34e4  50                   push eax
// 007d34e5  8b4634               mov eax, dword ptr [esi + 0x34]
// 007d34e8  68d0ed9e00           push 0x9eedd0
// 007d34ed  50                   push eax
// 007d34ee  e88d70fcff           call 0x79a580
// 007d34f3  50                   push eax
// 007d34f4  56                   push esi
// 007d34f5  e8461e0000           call 0x7d5340
// 007d34fa  83c41c               add esp, 0x1c
// 007d34fd  56                   push esi
// 007d34fe  e82d320000           call 0x7d6730
// 007d3503  83c404               add esp, 4
// 007d3506  8bc6                 mov eax, esi
// 007d3508  e8b3fcffff           call 0x7d31c0
// 007d350d  57                   push edi
// 007d350e  55                   push ebp
// 007d350f  e87c920000           call 0x7dc790
// 007d3514  83c404               add esp, 4
// 007d3517  50                   push eax
// 007d3518  55                   push ebp
// 007d3519  e832a20000           call 0x7dd750
// 007d351e  8b442440             mov eax, dword ptr [esp + 0x40]
// 007d3522  6815010000           push 0x115
// 007d3527  bf06010000           mov edi, 0x106
// 007d352c  e8afe3ffff           call 0x7d18e0
// 007d3531  8b7514               mov esi, dword ptr [ebp + 0x14]
// 007d3534  8b0e                 mov ecx, dword ptr [esi]
// 007d3536  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007d3539  894d14               mov dword ptr [ebp + 0x14], ecx
// 007d353c  0fb65608             movzx edx, byte ptr [esi + 8]
// 007d3540  83c410               add esp, 0x10
// 007d3543  e868e5ffff           call 0x7d1ab0
// 007d3548  807e0900             cmp byte ptr [esi + 9], 0
// 007d354c  7414                 je 0x7d3562
// 007d354e  0fb65608             movzx edx, byte ptr [esi + 8]
// 007d3552  6a00                 push 0
// 007d3554  6a00                 push 0
// 007d3556  52                   push edx
// 007d3557  6a23                 push 0x23
// 007d3559  55                   push ebp
// 007d355a  e8a1900000           call 0x7dc600
// 007d355f  83c414               add esp, 0x14
// 007d3562  0fb64532             movzx eax, byte ptr [ebp + 0x32]
// 007d3566  894524               mov dword ptr [ebp + 0x24], eax
// 007d3569  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d356c  51                   push ecx
// 007d356d  55                   push ebp
// 007d356e  e8ed920000           call 0x7dc860
// 007d3573  8b542434             mov edx, dword ptr [esp + 0x34]
// 007d3577  52                   push edx
// 007d3578  55                   push ebp
// 007d3579  e8e2920000           call 0x7dc860
// 007d357e  83c410               add esp, 0x10
// 007d3581  5f                   pop edi
// 007d3582  5e                   pop esi
// 007d3583  5d                   pop ebp
// 007d3584  83c424               add esp, 0x24
// 007d3587  c3                   ret 
// library lua-5.1/lparser.c (function _whilestat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
