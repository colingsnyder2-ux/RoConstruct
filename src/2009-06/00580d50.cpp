// from server: 100% by auto
// roc 2009-06 00580d50  unit: seg_00580000  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00580d50
//
// 00580d50  57                   push edi
// 00580d51  8b7c2408             mov edi, dword ptr [esp + 8]
// 00580d55  85ff                 test edi, edi
// 00580d57  0f84a6000000         je 0x580e03
// 00580d5d  56                   push esi
// 00580d5e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00580d62  85f6                 test esi, esi
// 00580d64  0f8498000000         je 0x580e02
// 00580d6a  53                   push ebx
// 00580d6b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00580d6f  85db                 test ebx, ebx
// 00580d71  7c08                 jl 0x580d7b
// 00580d73  81fb00010000         cmp ebx, 0x100
// 00580d79  7e14                 jle 0x580d8f
// 00580d7b  807e1903             cmp byte ptr [esi + 0x19], 3
// 00580d7f  6894c78c00           push 0x8cc794
// 00580d84  57                   push edi
// 00580d85  7572                 jne 0x580df9
// 00580d87  e8d4d30000           call 0x58e160
// 00580d8c  83c408               add esp, 8
// 00580d8f  6a00                 push 0
// 00580d91  6800100000           push 0x1000
// 00580d96  56                   push esi
// 00580d97  57                   push edi
// 00580d98  e8730b0000           call 0x581910
// 00580d9d  6800030000           push 0x300
// 00580da2  57                   push edi
// 00580da3  e8a8de0000           call 0x58ec50
// 00580da8  6800030000           push 0x300
// 00580dad  6a00                 push 0
// 00580daf  50                   push eax
// 00580db0  898714010000         mov dword ptr [edi + 0x114], eax
// 00580db6  e8b98e1900           call 0x719c74
// 00580dbb  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00580dbf  8b9714010000         mov edx, dword ptr [edi + 0x114]
// 00580dc5  8d045b               lea eax, [ebx + ebx*2]
// 00580dc8  50                   push eax
// 00580dc9  51                   push ecx
// 00580dca  52                   push edx
// 00580dcb  e8e6901900           call 0x719eb6
// 00580dd0  8b8714010000         mov eax, dword ptr [edi + 0x114]
// 00580dd6  83c430               add esp, 0x30
// 00580dd9  894610               mov dword ptr [esi + 0x10], eax
// 00580ddc  66899f18010000       mov word ptr [edi + 0x118], bx
// 00580de3  818eb800000000100000 or dword ptr [esi + 0xb8], 0x1000
// 00580ded  834e0808             or dword ptr [esi + 8], 8
// 00580df1  66895e14             mov word ptr [esi + 0x14], bx
// 00580df5  5b                   pop ebx
// 00580df6  5e                   pop esi
// 00580df7  5f                   pop edi
// 00580df8  c3                   ret 
// 00580df9  e812d40000           call 0x58e210
// 00580dfe  83c408               add esp, 8
// 00580e01  5b                   pop ebx
// 00580e02  5e                   pop esi
// 00580e03  5f                   pop edi
// 00580e04  c3                   ret 
// library libpng-1.2.10/pngset.c (function _png_set_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngset.c
