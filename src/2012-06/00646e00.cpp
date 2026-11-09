// from server: 100% by auto
// roc 2012-06 00646e00  unit: seg_00640000  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00646e00
//
// 00646e00  57                   push edi
// 00646e01  8b7c2408             mov edi, dword ptr [esp + 8]
// 00646e05  85ff                 test edi, edi
// 00646e07  0f84a6000000         je 0x646eb3
// 00646e0d  56                   push esi
// 00646e0e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00646e12  85f6                 test esi, esi
// 00646e14  0f8498000000         je 0x646eb2
// 00646e1a  53                   push ebx
// 00646e1b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00646e1f  85db                 test ebx, ebx
// 00646e21  7c08                 jl 0x646e2b
// 00646e23  81fb00010000         cmp ebx, 0x100
// 00646e29  7e14                 jle 0x646e3f
// 00646e2b  807e1903             cmp byte ptr [esi + 0x19], 3
// 00646e2f  68b862b800           push 0xb862b8
// 00646e34  57                   push edi
// 00646e35  7572                 jne 0x646ea9
// 00646e37  e874730000           call 0x64e1b0
// 00646e3c  83c408               add esp, 8
// 00646e3f  6a00                 push 0
// 00646e41  6800100000           push 0x1000
// 00646e46  56                   push esi
// 00646e47  57                   push edi
// 00646e48  e89370ffff           call 0x63dee0
// 00646e4d  6800030000           push 0x300
// 00646e52  57                   push edi
// 00646e53  e868760000           call 0x64e4c0
// 00646e58  6800030000           push 0x300
// 00646e5d  6a00                 push 0
// 00646e5f  50                   push eax
// 00646e60  898714010000         mov dword ptr [edi + 0x114], eax
// 00646e66  e809c53300           call 0x983374
// 00646e6b  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00646e6f  8b9714010000         mov edx, dword ptr [edi + 0x114]
// 00646e75  8d045b               lea eax, [ebx + ebx*2]
// 00646e78  50                   push eax
// 00646e79  51                   push ecx
// 00646e7a  52                   push edx
// 00646e7b  e8dcc73300           call 0x98365c
// 00646e80  8b8714010000         mov eax, dword ptr [edi + 0x114]
// 00646e86  83c430               add esp, 0x30
// 00646e89  894610               mov dword ptr [esi + 0x10], eax
// 00646e8c  66899f18010000       mov word ptr [edi + 0x118], bx
// 00646e93  818eb800000000100000 or dword ptr [esi + 0xb8], 0x1000
// 00646e9d  834e0808             or dword ptr [esi + 8], 8
// 00646ea1  66895e14             mov word ptr [esi + 0x14], bx
// 00646ea5  5b                   pop ebx
// 00646ea6  5e                   pop esi
// 00646ea7  5f                   pop edi
// 00646ea8  c3                   ret 
// 00646ea9  e8b2730000           call 0x64e260
// 00646eae  83c408               add esp, 8
// 00646eb1  5b                   pop ebx
// 00646eb2  5e                   pop esi
// 00646eb3  5f                   pop edi
// 00646eb4  c3                   ret 
// library libpng-1.2.10/pngset.c (function _png_set_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngset.c
