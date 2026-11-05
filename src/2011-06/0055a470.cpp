// from server: 100% by auto
// roc 2011-06 0055a470  unit: seg_00550000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055a470
//
// 0055a470  55                   push ebp
// 0055a471  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0055a475  85ed                 test ebp, ebp
// 0055a477  0f84da000000         je 0x55a557
// 0055a47d  56                   push esi
// 0055a47e  8b742410             mov esi, dword ptr [esp + 0x10]
// 0055a482  85f6                 test esi, esi
// 0055a484  0f84cc000000         je 0x55a556
// 0055a48a  53                   push ebx
// 0055a48b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0055a48f  57                   push edi
// 0055a490  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0055a494  85ff                 test edi, edi
// 0055a496  743d                 je 0x55a4d5
// 0055a498  6a00                 push 0
// 0055a49a  6800200000           push 0x2000
// 0055a49f  56                   push esi
// 0055a4a0  55                   push ebp
// 0055a4a1  e8fa63ffff           call 0x5508a0
// 0055a4a6  6800010000           push 0x100
// 0055a4ab  55                   push ebp
// 0055a4ac  e88f710000           call 0x561640
// 0055a4b1  89464c               mov dword ptr [esi + 0x4c], eax
// 0055a4b4  898588010000         mov dword ptr [ebp + 0x188], eax
// 0055a4ba  8d43ff               lea eax, [ebx - 1]
// 0055a4bd  83c418               add esp, 0x18
// 0055a4c0  3dff000000           cmp eax, 0xff
// 0055a4c5  770e                 ja 0x55a4d5
// 0055a4c7  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 0055a4ca  53                   push ebx
// 0055a4cb  57                   push edi
// 0055a4cc  51                   push ecx
// 0055a4cd  e80a112b00           call 0x80b5dc
// 0055a4d2  83c40c               add esp, 0xc
// 0055a4d5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0055a4d9  85ff                 test edi, edi
// 0055a4db  7461                 je 0x55a53e
// 0055a4dd  0fb64e18             movzx ecx, byte ptr [esi + 0x18]
// 0055a4e1  b801000000           mov eax, 1
// 0055a4e6  d3e0                 shl eax, cl
// 0055a4e8  8a4e19               mov cl, byte ptr [esi + 0x19]
// 0055a4eb  84c9                 test cl, cl
// 0055a4ed  7508                 jne 0x55a4f7
// 0055a4ef  0fb75708             movzx edx, word ptr [edi + 8]
// 0055a4f3  3bd0                 cmp edx, eax
// 0055a4f5  7f1d                 jg 0x55a514
// 0055a4f7  80f902               cmp cl, 2
// 0055a4fa  7526                 jne 0x55a522
// 0055a4fc  0fb74f02             movzx ecx, word ptr [edi + 2]
// 0055a500  3bc8                 cmp ecx, eax
// 0055a502  7f10                 jg 0x55a514
// 0055a504  0fb75704             movzx edx, word ptr [edi + 4]
// 0055a508  3bd0                 cmp edx, eax
// 0055a50a  7f08                 jg 0x55a514
// 0055a50c  0fb74f06             movzx ecx, word ptr [edi + 6]
// 0055a510  3bc8                 cmp ecx, eax
// 0055a512  7e0e                 jle 0x55a522
// 0055a514  68e024a800           push 0xa824e0
// 0055a519  55                   push ebp
// 0055a51a  e8c16e0000           call 0x5613e0
// 0055a51f  83c408               add esp, 8
// 0055a522  8b17                 mov edx, dword ptr [edi]
// 0055a524  895650               mov dword ptr [esi + 0x50], edx
// 0055a527  8b4704               mov eax, dword ptr [edi + 4]
// 0055a52a  894654               mov dword ptr [esi + 0x54], eax
// 0055a52d  668b4f08             mov cx, word ptr [edi + 8]
// 0055a531  66894e58             mov word ptr [esi + 0x58], cx
// 0055a535  85db                 test ebx, ebx
// 0055a537  7505                 jne 0x55a53e
// 0055a539  bb01000000           mov ebx, 1
// 0055a53e  5f                   pop edi
// 0055a53f  66895e16             mov word ptr [esi + 0x16], bx
// 0055a543  85db                 test ebx, ebx
// 0055a545  5b                   pop ebx
// 0055a546  740e                 je 0x55a556
// 0055a548  834e0810             or dword ptr [esi + 8], 0x10
// 0055a54c  818eb800000000200000 or dword ptr [esi + 0xb8], 0x2000
// 0055a556  5e                   pop esi
// 0055a557  5d                   pop ebp
// 0055a558  c3                   ret 
// library libpng-1.2.32/pngset.c (function _png_set_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngset.c
