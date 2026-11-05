// from server: 100% by auto
// roc 2010-06 00564bb0  unit: seg_00560000  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00564bb0
//
// 00564bb0  51                   push ecx
// 00564bb1  53                   push ebx
// 00564bb2  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00564bb6  85db                 test ebx, ebx
// 00564bb8  0f843f010000         je 0x564cfd
// 00564bbe  55                   push ebp
// 00564bbf  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00564bc3  85ed                 test ebp, ebp
// 00564bc5  0f8431010000         je 0x564cfc
// 00564bcb  57                   push edi
// 00564bcc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00564bd0  85ff                 test edi, edi
// 00564bd2  0f8423010000         je 0x564cfb
// 00564bd8  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 00564bde  03c7                 add eax, edi
// 00564be0  8d0480               lea eax, [eax + eax*4]
// 00564be3  03c0                 add eax, eax
// 00564be5  56                   push esi
// 00564be6  03c0                 add eax, eax
// 00564be8  50                   push eax
// 00564be9  53                   push ebx
// 00564bea  e841da0000           call 0x572630
// 00564bef  8bf0                 mov esi, eax
// 00564bf1  83c408               add esp, 8
// 00564bf4  89742410             mov dword ptr [esp + 0x10], esi
// 00564bf8  85f6                 test esi, esi
// 00564bfa  7514                 jne 0x564c10
// 00564bfc  68e814a200           push 0xa214e8
// 00564c01  53                   push ebx
// 00564c02  e859cf0000           call 0x571b60
// 00564c07  83c408               add esp, 8
// 00564c0a  5e                   pop esi
// 00564c0b  5f                   pop edi
// 00564c0c  5d                   pop ebp
// 00564c0d  5b                   pop ebx
// 00564c0e  59                   pop ecx
// 00564c0f  c3                   ret 
// 00564c10  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 00564c16  8b95bc000000         mov edx, dword ptr [ebp + 0xbc]
// 00564c1c  8d0c80               lea ecx, [eax + eax*4]
// 00564c1f  03c9                 add ecx, ecx
// 00564c21  03c9                 add ecx, ecx
// 00564c23  51                   push ecx
// 00564c24  52                   push edx
// 00564c25  56                   push esi
// 00564c26  e8fb412400           call 0x7a8e26
// 00564c2b  8b85bc000000         mov eax, dword ptr [ebp + 0xbc]
// 00564c31  50                   push eax
// 00564c32  53                   push ebx
// 00564c33  e8c8d90000           call 0x572600
// 00564c38  33c9                 xor ecx, ecx
// 00564c3a  83c414               add esp, 0x14
// 00564c3d  3bf9                 cmp edi, ecx
// 00564c3f  898dbc000000         mov dword ptr [ebp + 0xbc], ecx
// 00564c45  894c2418             mov dword ptr [esp + 0x18], ecx
// 00564c49  0f8e95000000         jle 0x564ce4
// 00564c4f  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00564c53  83c70c               add edi, 0xc
// 00564c56  eb08                 jmp 0x564c60
// 00564c58  8da42400000000       lea esp, [esp]
// 00564c5f  90                   nop 
// 00564c60  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 00564c66  8b57f4               mov edx, dword ptr [edi - 0xc]
// 00564c69  03c1                 add eax, ecx
// 00564c6b  8d0c80               lea ecx, [eax + eax*4]
// 00564c6e  8d348e               lea esi, [esi + ecx*4]
// 00564c71  8916                 mov dword ptr [esi], edx
// 00564c73  c6460400             mov byte ptr [esi + 4], 0
// 00564c77  8b0f                 mov ecx, dword ptr [edi]
// 00564c79  894e0c               mov dword ptr [esi + 0xc], ecx
// 00564c7c  8a5368               mov dl, byte ptr [ebx + 0x68]
// 00564c7f  885610               mov byte ptr [esi + 0x10], dl
// 00564c82  833f00               cmp dword ptr [edi], 0
// 00564c85  7509                 jne 0x564c90
// 00564c87  c7460800000000       mov dword ptr [esi + 8], 0
// 00564c8e  eb3a                 jmp 0x564cca
// 00564c90  8b07                 mov eax, dword ptr [edi]
// 00564c92  50                   push eax
// 00564c93  53                   push ebx
// 00564c94  e897d90000           call 0x572630
// 00564c99  83c408               add esp, 8
// 00564c9c  894608               mov dword ptr [esi + 8], eax
// 00564c9f  85c0                 test eax, eax
// 00564ca1  7517                 jne 0x564cba
// 00564ca3  68e814a200           push 0xa214e8
// 00564ca8  53                   push ebx
// 00564ca9  e8b2ce0000           call 0x571b60
// 00564cae  83c408               add esp, 8
// 00564cb1  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00564cb8  eb10                 jmp 0x564cca
// 00564cba  8b0f                 mov ecx, dword ptr [edi]
// 00564cbc  8b57fc               mov edx, dword ptr [edi - 4]
// 00564cbf  51                   push ecx
// 00564cc0  52                   push edx
// 00564cc1  50                   push eax
// 00564cc2  e85f412400           call 0x7a8e26
// 00564cc7  83c40c               add esp, 0xc
// 00564cca  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00564cce  8b742410             mov esi, dword ptr [esp + 0x10]
// 00564cd2  41                   inc ecx
// 00564cd3  83c714               add edi, 0x14
// 00564cd6  3b4c2424             cmp ecx, dword ptr [esp + 0x24]
// 00564cda  894c2418             mov dword ptr [esp + 0x18], ecx
// 00564cde  7c80                 jl 0x564c60
// 00564ce0  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00564ce4  01bdc0000000         add dword ptr [ebp + 0xc0], edi
// 00564cea  818db800000000020000 or dword ptr [ebp + 0xb8], 0x200
// 00564cf4  89b5bc000000         mov dword ptr [ebp + 0xbc], esi
// 00564cfa  5e                   pop esi
// 00564cfb  5f                   pop edi
// 00564cfc  5d                   pop ebp
// 00564cfd  5b                   pop ebx
// 00564cfe  59                   pop ecx
// 00564cff  c3                   ret 
// library libpng-1.2.29/pngset.c (function _png_set_unknown_chunks)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngset.c
