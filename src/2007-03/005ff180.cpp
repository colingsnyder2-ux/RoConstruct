// from server: 100% by auto
// roc 2007-03 005ff180  unit: seg_005f0000  size: 334 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ff180
//
// 005ff180  83ec34               sub esp, 0x34
// 005ff183  55                   push ebp
// 005ff184  8b6b30               mov ebp, dword ptr [ebx + 0x30]
// 005ff187  56                   push esi
// 005ff188  57                   push edi
// 005ff189  55                   push ebp
// 005ff18a  e881520100           call 0x614410
// 005ff18f  c644242a01           mov byte ptr [esp + 0x2a], 1
// 005ff194  89442410             mov dword ptr [esp + 0x10], eax
// 005ff198  83c8ff               or eax, 0xffffffff
// 005ff19b  89442424             mov dword ptr [esp + 0x24], eax
// 005ff19f  8a4d32               mov cl, byte ptr [ebp + 0x32]
// 005ff1a2  884c2428             mov byte ptr [esp + 0x28], cl
// 005ff1a6  c644242900           mov byte ptr [esp + 0x29], 0
// 005ff1ab  8b5514               mov edx, dword ptr [ebp + 0x14]
// 005ff1ae  89542420             mov dword ptr [esp + 0x20], edx
// 005ff1b2  8d4c2420             lea ecx, [esp + 0x20]
// 005ff1b6  894d14               mov dword ptr [ebp + 0x14], ecx
// 005ff1b9  89442418             mov dword ptr [esp + 0x18], eax
// 005ff1bd  c644241e00           mov byte ptr [esp + 0x1e], 0
// 005ff1c2  8a5532               mov dl, byte ptr [ebp + 0x32]
// 005ff1c5  8854241c             mov byte ptr [esp + 0x1c], dl
// 005ff1c9  c644241d00           mov byte ptr [esp + 0x1d], 0
// 005ff1ce  8b4514               mov eax, dword ptr [ebp + 0x14]
// 005ff1d1  8d4c2414             lea ecx, [esp + 0x14]
// 005ff1d5  89442414             mov dword ptr [esp + 0x14], eax
// 005ff1d9  53                   push ebx
// 005ff1da  894d14               mov dword ptr [ebp + 0x14], ecx
// 005ff1dd  e8be310000           call 0x6023a0
// 005ff1e2  53                   push ebx
// 005ff1e3  e8b80f0000           call 0x6001a0
// 005ff1e8  8b442450             mov eax, dword ptr [esp + 0x50]
// 005ff1ec  6810010000           push 0x110
// 005ff1f1  bf14010000           mov edi, 0x114
// 005ff1f6  8bf3                 mov esi, ebx
// 005ff1f8  e8d3e2ffff           call 0x5fd4d0
// 005ff1fd  6a00                 push 0
// 005ff1ff  8d54243c             lea edx, [esp + 0x3c]
// 005ff203  52                   push edx
// 005ff204  53                   push ebx
// 005ff205  e8c6faffff           call 0x5fecd0
// 005ff20a  83c41c               add esp, 0x1c
// 005ff20d  837c242801           cmp dword ptr [esp + 0x28], 1
// 005ff212  7508                 jne 0x5ff21c
// 005ff214  c744242803000000     mov dword ptr [esp + 0x28], 3
// 005ff21c  8b4b30               mov ecx, dword ptr [ebx + 0x30]
// 005ff21f  8d442428             lea eax, [esp + 0x28]
// 005ff223  50                   push eax
// 005ff224  51                   push ecx
// 005ff225  e8b6630100           call 0x6155e0
// 005ff22a  83c408               add esp, 8
// 005ff22d  807c241900           cmp byte ptr [esp + 0x19], 0
// 005ff232  7517                 jne 0x5ff24b
// 005ff234  8bf5                 mov esi, ebp
// 005ff236  e8b5e7ffff           call 0x5fd9f0
// 005ff23b  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005ff23f  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 005ff243  8b4b30               mov ecx, dword ptr [ebx + 0x30]
// 005ff246  52                   push edx
// 005ff247  50                   push eax
// 005ff248  51                   push ecx
// 005ff249  eb32                 jmp 0x5ff27d
// 005ff24b  8bc3                 mov eax, ebx
// 005ff24d  e89efdffff           call 0x5feff0
// 005ff252  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005ff256  8b4330               mov eax, dword ptr [ebx + 0x30]
// 005ff259  52                   push edx
// 005ff25a  50                   push eax
// 005ff25b  e8b05b0100           call 0x614e10
// 005ff260  83c408               add esp, 8
// 005ff263  8bf5                 mov esi, ebp
// 005ff265  e886e7ffff           call 0x5fd9f0
// 005ff26a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005ff26e  51                   push ecx
// 005ff26f  55                   push ebp
// 005ff270  e8cb5a0100           call 0x614d40
// 005ff275  8b5330               mov edx, dword ptr [ebx + 0x30]
// 005ff278  83c404               add esp, 4
// 005ff27b  50                   push eax
// 005ff27c  52                   push edx
// 005ff27d  e80e6a0100           call 0x615c90
// 005ff282  8b7514               mov esi, dword ptr [ebp + 0x14]
// 005ff285  8b06                 mov eax, dword ptr [esi]
// 005ff287  894514               mov dword ptr [ebp + 0x14], eax
// 005ff28a  0fb65608             movzx edx, byte ptr [esi + 8]
// 005ff28e  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005ff291  83c40c               add esp, 0xc
// 005ff294  e817e4ffff           call 0x5fd6b0
// 005ff299  807e0900             cmp byte ptr [esi + 9], 0
// 005ff29d  7414                 je 0x5ff2b3
// 005ff29f  0fb64e08             movzx ecx, byte ptr [esi + 8]
// 005ff2a3  6a00                 push 0
// 005ff2a5  6a00                 push 0
// 005ff2a7  51                   push ecx
// 005ff2a8  6a23                 push 0x23
// 005ff2aa  55                   push ebp
// 005ff2ab  e800590100           call 0x614bb0
// 005ff2b0  83c414               add esp, 0x14
// 005ff2b3  0fb65532             movzx edx, byte ptr [ebp + 0x32]
// 005ff2b7  895524               mov dword ptr [ebp + 0x24], edx
// 005ff2ba  8b4604               mov eax, dword ptr [esi + 4]
// 005ff2bd  50                   push eax
// 005ff2be  55                   push ebp
// 005ff2bf  e84c5b0100           call 0x614e10
// 005ff2c4  83c408               add esp, 8
// 005ff2c7  5f                   pop edi
// 005ff2c8  5e                   pop esi
// 005ff2c9  5d                   pop ebp
// 005ff2ca  83c434               add esp, 0x34
// 005ff2cd  c3                   ret 
// library lua-5.1.1/lparser.c (function _repeatstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
