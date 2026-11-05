// from server: 100% by auto
// roc 2009-12 00602690  unit: G3D::_internal::DialogTemplate  size: 549 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00602690
//
// 00602690  57                   push edi
// 00602691  8b7c2408             mov edi, dword ptr [esp + 8]
// 00602695  85ff                 test edi, edi
// 00602697  0f8416020000         je 0x6028b3
// 0060269d  56                   push esi
// 0060269e  8b742410             mov esi, dword ptr [esp + 0x10]
// 006026a2  85f6                 test esi, esi
// 006026a4  0f8408020000         je 0x6028b2
// 006026aa  53                   push ebx
// 006026ab  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 006026af  55                   push ebp
// 006026b0  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 006026b4  85ed                 test ebp, ebp
// 006026b6  7404                 je 0x6026bc
// 006026b8  85db                 test ebx, ebx
// 006026ba  750e                 jne 0x6026ca
// 006026bc  6870359c00           push 0x9c3570
// 006026c1  57                   push edi
// 006026c2  e8c9da0000           call 0x610190
// 006026c7  83c408               add esp, 8
// 006026ca  3baf64020000         cmp ebp, dword ptr [edi + 0x264]
// 006026d0  7708                 ja 0x6026da
// 006026d2  3b9f68020000         cmp ebx, dword ptr [edi + 0x268]
// 006026d8  760e                 jbe 0x6026e8
// 006026da  6848359c00           push 0x9c3548
// 006026df  57                   push edi
// 006026e0  e8abda0000           call 0x610190
// 006026e5  83c408               add esp, 8
// 006026e8  81fdffffff7f         cmp ebp, 0x7fffffff
// 006026ee  7708                 ja 0x6026f8
// 006026f0  81fbffffff7f         cmp ebx, 0x7fffffff
// 006026f6  760e                 jbe 0x602706
// 006026f8  682c359c00           push 0x9c352c
// 006026fd  57                   push edi
// 006026fe  e88dda0000           call 0x610190
// 00602703  83c408               add esp, 8
// 00602706  81fd7effff1f         cmp ebp, 0x1fffff7e
// 0060270c  760e                 jbe 0x60271c
// 0060270e  68fc349c00           push 0x9c34fc
// 00602713  57                   push edi
// 00602714  e827db0000           call 0x610240
// 00602719  83c408               add esp, 8
// 0060271c  8b442424             mov eax, dword ptr [esp + 0x24]
// 00602720  83f801               cmp eax, 1
// 00602723  7422                 je 0x602747
// 00602725  83f802               cmp eax, 2
// 00602728  741d                 je 0x602747
// 0060272a  83f804               cmp eax, 4
// 0060272d  7418                 je 0x602747
// 0060272f  83f808               cmp eax, 8
// 00602732  7413                 je 0x602747
// 00602734  83f810               cmp eax, 0x10
// 00602737  740e                 je 0x602747
// 00602739  68e0349c00           push 0x9c34e0
// 0060273e  57                   push edi
// 0060273f  e84cda0000           call 0x610190
// 00602744  83c408               add esp, 8
// 00602747  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0060274b  85db                 test ebx, ebx
// 0060274d  7c0f                 jl 0x60275e
// 0060274f  83fb01               cmp ebx, 1
// 00602752  740a                 je 0x60275e
// 00602754  83fb05               cmp ebx, 5
// 00602757  7405                 je 0x60275e
// 00602759  83fb06               cmp ebx, 6
// 0060275c  7e0e                 jle 0x60276c
// 0060275e  68c4349c00           push 0x9c34c4
// 00602763  57                   push edi
// 00602764  e827da0000           call 0x610190
// 00602769  83c408               add esp, 8
// 0060276c  83fb03               cmp ebx, 3
// 0060276f  7509                 jne 0x60277a
// 00602771  837c242408           cmp dword ptr [esp + 0x24], 8
// 00602776  7f18                 jg 0x602790
// 00602778  eb24                 jmp 0x60279e
// 0060277a  83fb02               cmp ebx, 2
// 0060277d  740a                 je 0x602789
// 0060277f  83fb04               cmp ebx, 4
// 00602782  7405                 je 0x602789
// 00602784  83fb06               cmp ebx, 6
// 00602787  7515                 jne 0x60279e
// 00602789  837c242408           cmp dword ptr [esp + 0x24], 8
// 0060278e  7d0e                 jge 0x60279e
// 00602790  6890349c00           push 0x9c3490
// 00602795  57                   push edi
// 00602796  e8f5d90000           call 0x610190
// 0060279b  83c408               add esp, 8
// 0060279e  837c242c02           cmp dword ptr [esp + 0x2c], 2
// 006027a3  7c0e                 jl 0x6027b3
// 006027a5  686c349c00           push 0x9c346c
// 006027aa  57                   push edi
// 006027ab  e8e0d90000           call 0x610190
// 006027b0  83c408               add esp, 8
// 006027b3  837c243000           cmp dword ptr [esp + 0x30], 0
// 006027b8  740e                 je 0x6027c8
// 006027ba  6848349c00           push 0x9c3448
// 006027bf  57                   push edi
// 006027c0  e8cbd90000           call 0x610190
// 006027c5  83c408               add esp, 8
// 006027c8  bd00100000           mov ebp, 0x1000
// 006027cd  856f68               test dword ptr [edi + 0x68], ebp
// 006027d0  7417                 je 0x6027e9
// 006027d2  83bf3002000000       cmp dword ptr [edi + 0x230], 0
// 006027d9  740e                 je 0x6027e9
// 006027db  68e4309c00           push 0x9c30e4
// 006027e0  57                   push edi
// 006027e1  e85ada0000           call 0x610240
// 006027e6  83c408               add esp, 8
// 006027e9  8b442434             mov eax, dword ptr [esp + 0x34]
// 006027ed  85c0                 test eax, eax
// 006027ef  743e                 je 0x60282f
// 006027f1  f6873002000004       test byte ptr [edi + 0x230], 4
// 006027f8  7414                 je 0x60280e
// 006027fa  83f840               cmp eax, 0x40
// 006027fd  750f                 jne 0x60280e
// 006027ff  856f68               test dword ptr [edi + 0x68], ebp
// 00602802  750a                 jne 0x60280e
// 00602804  83fb02               cmp ebx, 2
// 00602807  7413                 je 0x60281c
// 00602809  83fb06               cmp ebx, 6
// 0060280c  740e                 je 0x60281c
// 0060280e  6828349c00           push 0x9c3428
// 00602813  57                   push edi
// 00602814  e877d90000           call 0x610190
// 00602819  83c408               add esp, 8
// 0060281c  856f68               test dword ptr [edi + 0x68], ebp
// 0060281f  740e                 je 0x60282f
// 00602821  6808349c00           push 0x9c3408
// 00602826  57                   push edi
// 00602827  e814da0000           call 0x610240
// 0060282c  83c408               add esp, 8
// 0060282f  8b442420             mov eax, dword ptr [esp + 0x20]
// 00602833  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00602837  8a542424             mov dl, byte ptr [esp + 0x24]
// 0060283b  894604               mov dword ptr [esi + 4], eax
// 0060283e  8a442430             mov al, byte ptr [esp + 0x30]
// 00602842  88461a               mov byte ptr [esi + 0x1a], al
// 00602845  8a442434             mov al, byte ptr [esp + 0x34]
// 00602849  88461b               mov byte ptr [esi + 0x1b], al
// 0060284c  8a44242c             mov al, byte ptr [esp + 0x2c]
// 00602850  890e                 mov dword ptr [esi], ecx
// 00602852  885618               mov byte ptr [esi + 0x18], dl
// 00602855  885e19               mov byte ptr [esi + 0x19], bl
// 00602858  88461c               mov byte ptr [esi + 0x1c], al
// 0060285b  80fb03               cmp bl, 3
// 0060285e  740b                 je 0x60286b
// 00602860  f6c302               test bl, 2
// 00602863  7406                 je 0x60286b
// 00602865  c6461d03             mov byte ptr [esi + 0x1d], 3
// 00602869  eb04                 jmp 0x60286f
// 0060286b  c6461d01             mov byte ptr [esi + 0x1d], 1
// 0060286f  5d                   pop ebp
// 00602870  f6c304               test bl, 4
// 00602873  5b                   pop ebx
// 00602874  7403                 je 0x602879
// 00602876  fe461d               inc byte ptr [esi + 0x1d]
// 00602879  8a461d               mov al, byte ptr [esi + 0x1d]
// 0060287c  f6ea                 imul dl
// 0060287e  88461e               mov byte ptr [esi + 0x1e], al
// 00602881  81f97effff1f         cmp ecx, 0x1fffff7e
// 00602887  760a                 jbe 0x602893
// 00602889  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00602890  5e                   pop esi
// 00602891  5f                   pop edi
// 00602892  c3                   ret 
// 00602893  3c08                 cmp al, 8
// 00602895  0fb6c0               movzx eax, al
// 00602898  720c                 jb 0x6028a6
// 0060289a  c1e803               shr eax, 3
// 0060289d  0fafc1               imul eax, ecx
// 006028a0  89460c               mov dword ptr [esi + 0xc], eax
// 006028a3  5e                   pop esi
// 006028a4  5f                   pop edi
// 006028a5  c3                   ret 
// 006028a6  0fafc1               imul eax, ecx
// 006028a9  83c007               add eax, 7
// 006028ac  c1e803               shr eax, 3
// 006028af  89460c               mov dword ptr [esi + 0xc], eax
// 006028b2  5e                   pop esi
// 006028b3  5f                   pop edi
// 006028b4  c3                   ret 
// library libpng-1.2.10/pngset.c (function _png_set_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngset.c
