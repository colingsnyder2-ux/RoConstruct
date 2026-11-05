// from server: 100% by auto
// roc 2010-06 00564000  unit: G3D::_internal::DialogTemplate  size: 549 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00564000
//
// 00564000  57                   push edi
// 00564001  8b7c2408             mov edi, dword ptr [esp + 8]
// 00564005  85ff                 test edi, edi
// 00564007  0f8416020000         je 0x564223
// 0056400d  56                   push esi
// 0056400e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00564012  85f6                 test esi, esi
// 00564014  0f8408020000         je 0x564222
// 0056401a  53                   push ebx
// 0056401b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0056401f  55                   push ebp
// 00564020  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00564024  85ed                 test ebp, ebp
// 00564026  7404                 je 0x56402c
// 00564028  85db                 test ebx, ebx
// 0056402a  750e                 jne 0x56403a
// 0056402c  68c812a200           push 0xa212c8
// 00564031  57                   push edi
// 00564032  e879da0000           call 0x571ab0
// 00564037  83c408               add esp, 8
// 0056403a  3baf64020000         cmp ebp, dword ptr [edi + 0x264]
// 00564040  7708                 ja 0x56404a
// 00564042  3b9f68020000         cmp ebx, dword ptr [edi + 0x268]
// 00564048  760e                 jbe 0x564058
// 0056404a  68a012a200           push 0xa212a0
// 0056404f  57                   push edi
// 00564050  e85bda0000           call 0x571ab0
// 00564055  83c408               add esp, 8
// 00564058  81fdffffff7f         cmp ebp, 0x7fffffff
// 0056405e  7708                 ja 0x564068
// 00564060  81fbffffff7f         cmp ebx, 0x7fffffff
// 00564066  760e                 jbe 0x564076
// 00564068  688412a200           push 0xa21284
// 0056406d  57                   push edi
// 0056406e  e83dda0000           call 0x571ab0
// 00564073  83c408               add esp, 8
// 00564076  81fd7effff1f         cmp ebp, 0x1fffff7e
// 0056407c  760e                 jbe 0x56408c
// 0056407e  685412a200           push 0xa21254
// 00564083  57                   push edi
// 00564084  e8d7da0000           call 0x571b60
// 00564089  83c408               add esp, 8
// 0056408c  8b442424             mov eax, dword ptr [esp + 0x24]
// 00564090  83f801               cmp eax, 1
// 00564093  7422                 je 0x5640b7
// 00564095  83f802               cmp eax, 2
// 00564098  741d                 je 0x5640b7
// 0056409a  83f804               cmp eax, 4
// 0056409d  7418                 je 0x5640b7
// 0056409f  83f808               cmp eax, 8
// 005640a2  7413                 je 0x5640b7
// 005640a4  83f810               cmp eax, 0x10
// 005640a7  740e                 je 0x5640b7
// 005640a9  683812a200           push 0xa21238
// 005640ae  57                   push edi
// 005640af  e8fcd90000           call 0x571ab0
// 005640b4  83c408               add esp, 8
// 005640b7  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 005640bb  85db                 test ebx, ebx
// 005640bd  7c0f                 jl 0x5640ce
// 005640bf  83fb01               cmp ebx, 1
// 005640c2  740a                 je 0x5640ce
// 005640c4  83fb05               cmp ebx, 5
// 005640c7  7405                 je 0x5640ce
// 005640c9  83fb06               cmp ebx, 6
// 005640cc  7e0e                 jle 0x5640dc
// 005640ce  681c12a200           push 0xa2121c
// 005640d3  57                   push edi
// 005640d4  e8d7d90000           call 0x571ab0
// 005640d9  83c408               add esp, 8
// 005640dc  83fb03               cmp ebx, 3
// 005640df  7509                 jne 0x5640ea
// 005640e1  837c242408           cmp dword ptr [esp + 0x24], 8
// 005640e6  7f18                 jg 0x564100
// 005640e8  eb24                 jmp 0x56410e
// 005640ea  83fb02               cmp ebx, 2
// 005640ed  740a                 je 0x5640f9
// 005640ef  83fb04               cmp ebx, 4
// 005640f2  7405                 je 0x5640f9
// 005640f4  83fb06               cmp ebx, 6
// 005640f7  7515                 jne 0x56410e
// 005640f9  837c242408           cmp dword ptr [esp + 0x24], 8
// 005640fe  7d0e                 jge 0x56410e
// 00564100  68e811a200           push 0xa211e8
// 00564105  57                   push edi
// 00564106  e8a5d90000           call 0x571ab0
// 0056410b  83c408               add esp, 8
// 0056410e  837c242c02           cmp dword ptr [esp + 0x2c], 2
// 00564113  7c0e                 jl 0x564123
// 00564115  68c411a200           push 0xa211c4
// 0056411a  57                   push edi
// 0056411b  e890d90000           call 0x571ab0
// 00564120  83c408               add esp, 8
// 00564123  837c243000           cmp dword ptr [esp + 0x30], 0
// 00564128  740e                 je 0x564138
// 0056412a  68a011a200           push 0xa211a0
// 0056412f  57                   push edi
// 00564130  e87bd90000           call 0x571ab0
// 00564135  83c408               add esp, 8
// 00564138  bd00100000           mov ebp, 0x1000
// 0056413d  856f68               test dword ptr [edi + 0x68], ebp
// 00564140  7417                 je 0x564159
// 00564142  83bf3002000000       cmp dword ptr [edi + 0x230], 0
// 00564149  740e                 je 0x564159
// 0056414b  683c0ea200           push 0xa20e3c
// 00564150  57                   push edi
// 00564151  e80ada0000           call 0x571b60
// 00564156  83c408               add esp, 8
// 00564159  8b442434             mov eax, dword ptr [esp + 0x34]
// 0056415d  85c0                 test eax, eax
// 0056415f  743e                 je 0x56419f
// 00564161  f6873002000004       test byte ptr [edi + 0x230], 4
// 00564168  7414                 je 0x56417e
// 0056416a  83f840               cmp eax, 0x40
// 0056416d  750f                 jne 0x56417e
// 0056416f  856f68               test dword ptr [edi + 0x68], ebp
// 00564172  750a                 jne 0x56417e
// 00564174  83fb02               cmp ebx, 2
// 00564177  7413                 je 0x56418c
// 00564179  83fb06               cmp ebx, 6
// 0056417c  740e                 je 0x56418c
// 0056417e  688011a200           push 0xa21180
// 00564183  57                   push edi
// 00564184  e827d90000           call 0x571ab0
// 00564189  83c408               add esp, 8
// 0056418c  856f68               test dword ptr [edi + 0x68], ebp
// 0056418f  740e                 je 0x56419f
// 00564191  686011a200           push 0xa21160
// 00564196  57                   push edi
// 00564197  e8c4d90000           call 0x571b60
// 0056419c  83c408               add esp, 8
// 0056419f  8b442420             mov eax, dword ptr [esp + 0x20]
// 005641a3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005641a7  8a542424             mov dl, byte ptr [esp + 0x24]
// 005641ab  894604               mov dword ptr [esi + 4], eax
// 005641ae  8a442430             mov al, byte ptr [esp + 0x30]
// 005641b2  88461a               mov byte ptr [esi + 0x1a], al
// 005641b5  8a442434             mov al, byte ptr [esp + 0x34]
// 005641b9  88461b               mov byte ptr [esi + 0x1b], al
// 005641bc  8a44242c             mov al, byte ptr [esp + 0x2c]
// 005641c0  890e                 mov dword ptr [esi], ecx
// 005641c2  885618               mov byte ptr [esi + 0x18], dl
// 005641c5  885e19               mov byte ptr [esi + 0x19], bl
// 005641c8  88461c               mov byte ptr [esi + 0x1c], al
// 005641cb  80fb03               cmp bl, 3
// 005641ce  740b                 je 0x5641db
// 005641d0  f6c302               test bl, 2
// 005641d3  7406                 je 0x5641db
// 005641d5  c6461d03             mov byte ptr [esi + 0x1d], 3
// 005641d9  eb04                 jmp 0x5641df
// 005641db  c6461d01             mov byte ptr [esi + 0x1d], 1
// 005641df  5d                   pop ebp
// 005641e0  f6c304               test bl, 4
// 005641e3  5b                   pop ebx
// 005641e4  7403                 je 0x5641e9
// 005641e6  fe461d               inc byte ptr [esi + 0x1d]
// 005641e9  8a461d               mov al, byte ptr [esi + 0x1d]
// 005641ec  f6ea                 imul dl
// 005641ee  88461e               mov byte ptr [esi + 0x1e], al
// 005641f1  81f97effff1f         cmp ecx, 0x1fffff7e
// 005641f7  760a                 jbe 0x564203
// 005641f9  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00564200  5e                   pop esi
// 00564201  5f                   pop edi
// 00564202  c3                   ret 
// 00564203  3c08                 cmp al, 8
// 00564205  0fb6c0               movzx eax, al
// 00564208  720c                 jb 0x564216
// 0056420a  c1e803               shr eax, 3
// 0056420d  0fafc1               imul eax, ecx
// 00564210  89460c               mov dword ptr [esi + 0xc], eax
// 00564213  5e                   pop esi
// 00564214  5f                   pop edi
// 00564215  c3                   ret 
// 00564216  0fafc1               imul eax, ecx
// 00564219  83c007               add eax, 7
// 0056421c  c1e803               shr eax, 3
// 0056421f  89460c               mov dword ptr [esi + 0xc], eax
// 00564222  5e                   pop esi
// 00564223  5f                   pop edi
// 00564224  c3                   ret 
// library libpng-1.2.10/pngset.c (function _png_set_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngset.c
