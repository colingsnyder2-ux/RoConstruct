// from server: 100% by auto
// roc 2009-06 00588bd0  unit: seg_00580000  size: 296 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00588bd0
//
// 00588bd0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00588bd4  53                   push ebx
// 00588bd5  55                   push ebp
// 00588bd6  56                   push esi
// 00588bd7  57                   push edi
// 00588bd8  85c9                 test ecx, ecx
// 00588bda  0f8411010000         je 0x588cf1
// 00588be0  8b742418             mov esi, dword ptr [esp + 0x18]
// 00588be4  85f6                 test esi, esi
// 00588be6  0f8405010000         je 0x588cf1
// 00588bec  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00588bf0  85db                 test ebx, ebx
// 00588bf2  0f84f9000000         je 0x588cf1
// 00588bf8  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00588bfc  85ed                 test ebp, ebp
// 00588bfe  0f84ed000000         je 0x588cf1
// 00588c04  8b442424             mov eax, dword ptr [esp + 0x24]
// 00588c08  85c0                 test eax, eax
// 00588c0a  0f84e1000000         je 0x588cf1
// 00588c10  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00588c14  85ff                 test edi, edi
// 00588c16  0f84d5000000         je 0x588cf1
// 00588c1c  8b16                 mov edx, dword ptr [esi]
// 00588c1e  8913                 mov dword ptr [ebx], edx
// 00588c20  8b5604               mov edx, dword ptr [esi + 4]
// 00588c23  895500               mov dword ptr [ebp], edx
// 00588c26  0fb65618             movzx edx, byte ptr [esi + 0x18]
// 00588c2a  8910                 mov dword ptr [eax], edx
// 00588c2c  807e1801             cmp byte ptr [esi + 0x18], 1
// 00588c30  7206                 jb 0x588c38
// 00588c32  807e1810             cmp byte ptr [esi + 0x18], 0x10
// 00588c36  7612                 jbe 0x588c4a
// 00588c38  687ce48c00           push 0x8ce47c
// 00588c3d  51                   push ecx
// 00588c3e  e81d550000           call 0x58e160
// 00588c43  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00588c47  83c408               add esp, 8
// 00588c4a  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 00588c4e  8907                 mov dword ptr [edi], eax
// 00588c50  807e1906             cmp byte ptr [esi + 0x19], 6
// 00588c54  7612                 jbe 0x588c68
// 00588c56  6868e48c00           push 0x8ce468
// 00588c5b  51                   push ecx
// 00588c5c  e8ff540000           call 0x58e160
// 00588c61  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00588c65  83c408               add esp, 8
// 00588c68  8b442430             mov eax, dword ptr [esp + 0x30]
// 00588c6c  85c0                 test eax, eax
// 00588c6e  7406                 je 0x588c76
// 00588c70  0fb6561a             movzx edx, byte ptr [esi + 0x1a]
// 00588c74  8910                 mov dword ptr [eax], edx
// 00588c76  8b442434             mov eax, dword ptr [esp + 0x34]
// 00588c7a  85c0                 test eax, eax
// 00588c7c  7406                 je 0x588c84
// 00588c7e  0fb6561b             movzx edx, byte ptr [esi + 0x1b]
// 00588c82  8910                 mov dword ptr [eax], edx
// 00588c84  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00588c88  85c0                 test eax, eax
// 00588c8a  7406                 je 0x588c92
// 00588c8c  0fb6561c             movzx edx, byte ptr [esi + 0x1c]
// 00588c90  8910                 mov dword ptr [eax], edx
// 00588c92  8b03                 mov eax, dword ptr [ebx]
// 00588c94  85c0                 test eax, eax
// 00588c96  7407                 je 0x588c9f
// 00588c98  3dffffff7f           cmp eax, 0x7fffffff
// 00588c9d  7612                 jbe 0x588cb1
// 00588c9f  6854e48c00           push 0x8ce454
// 00588ca4  51                   push ecx
// 00588ca5  e8b6540000           call 0x58e160
// 00588caa  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00588cae  83c408               add esp, 8
// 00588cb1  8b4500               mov eax, dword ptr [ebp]
// 00588cb4  85c0                 test eax, eax
// 00588cb6  7407                 je 0x588cbf
// 00588cb8  3dffffff7f           cmp eax, 0x7fffffff
// 00588cbd  7612                 jbe 0x588cd1
// 00588cbf  683ce48c00           push 0x8ce43c
// 00588cc4  51                   push ecx
// 00588cc5  e896540000           call 0x58e160
// 00588cca  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00588cce  83c408               add esp, 8
// 00588cd1  813e7effff1f         cmp dword ptr [esi], 0x1fffff7e
// 00588cd7  760e                 jbe 0x588ce7
// 00588cd9  6808e48c00           push 0x8ce408
// 00588cde  51                   push ecx
// 00588cdf  e82c550000           call 0x58e210
// 00588ce4  83c408               add esp, 8
// 00588ce7  5f                   pop edi
// 00588ce8  5e                   pop esi
// 00588ce9  5d                   pop ebp
// 00588cea  b801000000           mov eax, 1
// 00588cef  5b                   pop ebx
// 00588cf0  c3                   ret 
// 00588cf1  5f                   pop edi
// 00588cf2  5e                   pop esi
// 00588cf3  5d                   pop ebp
// 00588cf4  33c0                 xor eax, eax
// 00588cf6  5b                   pop ebx
// 00588cf7  c3                   ret 
// library libpng-1.2.8/pngget.c (function _png_get_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.8 pngget.c
