// from server: 100% by auto
// roc 2011-06 0055a180  unit: seg_00550000  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055a180
//
// 0055a180  53                   push ebx
// 0055a181  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0055a185  85db                 test ebx, ebx
// 0055a187  0f84e1000000         je 0x55a26e
// 0055a18d  56                   push esi
// 0055a18e  8b742410             mov esi, dword ptr [esp + 0x10]
// 0055a192  85f6                 test esi, esi
// 0055a194  0f84d3000000         je 0x55a26d
// 0055a19a  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055a19e  85c0                 test eax, eax
// 0055a1a0  0f84c7000000         je 0x55a26d
// 0055a1a6  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 0055a1ab  0f84bc000000         je 0x55a26d
// 0055a1b1  8d5001               lea edx, [eax + 1]
// 0055a1b4  8a08                 mov cl, byte ptr [eax]
// 0055a1b6  40                   inc eax
// 0055a1b7  84c9                 test cl, cl
// 0055a1b9  75f9                 jne 0x55a1b4
// 0055a1bb  55                   push ebp
// 0055a1bc  2bc2                 sub eax, edx
// 0055a1be  57                   push edi
// 0055a1bf  8d6801               lea ebp, [eax + 1]
// 0055a1c2  55                   push ebp
// 0055a1c3  53                   push ebx
// 0055a1c4  e807750000           call 0x5616d0
// 0055a1c9  8bf8                 mov edi, eax
// 0055a1cb  83c408               add esp, 8
// 0055a1ce  85ff                 test edi, edi
// 0055a1d0  7513                 jne 0x55a1e5
// 0055a1d2  689824a800           push 0xa82498
// 0055a1d7  53                   push ebx
// 0055a1d8  e803720000           call 0x5613e0
// 0055a1dd  83c408               add esp, 8
// 0055a1e0  5f                   pop edi
// 0055a1e1  5d                   pop ebp
// 0055a1e2  5e                   pop esi
// 0055a1e3  5b                   pop ebx
// 0055a1e4  c3                   ret 
// 0055a1e5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0055a1e9  55                   push ebp
// 0055a1ea  50                   push eax
// 0055a1eb  57                   push edi
// 0055a1ec  e8eb132b00           call 0x80b5dc
// 0055a1f1  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0055a1f5  55                   push ebp
// 0055a1f6  53                   push ebx
// 0055a1f7  e8d4740000           call 0x5616d0
// 0055a1fc  8bd8                 mov ebx, eax
// 0055a1fe  83c414               add esp, 0x14
// 0055a201  85db                 test ebx, ebx
// 0055a203  751e                 jne 0x55a223
// 0055a205  8b742414             mov esi, dword ptr [esp + 0x14]
// 0055a209  57                   push edi
// 0055a20a  56                   push esi
// 0055a20b  e890740000           call 0x5616a0
// 0055a210  686824a800           push 0xa82468
// 0055a215  56                   push esi
// 0055a216  e8c5710000           call 0x5613e0
// 0055a21b  83c410               add esp, 0x10
// 0055a21e  5f                   pop edi
// 0055a21f  5d                   pop ebp
// 0055a220  5e                   pop esi
// 0055a221  5b                   pop ebx
// 0055a222  c3                   ret 
// 0055a223  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0055a227  55                   push ebp
// 0055a228  51                   push ecx
// 0055a229  53                   push ebx
// 0055a22a  e8ad132b00           call 0x80b5dc
// 0055a22f  8b542420             mov edx, dword ptr [esp + 0x20]
// 0055a233  6a00                 push 0
// 0055a235  6a10                 push 0x10
// 0055a237  56                   push esi
// 0055a238  52                   push edx
// 0055a239  e86266ffff           call 0x5508a0
// 0055a23e  8a44243c             mov al, byte ptr [esp + 0x3c]
// 0055a242  838eb800000010       or dword ptr [esi + 0xb8], 0x10
// 0055a249  83c41c               add esp, 0x1c
// 0055a24c  814e0800100000       or dword ptr [esi + 8], 0x1000
// 0055a253  89bec4000000         mov dword ptr [esi + 0xc4], edi
// 0055a259  5f                   pop edi
// 0055a25a  89aecc000000         mov dword ptr [esi + 0xcc], ebp
// 0055a260  899ec8000000         mov dword ptr [esi + 0xc8], ebx
// 0055a266  8886d0000000         mov byte ptr [esi + 0xd0], al
// 0055a26c  5d                   pop ebp
// 0055a26d  5e                   pop esi
// 0055a26e  5b                   pop ebx
// 0055a26f  c3                   ret 
// library libpng-1.2.24/pngset.c (function _png_set_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngset.c
