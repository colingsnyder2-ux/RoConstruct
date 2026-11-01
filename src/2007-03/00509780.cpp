// from server: 100% by auto
// roc 2007-03 00509780  unit: seg_00500000  size: 550 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00509780
//
// 00509780  57                   push edi
// 00509781  8b7c2408             mov edi, dword ptr [esp + 8]
// 00509785  85ff                 test edi, edi
// 00509787  0f8417020000         je 0x5099a4
// 0050978d  56                   push esi
// 0050978e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00509792  85f6                 test esi, esi
// 00509794  0f8409020000         je 0x5099a3
// 0050979a  53                   push ebx
// 0050979b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0050979f  55                   push ebp
// 005097a0  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 005097a4  85ed                 test ebp, ebp
// 005097a6  7404                 je 0x5097ac
// 005097a8  85db                 test ebx, ebx
// 005097aa  750e                 jne 0x5097ba
// 005097ac  68f40b7a00           push 0x7a0bf4
// 005097b1  57                   push edi
// 005097b2  e869eb0000           call 0x518320
// 005097b7  83c408               add esp, 8
// 005097ba  3baf64020000         cmp ebp, dword ptr [edi + 0x264]
// 005097c0  7708                 ja 0x5097ca
// 005097c2  3b9f68020000         cmp ebx, dword ptr [edi + 0x268]
// 005097c8  760e                 jbe 0x5097d8
// 005097ca  68cc0b7a00           push 0x7a0bcc
// 005097cf  57                   push edi
// 005097d0  e84beb0000           call 0x518320
// 005097d5  83c408               add esp, 8
// 005097d8  81fdffffff7f         cmp ebp, 0x7fffffff
// 005097de  7708                 ja 0x5097e8
// 005097e0  81fbffffff7f         cmp ebx, 0x7fffffff
// 005097e6  760e                 jbe 0x5097f6
// 005097e8  68b00b7a00           push 0x7a0bb0
// 005097ed  57                   push edi
// 005097ee  e82deb0000           call 0x518320
// 005097f3  83c408               add esp, 8
// 005097f6  81fd7effff1f         cmp ebp, 0x1fffff7e
// 005097fc  760e                 jbe 0x50980c
// 005097fe  68800b7a00           push 0x7a0b80
// 00509803  57                   push edi
// 00509804  e8c7eb0000           call 0x5183d0
// 00509809  83c408               add esp, 8
// 0050980c  8b442424             mov eax, dword ptr [esp + 0x24]
// 00509810  83f801               cmp eax, 1
// 00509813  7422                 je 0x509837
// 00509815  83f802               cmp eax, 2
// 00509818  741d                 je 0x509837
// 0050981a  83f804               cmp eax, 4
// 0050981d  7418                 je 0x509837
// 0050981f  83f808               cmp eax, 8
// 00509822  7413                 je 0x509837
// 00509824  83f810               cmp eax, 0x10
// 00509827  740e                 je 0x509837
// 00509829  68640b7a00           push 0x7a0b64
// 0050982e  57                   push edi
// 0050982f  e8ecea0000           call 0x518320
// 00509834  83c408               add esp, 8
// 00509837  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0050983b  85db                 test ebx, ebx
// 0050983d  7c0f                 jl 0x50984e
// 0050983f  83fb01               cmp ebx, 1
// 00509842  740a                 je 0x50984e
// 00509844  83fb05               cmp ebx, 5
// 00509847  7405                 je 0x50984e
// 00509849  83fb06               cmp ebx, 6
// 0050984c  7e0e                 jle 0x50985c
// 0050984e  68480b7a00           push 0x7a0b48
// 00509853  57                   push edi
// 00509854  e8c7ea0000           call 0x518320
// 00509859  83c408               add esp, 8
// 0050985c  83fb03               cmp ebx, 3
// 0050985f  7509                 jne 0x50986a
// 00509861  837c242408           cmp dword ptr [esp + 0x24], 8
// 00509866  7f18                 jg 0x509880
// 00509868  eb24                 jmp 0x50988e
// 0050986a  83fb02               cmp ebx, 2
// 0050986d  740a                 je 0x509879
// 0050986f  83fb04               cmp ebx, 4
// 00509872  7405                 je 0x509879
// 00509874  83fb06               cmp ebx, 6
// 00509877  7515                 jne 0x50988e
// 00509879  837c242408           cmp dword ptr [esp + 0x24], 8
// 0050987e  7d0e                 jge 0x50988e
// 00509880  68140b7a00           push 0x7a0b14
// 00509885  57                   push edi
// 00509886  e895ea0000           call 0x518320
// 0050988b  83c408               add esp, 8
// 0050988e  837c242c02           cmp dword ptr [esp + 0x2c], 2
// 00509893  7c0e                 jl 0x5098a3
// 00509895  68f00a7a00           push 0x7a0af0
// 0050989a  57                   push edi
// 0050989b  e880ea0000           call 0x518320
// 005098a0  83c408               add esp, 8
// 005098a3  837c243000           cmp dword ptr [esp + 0x30], 0
// 005098a8  740e                 je 0x5098b8
// 005098aa  68cc0a7a00           push 0x7a0acc
// 005098af  57                   push edi
// 005098b0  e86bea0000           call 0x518320
// 005098b5  83c408               add esp, 8
// 005098b8  bd00100000           mov ebp, 0x1000
// 005098bd  856f68               test dword ptr [edi + 0x68], ebp
// 005098c0  7417                 je 0x5098d9
// 005098c2  83bf3002000000       cmp dword ptr [edi + 0x230], 0
// 005098c9  740e                 je 0x5098d9
// 005098cb  68a4077a00           push 0x7a07a4
// 005098d0  57                   push edi
// 005098d1  e8faea0000           call 0x5183d0
// 005098d6  83c408               add esp, 8
// 005098d9  8b442434             mov eax, dword ptr [esp + 0x34]
// 005098dd  85c0                 test eax, eax
// 005098df  743e                 je 0x50991f
// 005098e1  f6873002000004       test byte ptr [edi + 0x230], 4
// 005098e8  7414                 je 0x5098fe
// 005098ea  83f840               cmp eax, 0x40
// 005098ed  750f                 jne 0x5098fe
// 005098ef  856f68               test dword ptr [edi + 0x68], ebp
// 005098f2  750a                 jne 0x5098fe
// 005098f4  83fb02               cmp ebx, 2
// 005098f7  7413                 je 0x50990c
// 005098f9  83fb06               cmp ebx, 6
// 005098fc  740e                 je 0x50990c
// 005098fe  68ac0a7a00           push 0x7a0aac
// 00509903  57                   push edi
// 00509904  e817ea0000           call 0x518320
// 00509909  83c408               add esp, 8
// 0050990c  856f68               test dword ptr [edi + 0x68], ebp
// 0050990f  740e                 je 0x50991f
// 00509911  688c0a7a00           push 0x7a0a8c
// 00509916  57                   push edi
// 00509917  e8b4ea0000           call 0x5183d0
// 0050991c  83c408               add esp, 8
// 0050991f  80fb03               cmp bl, 3
// 00509922  8b442420             mov eax, dword ptr [esp + 0x20]
// 00509926  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0050992a  8a542424             mov dl, byte ptr [esp + 0x24]
// 0050992e  894604               mov dword ptr [esi + 4], eax
// 00509931  8a442430             mov al, byte ptr [esp + 0x30]
// 00509935  88461a               mov byte ptr [esi + 0x1a], al
// 00509938  8a442434             mov al, byte ptr [esp + 0x34]
// 0050993c  88461b               mov byte ptr [esi + 0x1b], al
// 0050993f  8a44242c             mov al, byte ptr [esp + 0x2c]
// 00509943  890e                 mov dword ptr [esi], ecx
// 00509945  885618               mov byte ptr [esi + 0x18], dl
// 00509948  885e19               mov byte ptr [esi + 0x19], bl
// 0050994b  88461c               mov byte ptr [esi + 0x1c], al
// 0050994e  740b                 je 0x50995b
// 00509950  f6c302               test bl, 2
// 00509953  7406                 je 0x50995b
// 00509955  c6461d03             mov byte ptr [esi + 0x1d], 3
// 00509959  eb04                 jmp 0x50995f
// 0050995b  c6461d01             mov byte ptr [esi + 0x1d], 1
// 0050995f  5d                   pop ebp
// 00509960  f6c304               test bl, 4
// 00509963  5b                   pop ebx
// 00509964  7404                 je 0x50996a
// 00509966  80461d01             add byte ptr [esi + 0x1d], 1
// 0050996a  8a461d               mov al, byte ptr [esi + 0x1d]
// 0050996d  f6ea                 imul dl
// 0050996f  81f97effff1f         cmp ecx, 0x1fffff7e
// 00509975  88461e               mov byte ptr [esi + 0x1e], al
// 00509978  760a                 jbe 0x509984
// 0050997a  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00509981  5e                   pop esi
// 00509982  5f                   pop edi
// 00509983  c3                   ret 
// 00509984  3c08                 cmp al, 8
// 00509986  0fb6c0               movzx eax, al
// 00509989  720c                 jb 0x509997
// 0050998b  c1e803               shr eax, 3
// 0050998e  0fafc1               imul eax, ecx
// 00509991  89460c               mov dword ptr [esi + 0xc], eax
// 00509994  5e                   pop esi
// 00509995  5f                   pop edi
// 00509996  c3                   ret 
// 00509997  0fafc1               imul eax, ecx
// 0050999a  83c007               add eax, 7
// 0050999d  c1e803               shr eax, 3
// 005099a0  89460c               mov dword ptr [esi + 0xc], eax
// 005099a3  5e                   pop esi
// 005099a4  5f                   pop edi
// 005099a5  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_IHDR)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
