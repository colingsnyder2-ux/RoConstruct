// from server: 100% by auto
// roc 2011-06 00559f80  unit: seg_00550000  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00559f80
//
// 00559f80  57                   push edi
// 00559f81  8b7c2408             mov edi, dword ptr [esp + 8]
// 00559f85  85ff                 test edi, edi
// 00559f87  0f84a6000000         je 0x55a033
// 00559f8d  56                   push esi
// 00559f8e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00559f92  85f6                 test esi, esi
// 00559f94  0f8498000000         je 0x55a032
// 00559f9a  53                   push ebx
// 00559f9b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00559f9f  85db                 test ebx, ebx
// 00559fa1  7c08                 jl 0x559fab
// 00559fa3  81fb00010000         cmp ebx, 0x100
// 00559fa9  7e14                 jle 0x559fbf
// 00559fab  807e1903             cmp byte ptr [esi + 0x19], 3
// 00559faf  680824a800           push 0xa82408
// 00559fb4  57                   push edi
// 00559fb5  7572                 jne 0x55a029
// 00559fb7  e874730000           call 0x561330
// 00559fbc  83c408               add esp, 8
// 00559fbf  6a00                 push 0
// 00559fc1  6800100000           push 0x1000
// 00559fc6  56                   push esi
// 00559fc7  57                   push edi
// 00559fc8  e8d368ffff           call 0x5508a0
// 00559fcd  6800030000           push 0x300
// 00559fd2  57                   push edi
// 00559fd3  e868760000           call 0x561640
// 00559fd8  6800030000           push 0x300
// 00559fdd  6a00                 push 0
// 00559fdf  50                   push eax
// 00559fe0  898714010000         mov dword ptr [edi + 0x114], eax
// 00559fe6  e8f9122b00           call 0x80b2e4
// 00559feb  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00559fef  8b9714010000         mov edx, dword ptr [edi + 0x114]
// 00559ff5  8d045b               lea eax, [ebx + ebx*2]
// 00559ff8  50                   push eax
// 00559ff9  51                   push ecx
// 00559ffa  52                   push edx
// 00559ffb  e8dc152b00           call 0x80b5dc
// 0055a000  8b8714010000         mov eax, dword ptr [edi + 0x114]
// 0055a006  83c430               add esp, 0x30
// 0055a009  894610               mov dword ptr [esi + 0x10], eax
// 0055a00c  66899f18010000       mov word ptr [edi + 0x118], bx
// 0055a013  818eb800000000100000 or dword ptr [esi + 0xb8], 0x1000
// 0055a01d  834e0808             or dword ptr [esi + 8], 8
// 0055a021  66895e14             mov word ptr [esi + 0x14], bx
// 0055a025  5b                   pop ebx
// 0055a026  5e                   pop esi
// 0055a027  5f                   pop edi
// 0055a028  c3                   ret 
// 0055a029  e8b2730000           call 0x5613e0
// 0055a02e  83c408               add esp, 8
// 0055a031  5b                   pop ebx
// 0055a032  5e                   pop esi
// 0055a033  5f                   pop edi
// 0055a034  c3                   ret 
// library libpng-1.2.10/pngset.c (function _png_set_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngset.c
