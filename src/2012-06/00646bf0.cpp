// from server: 100% by auto
// roc 2012-06 00646bf0  unit: seg_00640000  size: 401 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00646bf0
//
// 00646bf0  53                   push ebx
// 00646bf1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00646bf5  85db                 test ebx, ebx
// 00646bf7  0f846f010000         je 0x646d6c
// 00646bfd  57                   push edi
// 00646bfe  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00646c02  85ff                 test edi, edi
// 00646c04  0f8461010000         je 0x646d6b
// 00646c0a  55                   push ebp
// 00646c0b  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00646c0f  8bc5                 mov eax, ebp
// 00646c11  8d5001               lea edx, [eax + 1]
// 00646c14  8a08                 mov cl, byte ptr [eax]
// 00646c16  40                   inc eax
// 00646c17  84c9                 test cl, cl
// 00646c19  75f9                 jne 0x646c14
// 00646c1b  56                   push esi
// 00646c1c  2bc2                 sub eax, edx
// 00646c1e  8d7001               lea esi, [eax + 1]
// 00646c21  56                   push esi
// 00646c22  53                   push ebx
// 00646c23  e828790000           call 0x64e550
// 00646c28  83c408               add esp, 8
// 00646c2b  8987a0000000         mov dword ptr [edi + 0xa0], eax
// 00646c31  85c0                 test eax, eax
// 00646c33  7513                 jne 0x646c48
// 00646c35  689062b800           push 0xb86290
// 00646c3a  53                   push ebx
// 00646c3b  e820760000           call 0x64e260
// 00646c40  83c408               add esp, 8
// 00646c43  5e                   pop esi
// 00646c44  5d                   pop ebp
// 00646c45  5f                   pop edi
// 00646c46  5b                   pop ebx
// 00646c47  c3                   ret 
// 00646c48  56                   push esi
// 00646c49  55                   push ebp
// 00646c4a  50                   push eax
// 00646c4b  e80cca3300           call 0x98365c
// 00646c50  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00646c54  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 00646c58  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00646c5c  8a542434             mov dl, byte ptr [esp + 0x34]
// 00646c60  8987a4000000         mov dword ptr [edi + 0xa4], eax
// 00646c66  8a442438             mov al, byte ptr [esp + 0x38]
// 00646c6a  8887b5000000         mov byte ptr [edi + 0xb5], al
// 00646c70  8bc5                 mov eax, ebp
// 00646c72  83c40c               add esp, 0xc
// 00646c75  898fa8000000         mov dword ptr [edi + 0xa8], ecx
// 00646c7b  8897b4000000         mov byte ptr [edi + 0xb4], dl
// 00646c81  8d7001               lea esi, [eax + 1]
// 00646c84  8a08                 mov cl, byte ptr [eax]
// 00646c86  40                   inc eax
// 00646c87  84c9                 test cl, cl
// 00646c89  75f9                 jne 0x646c84
// 00646c8b  2bc6                 sub eax, esi
// 00646c8d  8d7001               lea esi, [eax + 1]
// 00646c90  56                   push esi
// 00646c91  53                   push ebx
// 00646c92  e8b9780000           call 0x64e550
// 00646c97  83c408               add esp, 8
// 00646c9a  8987ac000000         mov dword ptr [edi + 0xac], eax
// 00646ca0  85c0                 test eax, eax
// 00646ca2  7513                 jne 0x646cb7
// 00646ca4  686c62b800           push 0xb8626c
// 00646ca9  53                   push ebx
// 00646caa  e8b1750000           call 0x64e260
// 00646caf  83c408               add esp, 8
// 00646cb2  5e                   pop esi
// 00646cb3  5d                   pop ebp
// 00646cb4  5f                   pop edi
// 00646cb5  5b                   pop ebx
// 00646cb6  c3                   ret 
// 00646cb7  56                   push esi
// 00646cb8  55                   push ebp
// 00646cb9  50                   push eax
// 00646cba  e89dc93300           call 0x98365c
// 00646cbf  8b742438             mov esi, dword ptr [esp + 0x38]
// 00646cc3  8d34b504000000       lea esi, [esi*4 + 4]
// 00646cca  56                   push esi
// 00646ccb  53                   push ebx
// 00646ccc  e87f780000           call 0x64e550
// 00646cd1  83c414               add esp, 0x14
// 00646cd4  8987b0000000         mov dword ptr [edi + 0xb0], eax
// 00646cda  85c0                 test eax, eax
// 00646cdc  7513                 jne 0x646cf1
// 00646cde  684462b800           push 0xb86244
// 00646ce3  53                   push ebx
// 00646ce4  e877750000           call 0x64e260
// 00646ce9  83c408               add esp, 8
// 00646cec  5e                   pop esi
// 00646ced  5d                   pop ebp
// 00646cee  5f                   pop edi
// 00646cef  5b                   pop ebx
// 00646cf0  c3                   ret 
// 00646cf1  56                   push esi
// 00646cf2  6a00                 push 0
// 00646cf4  50                   push eax
// 00646cf5  e87ac63300           call 0x983374
// 00646cfa  33f6                 xor esi, esi
// 00646cfc  83c40c               add esp, 0xc
// 00646cff  3974242c             cmp dword ptr [esp + 0x2c], esi
// 00646d03  7e53                 jle 0x646d58
// 00646d05  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00646d09  8b04b1               mov eax, dword ptr [ecx + esi*4]
// 00646d0c  8d5001               lea edx, [eax + 1]
// 00646d0f  90                   nop 
// 00646d10  8a08                 mov cl, byte ptr [eax]
// 00646d12  40                   inc eax
// 00646d13  84c9                 test cl, cl
// 00646d15  75f9                 jne 0x646d10
// 00646d17  2bc2                 sub eax, edx
// 00646d19  8d6801               lea ebp, [eax + 1]
// 00646d1c  55                   push ebp
// 00646d1d  53                   push ebx
// 00646d1e  e82d780000           call 0x64e550
// 00646d23  8b97b0000000         mov edx, dword ptr [edi + 0xb0]
// 00646d29  8904b2               mov dword ptr [edx + esi*4], eax
// 00646d2c  8b87b0000000         mov eax, dword ptr [edi + 0xb0]
// 00646d32  8d04b0               lea eax, [eax + esi*4]
// 00646d35  83c408               add esp, 8
// 00646d38  833800               cmp dword ptr [eax], 0
// 00646d3b  7431                 je 0x646d6e
// 00646d3d  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00646d41  8b14b1               mov edx, dword ptr [ecx + esi*4]
// 00646d44  8b00                 mov eax, dword ptr [eax]
// 00646d46  55                   push ebp
// 00646d47  52                   push edx
// 00646d48  50                   push eax
// 00646d49  e80ec93300           call 0x98365c
// 00646d4e  46                   inc esi
// 00646d4f  83c40c               add esp, 0xc
// 00646d52  3b74242c             cmp esi, dword ptr [esp + 0x2c]
// 00646d56  7cad                 jl 0x646d05
// 00646d58  814f0800040000       or dword ptr [edi + 8], 0x400
// 00646d5f  818fb800000080000000 or dword ptr [edi + 0xb8], 0x80
// 00646d69  5e                   pop esi
// 00646d6a  5d                   pop ebp
// 00646d6b  5f                   pop edi
// 00646d6c  5b                   pop ebx
// 00646d6d  c3                   ret 
// 00646d6e  681c62b800           push 0xb8621c
// 00646d73  53                   push ebx
// 00646d74  e8e7740000           call 0x64e260
// 00646d79  83c408               add esp, 8
// 00646d7c  5e                   pop esi
// 00646d7d  5d                   pop ebp
// 00646d7e  5f                   pop edi
// 00646d7f  5b                   pop ebx
// 00646d80  c3                   ret 
// library libpng-1.2.37/pngset.c (function _png_set_pCAL)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.37 pngset.c
