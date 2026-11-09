// from server: 100% by auto
// roc 2010-06 00563f40  unit: G3D::_internal::DialogTemplate  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00563f40
//
// 00563f40  57                   push edi
// 00563f41  8b7c2408             mov edi, dword ptr [esp + 8]
// 00563f45  85ff                 test edi, edi
// 00563f47  0f84b1000000         je 0x563ffe
// 00563f4d  56                   push esi
// 00563f4e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00563f52  85f6                 test esi, esi
// 00563f54  0f84a3000000         je 0x563ffd
// 00563f5a  0fb74614             movzx eax, word ptr [esi + 0x14]
// 00563f5e  6685c0               test ax, ax
// 00563f61  0f8488000000         je 0x563fef
// 00563f67  b900010000           mov ecx, 0x100
// 00563f6c  663bc1               cmp ax, cx
// 00563f6f  777e                 ja 0x563fef
// 00563f71  6a00                 push 0
// 00563f73  6a08                 push 8
// 00563f75  56                   push esi
// 00563f76  57                   push edi
// 00563f77  e8b4100000           call 0x565030
// 00563f7c  6800020000           push 0x200
// 00563f81  57                   push edi
// 00563f82  e8a9e60000           call 0x572630
// 00563f87  83c418               add esp, 0x18
// 00563f8a  8987f4010000         mov dword ptr [edi + 0x1f4], eax
// 00563f90  85c0                 test eax, eax
// 00563f92  7511                 jne 0x563fa5
// 00563f94  683411a200           push 0xa21134
// 00563f99  57                   push edi
// 00563f9a  e8c1db0000           call 0x571b60
// 00563f9f  83c408               add esp, 8
// 00563fa2  5e                   pop esi
// 00563fa3  5f                   pop edi
// 00563fa4  c3                   ret 
// 00563fa5  33d2                 xor edx, edx
// 00563fa7  33c0                 xor eax, eax
// 00563fa9  663b5614             cmp dx, word ptr [esi + 0x14]
// 00563fad  7329                 jae 0x563fd8
// 00563faf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00563fb3  53                   push ebx
// 00563fb4  eb0a                 jmp 0x563fc0
// 00563fb6  8da42400000000       lea esp, [esp]
// 00563fbd  8d4900               lea ecx, [ecx]
// 00563fc0  8b97f4010000         mov edx, dword ptr [edi + 0x1f4]
// 00563fc6  668b1c41             mov bx, word ptr [ecx + eax*2]
// 00563fca  66891c42             mov word ptr [edx + eax*2], bx
// 00563fce  0fb75614             movzx edx, word ptr [esi + 0x14]
// 00563fd2  40                   inc eax
// 00563fd3  3bc2                 cmp eax, edx
// 00563fd5  7ce9                 jl 0x563fc0
// 00563fd7  5b                   pop ebx
// 00563fd8  8b87f4010000         mov eax, dword ptr [edi + 0x1f4]
// 00563fde  834e0840             or dword ptr [esi + 8], 0x40
// 00563fe2  838eb800000008       or dword ptr [esi + 0xb8], 8
// 00563fe9  89467c               mov dword ptr [esi + 0x7c], eax
// 00563fec  5e                   pop esi
// 00563fed  5f                   pop edi
// 00563fee  c3                   ret 
// 00563fef  680411a200           push 0xa21104
// 00563ff4  57                   push edi
// 00563ff5  e866db0000           call 0x571b60
// 00563ffa  83c408               add esp, 8
// 00563ffd  5e                   pop esi
// 00563ffe  5f                   pop edi
// 00563fff  c3                   ret 
// library libpng-1.2.22/pngset.c (function _png_set_hIST)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngset.c
