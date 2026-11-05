// from server: 100% by auto
// roc 2010-06 0056fb90  unit: G3D::LineSegment  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056fb90
//
// 0056fb90  83ec1c               sub esp, 0x1c
// 0056fb93  53                   push ebx
// 0056fb94  b043                 mov al, 0x43
// 0056fb96  56                   push esi
// 0056fb97  8b742428             mov esi, dword ptr [esp + 0x28]
// 0056fb9b  57                   push edi
// 0056fb9c  33ff                 xor edi, edi
// 0056fb9e  8844240d             mov byte ptr [esp + 0xd], al
// 0056fba2  8844240e             mov byte ptr [esp + 0xe], al
// 0056fba6  8b442430             mov eax, dword ptr [esp + 0x30]
// 0056fbaa  c644240c69           mov byte ptr [esp + 0xc], 0x69
// 0056fbaf  c644240f50           mov byte ptr [esp + 0xf], 0x50
// 0056fbb4  c644241000           mov byte ptr [esp + 0x10], 0
// 0056fbb9  897c241c             mov dword ptr [esp + 0x1c], edi
// 0056fbbd  897c2420             mov dword ptr [esp + 0x20], edi
// 0056fbc1  897c2424             mov dword ptr [esp + 0x24], edi
// 0056fbc5  897c2414             mov dword ptr [esp + 0x14], edi
// 0056fbc9  897c2418             mov dword ptr [esp + 0x18], edi
// 0056fbcd  3bc7                 cmp eax, edi
// 0056fbcf  0f84f6000000         je 0x56fccb
// 0056fbd5  8d4c2430             lea ecx, [esp + 0x30]
// 0056fbd9  51                   push ecx
// 0056fbda  50                   push eax
// 0056fbdb  56                   push esi
// 0056fbdc  e8afecffff           call 0x56e890
// 0056fbe1  8bd8                 mov ebx, eax
// 0056fbe3  83c40c               add esp, 0xc
// 0056fbe6  3bdf                 cmp ebx, edi
// 0056fbe8  0f84dd000000         je 0x56fccb
// 0056fbee  397c2434             cmp dword ptr [esp + 0x34], edi
// 0056fbf2  740e                 je 0x56fc02
// 0056fbf4  683c3ca200           push 0xa23c3c
// 0056fbf9  56                   push esi
// 0056fbfa  e8611f0000           call 0x571b60
// 0056fbff  83c408               add esp, 8
// 0056fc02  8b442438             mov eax, dword ptr [esp + 0x38]
// 0056fc06  55                   push ebp
// 0056fc07  3bc7                 cmp eax, edi
// 0056fc09  7504                 jne 0x56fc0f
// 0056fc0b  33ed                 xor ebp, ebp
// 0056fc0d  eb70                 jmp 0x56fc7f
// 0056fc0f  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0056fc13  83fd03               cmp ebp, 3
// 0056fc16  7e1e                 jle 0x56fc36
// 0056fc18  0fb638               movzx edi, byte ptr [eax]
// 0056fc1b  0fb65001             movzx edx, byte ptr [eax + 1]
// 0056fc1f  0fb64802             movzx ecx, byte ptr [eax + 2]
// 0056fc23  c1e708               shl edi, 8
// 0056fc26  0bfa                 or edi, edx
// 0056fc28  0fb65003             movzx edx, byte ptr [eax + 3]
// 0056fc2c  c1e708               shl edi, 8
// 0056fc2f  0bf9                 or edi, ecx
// 0056fc31  c1e708               shl edi, 8
// 0056fc34  0bfa                 or edi, edx
// 0056fc36  3bef                 cmp ebp, edi
// 0056fc38  7d16                 jge 0x56fc50
// 0056fc3a  680c3ca200           push 0xa23c0c
// 0056fc3f  56                   push esi
// 0056fc40  e81b1f0000           call 0x571b60
// 0056fc45  83c408               add esp, 8
// 0056fc48  5d                   pop ebp
// 0056fc49  5f                   pop edi
// 0056fc4a  5e                   pop esi
// 0056fc4b  5b                   pop ebx
// 0056fc4c  83c41c               add esp, 0x1c
// 0056fc4f  c3                   ret 
// 0056fc50  7e14                 jle 0x56fc66
// 0056fc52  68d83ba200           push 0xa23bd8
// 0056fc57  56                   push esi
// 0056fc58  e8031f0000           call 0x571b60
// 0056fc5d  8b442444             mov eax, dword ptr [esp + 0x44]
// 0056fc61  83c408               add esp, 8
// 0056fc64  8bef                 mov ebp, edi
// 0056fc66  85ed                 test ebp, ebp
// 0056fc68  7415                 je 0x56fc7f
// 0056fc6a  50                   push eax
// 0056fc6b  8d7c241c             lea edi, [esp + 0x1c]
// 0056fc6f  33c0                 xor eax, eax
// 0056fc71  8bcd                 mov ecx, ebp
// 0056fc73  8bd6                 mov edx, esi
// 0056fc75  e8a6e6ffff           call 0x56e320
// 0056fc7a  83c404               add esp, 4
// 0056fc7d  8be8                 mov ebp, eax
// 0056fc7f  8d442b02             lea eax, [ebx + ebp + 2]
// 0056fc83  50                   push eax
// 0056fc84  8d4c2414             lea ecx, [esp + 0x14]
// 0056fc88  51                   push ecx
// 0056fc89  56                   push esi
// 0056fc8a  e8a1e5ffff           call 0x56e230
// 0056fc8f  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 0056fc93  c6441f0100           mov byte ptr [edi + ebx + 1], 0
// 0056fc98  83c302               add ebx, 2
// 0056fc9b  53                   push ebx
// 0056fc9c  57                   push edi
// 0056fc9d  56                   push esi
// 0056fc9e  e8fde5ffff           call 0x56e2a0
// 0056fca3  83c418               add esp, 0x18
// 0056fca6  85ed                 test ebp, ebp
// 0056fca8  7409                 je 0x56fcb3
// 0056fcaa  8d442418             lea eax, [esp + 0x18]
// 0056fcae  e8ede8ffff           call 0x56e5a0
// 0056fcb3  56                   push esi
// 0056fcb4  e827e6ffff           call 0x56e2e0
// 0056fcb9  57                   push edi
// 0056fcba  56                   push esi
// 0056fcbb  e840290000           call 0x572600
// 0056fcc0  83c40c               add esp, 0xc
// 0056fcc3  5d                   pop ebp
// 0056fcc4  5f                   pop edi
// 0056fcc5  5e                   pop esi
// 0056fcc6  5b                   pop ebx
// 0056fcc7  83c41c               add esp, 0x1c
// 0056fcca  c3                   ret 
// 0056fccb  68bc3ba200           push 0xa23bbc
// 0056fcd0  56                   push esi
// 0056fcd1  e88a1e0000           call 0x571b60
// 0056fcd6  83c408               add esp, 8
// 0056fcd9  5f                   pop edi
// 0056fcda  5e                   pop esi
// 0056fcdb  5b                   pop ebx
// 0056fcdc  83c41c               add esp, 0x1c
// 0056fcdf  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
