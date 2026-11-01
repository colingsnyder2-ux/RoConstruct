// from server: 100% by auto
// roc 2009-12 00602cd0  unit: seg_00600000  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00602cd0
//
// 00602cd0  53                   push ebx
// 00602cd1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00602cd5  85db                 test ebx, ebx
// 00602cd7  0f84e1000000         je 0x602dbe
// 00602cdd  56                   push esi
// 00602cde  8b742410             mov esi, dword ptr [esp + 0x10]
// 00602ce2  85f6                 test esi, esi
// 00602ce4  0f84d3000000         je 0x602dbd
// 00602cea  8b442414             mov eax, dword ptr [esp + 0x14]
// 00602cee  85c0                 test eax, eax
// 00602cf0  0f84c7000000         je 0x602dbd
// 00602cf6  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 00602cfb  0f84bc000000         je 0x602dbd
// 00602d01  8d5001               lea edx, [eax + 1]
// 00602d04  8a08                 mov cl, byte ptr [eax]
// 00602d06  40                   inc eax
// 00602d07  84c9                 test cl, cl
// 00602d09  75f9                 jne 0x602d04
// 00602d0b  55                   push ebp
// 00602d0c  2bc2                 sub eax, edx
// 00602d0e  57                   push edi
// 00602d0f  8d6801               lea ebp, [eax + 1]
// 00602d12  55                   push ebp
// 00602d13  53                   push ebx
// 00602d14  e8f7df0000           call 0x610d10
// 00602d19  8bf8                 mov edi, eax
// 00602d1b  83c408               add esp, 8
// 00602d1e  85ff                 test edi, edi
// 00602d20  7513                 jne 0x602d35
// 00602d22  68c0369c00           push 0x9c36c0
// 00602d27  53                   push ebx
// 00602d28  e813d50000           call 0x610240
// 00602d2d  83c408               add esp, 8
// 00602d30  5f                   pop edi
// 00602d31  5d                   pop ebp
// 00602d32  5e                   pop esi
// 00602d33  5b                   pop ebx
// 00602d34  c3                   ret 
// 00602d35  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00602d39  55                   push ebp
// 00602d3a  50                   push eax
// 00602d3b  57                   push edi
// 00602d3c  e8a51f1f00           call 0x7f4ce6
// 00602d41  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00602d45  55                   push ebp
// 00602d46  53                   push ebx
// 00602d47  e8c4df0000           call 0x610d10
// 00602d4c  8bd8                 mov ebx, eax
// 00602d4e  83c414               add esp, 0x14
// 00602d51  85db                 test ebx, ebx
// 00602d53  751e                 jne 0x602d73
// 00602d55  8b742414             mov esi, dword ptr [esp + 0x14]
// 00602d59  57                   push edi
// 00602d5a  56                   push esi
// 00602d5b  e880df0000           call 0x610ce0
// 00602d60  6890369c00           push 0x9c3690
// 00602d65  56                   push esi
// 00602d66  e8d5d40000           call 0x610240
// 00602d6b  83c410               add esp, 0x10
// 00602d6e  5f                   pop edi
// 00602d6f  5d                   pop ebp
// 00602d70  5e                   pop esi
// 00602d71  5b                   pop ebx
// 00602d72  c3                   ret 
// 00602d73  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00602d77  55                   push ebp
// 00602d78  51                   push ecx
// 00602d79  53                   push ebx
// 00602d7a  e8671f1f00           call 0x7f4ce6
// 00602d7f  8b542420             mov edx, dword ptr [esp + 0x20]
// 00602d83  6a00                 push 0
// 00602d85  6a10                 push 0x10
// 00602d87  56                   push esi
// 00602d88  52                   push edx
// 00602d89  e832090000           call 0x6036c0
// 00602d8e  8a44243c             mov al, byte ptr [esp + 0x3c]
// 00602d92  838eb800000010       or dword ptr [esi + 0xb8], 0x10
// 00602d99  83c41c               add esp, 0x1c
// 00602d9c  814e0800100000       or dword ptr [esi + 8], 0x1000
// 00602da3  89bec4000000         mov dword ptr [esi + 0xc4], edi
// 00602da9  5f                   pop edi
// 00602daa  89aecc000000         mov dword ptr [esi + 0xcc], ebp
// 00602db0  899ec8000000         mov dword ptr [esi + 0xc8], ebx
// 00602db6  8886d0000000         mov byte ptr [esi + 0xd0], al
// 00602dbc  5d                   pop ebp
// 00602dbd  5e                   pop esi
// 00602dbe  5b                   pop ebx
// 00602dbf  c3                   ret 
// library libpng-1.2.24/pngset.c (function _png_set_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngset.c
