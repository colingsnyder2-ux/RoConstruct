// roc 2012-06 0065b020  unit: seg_00650000  size: 444 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065b020
//
// 0065b020  83ec10               sub esp, 0x10
// 0065b023  53                   push ebx
// 0065b024  55                   push ebp
// 0065b025  56                   push esi
// 0065b026  8b742420             mov esi, dword ptr [esp + 0x20]
// 0065b02a  f6466801             test byte ptr [esi + 0x68], 1
// 0065b02e  57                   push edi
// 0065b02f  740e                 je 0x65b03f
// 0065b031  6884a2b800           push 0xb8a284
// 0065b036  56                   push esi
// 0065b037  e87431ffff           call 0x64e1b0
// 0065b03c  83c408               add esp, 8
// 0065b03f  837c242c0d           cmp dword ptr [esp + 0x2c], 0xd
// 0065b044  740e                 je 0x65b054
// 0065b046  6870a2b800           push 0xb8a270
// 0065b04b  56                   push esi
// 0065b04c  e85f31ffff           call 0x64e1b0
// 0065b051  83c408               add esp, 8
// 0065b054  834e6801             or dword ptr [esi + 0x68], 1
// 0065b058  6a0d                 push 0xd
// 0065b05a  8d442414             lea eax, [esp + 0x14]
// 0065b05e  50                   push eax
// 0065b05f  56                   push esi
// 0065b060  e88b2dffff           call 0x64ddf0
// 0065b065  6a0d                 push 0xd
// 0065b067  8d4c2420             lea ecx, [esp + 0x20]
// 0065b06b  51                   push ecx
// 0065b06c  56                   push esi
// 0065b06d  e81e2efeff           call 0x63de90
// 0065b072  6a00                 push 0
// 0065b074  56                   push esi
// 0065b075  e8d6feffff           call 0x65af50
// 0065b07a  0fb67c2430           movzx edi, byte ptr [esp + 0x30]
// 0065b07f  0fb6542431           movzx edx, byte ptr [esp + 0x31]
// 0065b084  0fb6442432           movzx eax, byte ptr [esp + 0x32]
// 0065b089  0fb64c2433           movzx ecx, byte ptr [esp + 0x33]
// 0065b08e  c1e708               shl edi, 8
// 0065b091  03fa                 add edi, edx
// 0065b093  c1e708               shl edi, 8
// 0065b096  03f8                 add edi, eax
// 0065b098  c1e708               shl edi, 8
// 0065b09b  03f9                 add edi, ecx
// 0065b09d  83c420               add esp, 0x20
// 0065b0a0  81ffffffff7f         cmp edi, 0x7fffffff
// 0065b0a6  760e                 jbe 0x65b0b6
// 0065b0a8  688ca0b800           push 0xb8a08c
// 0065b0ad  56                   push esi
// 0065b0ae  e8fd30ffff           call 0x64e1b0
// 0065b0b3  83c408               add esp, 8
// 0065b0b6  0fb66c2414           movzx ebp, byte ptr [esp + 0x14]
// 0065b0bb  0fb6542415           movzx edx, byte ptr [esp + 0x15]
// 0065b0c0  0fb6442416           movzx eax, byte ptr [esp + 0x16]
// 0065b0c5  0fb64c2417           movzx ecx, byte ptr [esp + 0x17]
// 0065b0ca  c1e508               shl ebp, 8
// 0065b0cd  03ea                 add ebp, edx
// 0065b0cf  c1e508               shl ebp, 8
// 0065b0d2  03e8                 add ebp, eax
// 0065b0d4  c1e508               shl ebp, 8
// 0065b0d7  03e9                 add ebp, ecx
// 0065b0d9  81fdffffff7f         cmp ebp, 0x7fffffff
// 0065b0df  760e                 jbe 0x65b0ef
// 0065b0e1  688ca0b800           push 0xb8a08c
// 0065b0e6  56                   push esi
// 0065b0e7  e8c430ffff           call 0x64e1b0
// 0065b0ec  83c408               add esp, 8
// 0065b0ef  0fb644241b           movzx eax, byte ptr [esp + 0x1b]
// 0065b0f4  0fb64c2419           movzx ecx, byte ptr [esp + 0x19]
// 0065b0f9  0fb6542418           movzx edx, byte ptr [esp + 0x18]
// 0065b0fe  0fb65c241a           movzx ebx, byte ptr [esp + 0x1a]
// 0065b103  89442424             mov dword ptr [esp + 0x24], eax
// 0065b107  0fb644241c           movzx eax, byte ptr [esp + 0x1c]
// 0065b10c  8944242c             mov dword ptr [esp + 0x2c], eax
// 0065b110  888623010000         mov byte ptr [esi + 0x123], al
// 0065b116  8a442424             mov al, byte ptr [esp + 0x24]
// 0065b11a  888638020000         mov byte ptr [esi + 0x238], al
// 0065b120  0fb6c1               movzx eax, cl
// 0065b123  89bec8000000         mov dword ptr [esi + 0xc8], edi
// 0065b129  89aecc000000         mov dword ptr [esi + 0xcc], ebp
// 0065b12f  889627010000         mov byte ptr [esi + 0x127], dl
// 0065b135  888e26010000         mov byte ptr [esi + 0x126], cl
// 0065b13b  889e60020000         mov byte ptr [esi + 0x260], bl
// 0065b141  83f806               cmp eax, 6
// 0065b144  7729                 ja 0x65b16f
// 0065b146  ff2485c0b16500       jmp dword ptr [eax*4 + 0x65b1c0]
// 0065b14d  c6862a01000001       mov byte ptr [esi + 0x12a], 1
// 0065b154  eb19                 jmp 0x65b16f
// 0065b156  c6862a01000003       mov byte ptr [esi + 0x12a], 3
// 0065b15d  eb10                 jmp 0x65b16f
// 0065b15f  c6862a01000002       mov byte ptr [esi + 0x12a], 2
// 0065b166  eb07                 jmp 0x65b16f
// 0065b168  c6862a01000004       mov byte ptr [esi + 0x12a], 4
// 0065b16f  8a862a010000         mov al, byte ptr [esi + 0x12a]
// 0065b175  f6ea                 imul dl
// 0065b177  888629010000         mov byte ptr [esi + 0x129], al
// 0065b17d  3c08                 cmp al, 8
// 0065b17f  0fb6c0               movzx eax, al
// 0065b182  7208                 jb 0x65b18c
// 0065b184  c1e803               shr eax, 3
// 0065b187  0fafc7               imul eax, edi
// 0065b18a  eb09                 jmp 0x65b195
// 0065b18c  0fafc7               imul eax, edi
// 0065b18f  83c007               add eax, 7
// 0065b192  c1e803               shr eax, 3
// 0065b195  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 0065b19b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065b19f  50                   push eax
// 0065b1a0  8b442430             mov eax, dword ptr [esp + 0x30]
// 0065b1a4  53                   push ebx
// 0065b1a5  50                   push eax
// 0065b1a6  51                   push ecx
// 0065b1a7  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0065b1ab  52                   push edx
// 0065b1ac  55                   push ebp
// 0065b1ad  57                   push edi
// 0065b1ae  51                   push ecx
// 0065b1af  56                   push esi
// 0065b1b0  e8dbb7feff           call 0x646990
// 0065b1b5  83c424               add esp, 0x24
// 0065b1b8  5f                   pop edi
// 0065b1b9  5e                   pop esi
// 0065b1ba  5d                   pop ebp
// 0065b1bb  5b                   pop ebx
// 0065b1bc  83c410               add esp, 0x10
// 0065b1bf  c3                   ret 
// 0065b1c0  4d                   dec ebp
// 0065b1c1  b165                 mov cl, 0x65
// 0065b1c3  006fb1               add byte ptr [edi - 0x4f], ch
// 0065b1c6  650056b1             add byte ptr gs:[esi - 0x4f], dl
// 0065b1ca  65004db1             add byte ptr gs:[ebp - 0x4f], cl
// 0065b1ce  65005fb1             add byte ptr gs:[edi - 0x4f], bl
// 0065b1d2  65006fb1             add byte ptr gs:[edi - 0x4f], ch
// 0065b1d6  650068b1             add byte ptr gs:[eax - 0x4f], ch
// library libpng-1.2.10/pngrutil.c (function _png_handle_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngrutil.c
