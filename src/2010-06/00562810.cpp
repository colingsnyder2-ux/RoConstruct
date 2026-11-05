// from server: 100% by auto
// roc 2010-06 00562810  unit: G3D::_internal::DialogTemplate  size: 489 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00562810
//
// 00562810  55                   push ebp
// 00562811  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00562815  85ed                 test ebp, ebp
// 00562817  0f84da010000         je 0x5629f7
// 0056281d  56                   push esi
// 0056281e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00562822  85f6                 test esi, esi
// 00562824  0f84cc010000         je 0x5629f6
// 0056282a  f7456800040000       test dword ptr [ebp + 0x68], 0x400
// 00562831  0f85bf010000         jne 0x5629f6
// 00562837  57                   push edi
// 00562838  55                   push ebp
// 00562839  e882b90000           call 0x56e1c0
// 0056283e  bf00100000           mov edi, 0x1000
// 00562843  83c404               add esp, 4
// 00562846  857d68               test dword ptr [ebp + 0x68], edi
// 00562849  7421                 je 0x56286c
// 0056284b  83bd3002000000       cmp dword ptr [ebp + 0x230], 0
// 00562852  7418                 je 0x56286c
// 00562854  683c0ea200           push 0xa20e3c
// 00562859  55                   push ebp
// 0056285a  e801f30000           call 0x571b60
// 0056285f  83c408               add esp, 8
// 00562862  c7853002000000000000 mov dword ptr [ebp + 0x230], 0
// 0056286c  0fb6461c             movzx eax, byte ptr [esi + 0x1c]
// 00562870  0fb64e1b             movzx ecx, byte ptr [esi + 0x1b]
// 00562874  0fb6561a             movzx edx, byte ptr [esi + 0x1a]
// 00562878  50                   push eax
// 00562879  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 0056287d  51                   push ecx
// 0056287e  0fb64e18             movzx ecx, byte ptr [esi + 0x18]
// 00562882  52                   push edx
// 00562883  8b5604               mov edx, dword ptr [esi + 4]
// 00562886  50                   push eax
// 00562887  8b06                 mov eax, dword ptr [esi]
// 00562889  51                   push ecx
// 0056288a  52                   push edx
// 0056288b  50                   push eax
// 0056288c  55                   push ebp
// 0056288d  e87ecb0000           call 0x56f410
// 00562892  83c420               add esp, 0x20
// 00562895  f6460801             test byte ptr [esi + 8], 1
// 00562899  7412                 je 0x5628ad
// 0056289b  d94628               fld dword ptr [esi + 0x28]
// 0056289e  83ec08               sub esp, 8
// 005628a1  dd1c24               fstp qword ptr [esp]
// 005628a4  55                   push ebp
// 005628a5  e856d10000           call 0x56fa00
// 005628aa  83c40c               add esp, 0xc
// 005628ad  f7460800080000       test dword ptr [esi + 8], 0x800
// 005628b4  740e                 je 0x5628c4
// 005628b6  0fb64e2c             movzx ecx, byte ptr [esi + 0x2c]
// 005628ba  51                   push ecx
// 005628bb  55                   push ebp
// 005628bc  e81fd20000           call 0x56fae0
// 005628c1  83c408               add esp, 8
// 005628c4  857e08               test dword ptr [esi + 8], edi
// 005628c7  7420                 je 0x5628e9
// 005628c9  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 005628cf  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 005628d5  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 005628db  52                   push edx
// 005628dc  50                   push eax
// 005628dd  6a00                 push 0
// 005628df  51                   push ecx
// 005628e0  55                   push ebp
// 005628e1  e8aad20000           call 0x56fb90
// 005628e6  83c414               add esp, 0x14
// 005628e9  f6460802             test byte ptr [esi + 8], 2
// 005628ed  7412                 je 0x562901
// 005628ef  0fb65619             movzx edx, byte ptr [esi + 0x19]
// 005628f3  52                   push edx
// 005628f4  8d4644               lea eax, [esi + 0x44]
// 005628f7  50                   push eax
// 005628f8  55                   push ebp
// 005628f9  e8e2d50000           call 0x56fee0
// 005628fe  83c40c               add esp, 0xc
// 00562901  f6460804             test byte ptr [esi + 8], 4
// 00562905  745b                 je 0x562962
// 00562907  d9869c000000         fld dword ptr [esi + 0x9c]
// 0056290d  83ec40               sub esp, 0x40
// 00562910  dd5c2438             fstp qword ptr [esp + 0x38]
// 00562914  d98698000000         fld dword ptr [esi + 0x98]
// 0056291a  dd5c2430             fstp qword ptr [esp + 0x30]
// 0056291e  d98694000000         fld dword ptr [esi + 0x94]
// 00562924  dd5c2428             fstp qword ptr [esp + 0x28]
// 00562928  d98690000000         fld dword ptr [esi + 0x90]
// 0056292e  dd5c2420             fstp qword ptr [esp + 0x20]
// 00562932  d9868c000000         fld dword ptr [esi + 0x8c]
// 00562938  dd5c2418             fstp qword ptr [esp + 0x18]
// 0056293c  d98688000000         fld dword ptr [esi + 0x88]
// 00562942  dd5c2410             fstp qword ptr [esp + 0x10]
// 00562946  d98684000000         fld dword ptr [esi + 0x84]
// 0056294c  dd5c2408             fstp qword ptr [esp + 8]
// 00562950  d98680000000         fld dword ptr [esi + 0x80]
// 00562956  dd1c24               fstp qword ptr [esp]
// 00562959  55                   push ebp
// 0056295a  e861d60000           call 0x56ffc0
// 0056295f  83c444               add esp, 0x44
// 00562962  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00562968  85c0                 test eax, eax
// 0056296a  0f847e000000         je 0x5629ee
// 00562970  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 00562976  8d0c80               lea ecx, [eax + eax*4]
// 00562979  8d148f               lea edx, [edi + ecx*4]
// 0056297c  3bfa                 cmp edi, edx
// 0056297e  736e                 jae 0x5629ee
// 00562980  57                   push edi
// 00562981  55                   push ebp
// 00562982  e8c92a0000           call 0x565450
// 00562987  83c408               add esp, 8
// 0056298a  83f801               cmp eax, 1
// 0056298d  7446                 je 0x5629d5
// 0056298f  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00562992  84c9                 test cl, cl
// 00562994  743f                 je 0x5629d5
// 00562996  f6c106               test cl, 6
// 00562999  753a                 jne 0x5629d5
// 0056299b  f6470320             test byte ptr [edi + 3], 0x20
// 0056299f  750e                 jne 0x5629af
// 005629a1  83f803               cmp eax, 3
// 005629a4  7409                 je 0x5629af
// 005629a6  f7456c00000100       test dword ptr [ebp + 0x6c], 0x10000
// 005629ad  7426                 je 0x5629d5
// 005629af  837f0c00             cmp dword ptr [edi + 0xc], 0
// 005629b3  750e                 jne 0x5629c3
// 005629b5  68180ea200           push 0xa20e18
// 005629ba  55                   push ebp
// 005629bb  e8a0f10000           call 0x571b60
// 005629c0  83c408               add esp, 8
// 005629c3  8b470c               mov eax, dword ptr [edi + 0xc]
// 005629c6  8b4f08               mov ecx, dword ptr [edi + 8]
// 005629c9  50                   push eax
// 005629ca  51                   push ecx
// 005629cb  57                   push edi
// 005629cc  55                   push ebp
// 005629cd  e8bec90000           call 0x56f390
// 005629d2  83c410               add esp, 0x10
// 005629d5  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 005629db  8d1480               lea edx, [eax + eax*4]
// 005629de  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 005629e4  83c714               add edi, 0x14
// 005629e7  8d0c90               lea ecx, [eax + edx*4]
// 005629ea  3bf9                 cmp edi, ecx
// 005629ec  7292                 jb 0x562980
// 005629ee  814d6800040000       or dword ptr [ebp + 0x68], 0x400
// 005629f5  5f                   pop edi
// 005629f6  5e                   pop esi
// 005629f7  5d                   pop ebp
// 005629f8  c3                   ret 
// library libpng-1.2.29/pngwrite.c (function _png_write_info_before_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngwrite.c
