// from server: 100% by auto
// roc 2009-12 007d3590  unit: seg_007d0000  size: 334 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d3590
//
// 007d3590  83ec34               sub esp, 0x34
// 007d3593  55                   push ebp
// 007d3594  8b6b30               mov ebp, dword ptr [ebx + 0x30]
// 007d3597  56                   push esi
// 007d3598  57                   push edi
// 007d3599  55                   push ebp
// 007d359a  e8f1880000           call 0x7dbe90
// 007d359f  c644242a01           mov byte ptr [esp + 0x2a], 1
// 007d35a4  89442410             mov dword ptr [esp + 0x10], eax
// 007d35a8  83c8ff               or eax, 0xffffffff
// 007d35ab  89442424             mov dword ptr [esp + 0x24], eax
// 007d35af  8a4d32               mov cl, byte ptr [ebp + 0x32]
// 007d35b2  884c2428             mov byte ptr [esp + 0x28], cl
// 007d35b6  c644242900           mov byte ptr [esp + 0x29], 0
// 007d35bb  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007d35be  89542420             mov dword ptr [esp + 0x20], edx
// 007d35c2  8d4c2420             lea ecx, [esp + 0x20]
// 007d35c6  894d14               mov dword ptr [ebp + 0x14], ecx
// 007d35c9  89442418             mov dword ptr [esp + 0x18], eax
// 007d35cd  c644241e00           mov byte ptr [esp + 0x1e], 0
// 007d35d2  8a5532               mov dl, byte ptr [ebp + 0x32]
// 007d35d5  8854241c             mov byte ptr [esp + 0x1c], dl
// 007d35d9  c644241d00           mov byte ptr [esp + 0x1d], 0
// 007d35de  8b4514               mov eax, dword ptr [ebp + 0x14]
// 007d35e1  8d4c2414             lea ecx, [esp + 0x14]
// 007d35e5  89442414             mov dword ptr [esp + 0x14], eax
// 007d35e9  53                   push ebx
// 007d35ea  894d14               mov dword ptr [ebp + 0x14], ecx
// 007d35ed  e83e310000           call 0x7d6730
// 007d35f2  53                   push ebx
// 007d35f3  e8a80f0000           call 0x7d45a0
// 007d35f8  8b442450             mov eax, dword ptr [esp + 0x50]
// 007d35fc  6810010000           push 0x110
// 007d3601  bf14010000           mov edi, 0x114
// 007d3606  8bf3                 mov esi, ebx
// 007d3608  e8d3e2ffff           call 0x7d18e0
// 007d360d  6a00                 push 0
// 007d360f  8d54243c             lea edx, [esp + 0x3c]
// 007d3613  52                   push edx
// 007d3614  53                   push ebx
// 007d3615  e896faffff           call 0x7d30b0
// 007d361a  83c41c               add esp, 0x1c
// 007d361d  837c242801           cmp dword ptr [esp + 0x28], 1
// 007d3622  7508                 jne 0x7d362c
// 007d3624  c744242803000000     mov dword ptr [esp + 0x28], 3
// 007d362c  8b4b30               mov ecx, dword ptr [ebx + 0x30]
// 007d362f  8d442428             lea eax, [esp + 0x28]
// 007d3633  50                   push eax
// 007d3634  51                   push ecx
// 007d3635  e8f6990000           call 0x7dd030
// 007d363a  83c408               add esp, 8
// 007d363d  807c241900           cmp byte ptr [esp + 0x19], 0
// 007d3642  7517                 jne 0x7d365b
// 007d3644  8bf5                 mov esi, ebp
// 007d3646  e895e7ffff           call 0x7d1de0
// 007d364b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007d364f  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 007d3653  8b4b30               mov ecx, dword ptr [ebx + 0x30]
// 007d3656  52                   push edx
// 007d3657  50                   push eax
// 007d3658  51                   push ecx
// 007d3659  eb32                 jmp 0x7d368d
// 007d365b  8bc3                 mov eax, ebx
// 007d365d  e89efdffff           call 0x7d3400
// 007d3662  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 007d3666  8b4330               mov eax, dword ptr [ebx + 0x30]
// 007d3669  52                   push edx
// 007d366a  50                   push eax
// 007d366b  e8f0910000           call 0x7dc860
// 007d3670  83c408               add esp, 8
// 007d3673  8bf5                 mov esi, ebp
// 007d3675  e866e7ffff           call 0x7d1de0
// 007d367a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007d367e  51                   push ecx
// 007d367f  55                   push ebp
// 007d3680  e80b910000           call 0x7dc790
// 007d3685  8b5330               mov edx, dword ptr [ebx + 0x30]
// 007d3688  83c404               add esp, 4
// 007d368b  50                   push eax
// 007d368c  52                   push edx
// 007d368d  e8bea00000           call 0x7dd750
// 007d3692  8b7514               mov esi, dword ptr [ebp + 0x14]
// 007d3695  8b06                 mov eax, dword ptr [esi]
// 007d3697  894514               mov dword ptr [ebp + 0x14], eax
// 007d369a  0fb65608             movzx edx, byte ptr [esi + 8]
// 007d369e  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007d36a1  83c40c               add esp, 0xc
// 007d36a4  e807e4ffff           call 0x7d1ab0
// 007d36a9  807e0900             cmp byte ptr [esi + 9], 0
// 007d36ad  7414                 je 0x7d36c3
// 007d36af  0fb64e08             movzx ecx, byte ptr [esi + 8]
// 007d36b3  6a00                 push 0
// 007d36b5  6a00                 push 0
// 007d36b7  51                   push ecx
// 007d36b8  6a23                 push 0x23
// 007d36ba  55                   push ebp
// 007d36bb  e8408f0000           call 0x7dc600
// 007d36c0  83c414               add esp, 0x14
// 007d36c3  0fb65532             movzx edx, byte ptr [ebp + 0x32]
// 007d36c7  895524               mov dword ptr [ebp + 0x24], edx
// 007d36ca  8b4604               mov eax, dword ptr [esi + 4]
// 007d36cd  50                   push eax
// 007d36ce  55                   push ebp
// 007d36cf  e88c910000           call 0x7dc860
// 007d36d4  83c408               add esp, 8
// 007d36d7  5f                   pop edi
// 007d36d8  5e                   pop esi
// 007d36d9  5d                   pop ebp
// 007d36da  83c434               add esp, 0x34
// 007d36dd  c3                   ret 
// library lua-5.1/lparser.c (function _repeatstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
