// from server: 100% by auto
// roc 2010-06 00564470  unit: seg_00560000  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00564470
//
// 00564470  57                   push edi
// 00564471  8b7c2408             mov edi, dword ptr [esp + 8]
// 00564475  85ff                 test edi, edi
// 00564477  0f84a6000000         je 0x564523
// 0056447d  56                   push esi
// 0056447e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00564482  85f6                 test esi, esi
// 00564484  0f8498000000         je 0x564522
// 0056448a  53                   push ebx
// 0056448b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0056448f  85db                 test ebx, ebx
// 00564491  7c08                 jl 0x56449b
// 00564493  81fb00010000         cmp ebx, 0x100
// 00564499  7e14                 jle 0x5644af
// 0056449b  807e1903             cmp byte ptr [esi + 0x19], 3
// 0056449f  688c13a200           push 0xa2138c
// 005644a4  57                   push edi
// 005644a5  7572                 jne 0x564519
// 005644a7  e804d60000           call 0x571ab0
// 005644ac  83c408               add esp, 8
// 005644af  6a00                 push 0
// 005644b1  6800100000           push 0x1000
// 005644b6  56                   push esi
// 005644b7  57                   push edi
// 005644b8  e8730b0000           call 0x565030
// 005644bd  6800030000           push 0x300
// 005644c2  57                   push edi
// 005644c3  e8d8e00000           call 0x5725a0
// 005644c8  6800030000           push 0x300
// 005644cd  6a00                 push 0
// 005644cf  50                   push eax
// 005644d0  898714010000         mov dword ptr [edi + 0x114], eax
// 005644d6  e809472400           call 0x7a8be4
// 005644db  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005644df  8b9714010000         mov edx, dword ptr [edi + 0x114]
// 005644e5  8d045b               lea eax, [ebx + ebx*2]
// 005644e8  50                   push eax
// 005644e9  51                   push ecx
// 005644ea  52                   push edx
// 005644eb  e836492400           call 0x7a8e26
// 005644f0  8b8714010000         mov eax, dword ptr [edi + 0x114]
// 005644f6  83c430               add esp, 0x30
// 005644f9  894610               mov dword ptr [esi + 0x10], eax
// 005644fc  66899f18010000       mov word ptr [edi + 0x118], bx
// 00564503  818eb800000000100000 or dword ptr [esi + 0xb8], 0x1000
// 0056450d  834e0808             or dword ptr [esi + 8], 8
// 00564511  66895e14             mov word ptr [esi + 0x14], bx
// 00564515  5b                   pop ebx
// 00564516  5e                   pop esi
// 00564517  5f                   pop edi
// 00564518  c3                   ret 
// 00564519  e842d60000           call 0x571b60
// 0056451e  83c408               add esp, 8
// 00564521  5b                   pop ebx
// 00564522  5e                   pop esi
// 00564523  5f                   pop edi
// 00564524  c3                   ret 
// library libpng-1.2.10/pngset.c (function _png_set_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngset.c
