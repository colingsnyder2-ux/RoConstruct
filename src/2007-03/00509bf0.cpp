// from server: 100% by auto
// roc 2007-03 00509bf0  unit: seg_00500000  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00509bf0
//
// 00509bf0  57                   push edi
// 00509bf1  8b7c2408             mov edi, dword ptr [esp + 8]
// 00509bf5  85ff                 test edi, edi
// 00509bf7  7476                 je 0x509c6f
// 00509bf9  56                   push esi
// 00509bfa  8b742410             mov esi, dword ptr [esp + 0x10]
// 00509bfe  85f6                 test esi, esi
// 00509c00  746c                 je 0x509c6e
// 00509c02  53                   push ebx
// 00509c03  6a00                 push 0
// 00509c05  6800100000           push 0x1000
// 00509c0a  56                   push esi
// 00509c0b  57                   push edi
// 00509c0c  e86f0b0000           call 0x50a780
// 00509c11  6800030000           push 0x300
// 00509c16  57                   push edi
// 00509c17  e884f30000           call 0x518fa0
// 00509c1c  6800030000           push 0x300
// 00509c21  6a00                 push 0
// 00509c23  50                   push eax
// 00509c24  898714010000         mov dword ptr [edi + 0x114], eax
// 00509c2a  e8ed531100           call 0x61f01c
// 00509c2f  8b5c2440             mov ebx, dword ptr [esp + 0x40]
// 00509c33  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00509c37  8b9714010000         mov edx, dword ptr [edi + 0x114]
// 00509c3d  8d045b               lea eax, [ebx + ebx*2]
// 00509c40  50                   push eax
// 00509c41  51                   push ecx
// 00509c42  52                   push edx
// 00509c43  e89a551100           call 0x61f1e2
// 00509c48  8b8714010000         mov eax, dword ptr [edi + 0x114]
// 00509c4e  83c430               add esp, 0x30
// 00509c51  894610               mov dword ptr [esi + 0x10], eax
// 00509c54  66899f18010000       mov word ptr [edi + 0x118], bx
// 00509c5b  818eb800000000100000 or dword ptr [esi + 0xb8], 0x1000
// 00509c65  834e0808             or dword ptr [esi + 8], 8
// 00509c69  66895e14             mov word ptr [esi + 0x14], bx
// 00509c6d  5b                   pop ebx
// 00509c6e  5e                   pop esi
// 00509c6f  5f                   pop edi
// 00509c70  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
