// from server: 100% by auto
// roc 2009-12 00616840  unit: seg_00610000  size: 798 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00616840
//
// 00616840  83ec38               sub esp, 0x38
// 00616843  53                   push ebx
// 00616844  55                   push ebp
// 00616845  56                   push esi
// 00616846  8b742448             mov esi, dword ptr [esp + 0x48]
// 0061684a  33d2                 xor edx, edx
// 0061684c  b804000000           mov eax, 4
// 00616851  b902000000           mov ecx, 2
// 00616856  57                   push edi
// 00616857  bb01000000           mov ebx, 1
// 0061685c  bf08000000           mov edi, 8
// 00616861  56                   push esi
// 00616862  89542430             mov dword ptr [esp + 0x30], edx
// 00616866  89442434             mov dword ptr [esp + 0x34], eax
// 0061686a  89542438             mov dword ptr [esp + 0x38], edx
// 0061686e  894c243c             mov dword ptr [esp + 0x3c], ecx
// 00616872  89542440             mov dword ptr [esp + 0x40], edx
// 00616876  895c2444             mov dword ptr [esp + 0x44], ebx
// 0061687a  89542448             mov dword ptr [esp + 0x48], edx
// 0061687e  897c2414             mov dword ptr [esp + 0x14], edi
// 00616882  897c2418             mov dword ptr [esp + 0x18], edi
// 00616886  8944241c             mov dword ptr [esp + 0x1c], eax
// 0061688a  89442420             mov dword ptr [esp + 0x20], eax
// 0061688e  894c2424             mov dword ptr [esp + 0x24], ecx
// 00616892  894c2428             mov dword ptr [esp + 0x28], ecx
// 00616896  895c242c             mov dword ptr [esp + 0x2c], ebx
// 0061689a  895678               mov dword ptr [esi + 0x78], edx
// 0061689d  e82e2effff           call 0x6096d0
// 006168a2  83c404               add esp, 4
// 006168a5  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 006168ac  7472                 je 0x616920
// 006168ae  f6467002             test byte ptr [esi + 0x70], 2
// 006168b2  7514                 jne 0x6168c8
// 006168b4  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 006168ba  83c007               add eax, 7
// 006168bd  c1e803               shr eax, 3
// 006168c0  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 006168c6  eb0c                 jmp 0x6168d4
// 006168c8  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 006168ce  898ed0000000         mov dword ptr [esi + 0xd0], ecx
// 006168d4  0fb68624010000       movzx eax, byte ptr [esi + 0x124]
// 006168db  8baec8000000         mov ebp, dword ptr [esi + 0xc8]
// 006168e1  03c0                 add eax, eax
// 006168e3  03c0                 add eax, eax
// 006168e5  8b4c0410             mov ecx, dword ptr [esp + eax + 0x10]
// 006168e9  8bd5                 mov edx, ebp
// 006168eb  2b54042c             sub edx, dword ptr [esp + eax + 0x2c]
// 006168ef  8d440aff             lea eax, [edx + ecx - 1]
// 006168f3  33d2                 xor edx, edx
// 006168f5  f7f1                 div ecx
// 006168f7  8a8e29010000         mov cl, byte ptr [esi + 0x129]
// 006168fd  80f908               cmp cl, 8
// 00616900  0fb6c9               movzx ecx, cl
// 00616903  8986e0000000         mov dword ptr [esi + 0xe0], eax
// 00616909  7209                 jb 0x616914
// 0061690b  c1e903               shr ecx, 3
// 0061690e  0fafc8               imul ecx, eax
// 00616911  41                   inc ecx
// 00616912  eb2c                 jmp 0x616940
// 00616914  0fafc8               imul ecx, eax
// 00616917  83c107               add ecx, 7
// 0061691a  c1e903               shr ecx, 3
// 0061691d  41                   inc ecx
// 0061691e  eb20                 jmp 0x616940
// 00616920  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 00616926  8baec8000000         mov ebp, dword ptr [esi + 0xc8]
// 0061692c  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 00616932  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 00616938  89aee0000000         mov dword ptr [esi + 0xe0], ebp
// 0061693e  03cb                 add ecx, ebx
// 00616940  8b5e70               mov ebx, dword ptr [esi + 0x70]
// 00616943  0fb68629010000       movzx eax, byte ptr [esi + 0x129]
// 0061694a  898edc000000         mov dword ptr [esi + 0xdc], ecx
// 00616950  f6c304               test bl, 4
// 00616953  740b                 je 0x616960
// 00616955  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 0061695c  7302                 jae 0x616960
// 0061695e  8bc7                 mov eax, edi
// 00616960  8bfb                 mov edi, ebx
// 00616962  81e700100000         and edi, 0x1000
// 00616968  7460                 je 0x6169ca
// 0061696a  8a8e26010000         mov cl, byte ptr [esi + 0x126]
// 00616970  80f903               cmp cl, 3
// 00616973  7515                 jne 0x61698a
// 00616975  33c0                 xor eax, eax
// 00616977  6639861a010000       cmp word ptr [esi + 0x11a], ax
// 0061697e  0f95c0               setne al
// 00616981  8d04c518000000       lea eax, [eax*8 + 0x18]
// 00616988  eb40                 jmp 0x6169ca
// 0061698a  84c9                 test cl, cl
// 0061698c  7518                 jne 0x6169a6
// 0061698e  83f808               cmp eax, 8
// 00616991  7d05                 jge 0x616998
// 00616993  b808000000           mov eax, 8
// 00616998  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 006169a0  7428                 je 0x6169ca
// 006169a2  03c0                 add eax, eax
// 006169a4  eb24                 jmp 0x6169ca
// 006169a6  80f902               cmp cl, 2
// 006169a9  751f                 jne 0x6169ca
// 006169ab  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 006169b3  7415                 je 0x6169ca
// 006169b5  8d0c8500000000       lea ecx, [eax*4]
// 006169bc  b856555555           mov eax, 0x55555556
// 006169c1  f7e9                 imul ecx
// 006169c3  8bc2                 mov eax, edx
// 006169c5  c1e81f               shr eax, 0x1f
// 006169c8  03c2                 add eax, edx
// 006169ca  8bd3                 mov edx, ebx
// 006169cc  81e200800000         and edx, 0x8000
// 006169d2  743d                 je 0x616a11
// 006169d4  8a8e26010000         mov cl, byte ptr [esi + 0x126]
// 006169da  80f903               cmp cl, 3
// 006169dd  7507                 jne 0x6169e6
// 006169df  b820000000           mov eax, 0x20
// 006169e4  eb2b                 jmp 0x616a11
// 006169e6  84c9                 test cl, cl
// 006169e8  7511                 jne 0x6169fb
// 006169ea  33c9                 xor ecx, ecx
// 006169ec  83f808               cmp eax, 8
// 006169ef  0f9fc1               setg cl
// 006169f2  49                   dec ecx
// 006169f3  83e1f0               and ecx, 0xfffffff0
// 006169f6  83c120               add ecx, 0x20
// 006169f9  eb14                 jmp 0x616a0f
// 006169fb  80f902               cmp cl, 2
// 006169fe  7511                 jne 0x616a11
// 00616a00  33c9                 xor ecx, ecx
// 00616a02  83f820               cmp eax, 0x20
// 00616a05  0f9fc1               setg cl
// 00616a08  49                   dec ecx
// 00616a09  83e1e0               and ecx, 0xffffffe0
// 00616a0c  83c140               add ecx, 0x40
// 00616a0f  8bc1                 mov eax, ecx
// 00616a11  f7c300400000         test ebx, 0x4000
// 00616a17  7455                 je 0x616a6e
// 00616a19  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 00616a21  7404                 je 0x616a27
// 00616a23  85ff                 test edi, edi
// 00616a25  7536                 jne 0x616a5d
// 00616a27  85d2                 test edx, edx
// 00616a29  7532                 jne 0x616a5d
// 00616a2b  8a8e26010000         mov cl, byte ptr [esi + 0x126]
// 00616a31  80f904               cmp cl, 4
// 00616a34  7427                 je 0x616a5d
// 00616a36  83f808               cmp eax, 8
// 00616a39  7f11                 jg 0x616a4c
// 00616a3b  33c0                 xor eax, eax
// 00616a3d  80f906               cmp cl, 6
// 00616a40  0f94c0               sete al
// 00616a43  8d04c518000000       lea eax, [eax*8 + 0x18]
// 00616a4a  eb22                 jmp 0x616a6e
// 00616a4c  33c0                 xor eax, eax
// 00616a4e  80f906               cmp cl, 6
// 00616a51  0f95c0               setne al
// 00616a54  48                   dec eax
// 00616a55  83e010               and eax, 0x10
// 00616a58  83c030               add eax, 0x30
// 00616a5b  eb11                 jmp 0x616a6e
// 00616a5d  33d2                 xor edx, edx
// 00616a5f  83f810               cmp eax, 0x10
// 00616a62  0f9fc2               setg dl
// 00616a65  4a                   dec edx
// 00616a66  83e2e0               and edx, 0xffffffe0
// 00616a69  83c240               add edx, 0x40
// 00616a6c  8bc2                 mov eax, edx
// 00616a6e  f7c300001000         test ebx, 0x100000
// 00616a74  7411                 je 0x616a87
// 00616a76  0fb64e65             movzx ecx, byte ptr [esi + 0x65]
// 00616a7a  0fb65664             movzx edx, byte ptr [esi + 0x64]
// 00616a7e  0fafca               imul ecx, edx
// 00616a81  3bc8                 cmp ecx, eax
// 00616a83  7e02                 jle 0x616a87
// 00616a85  8bc1                 mov eax, ecx
// 00616a87  8d4d07               lea ecx, [ebp + 7]
// 00616a8a  83e1f8               and ecx, 0xfffffff8
// 00616a8d  83f808               cmp eax, 8
// 00616a90  7c0a                 jl 0x616a9c
// 00616a92  8bd0                 mov edx, eax
// 00616a94  c1ea03               shr edx, 3
// 00616a97  0fafd1               imul edx, ecx
// 00616a9a  eb0b                 jmp 0x616aa7
// 00616a9c  0fafc8               imul ecx, eax
// 00616a9f  83c107               add ecx, 7
// 00616aa2  c1e903               shr ecx, 3
// 00616aa5  8bd1                 mov edx, ecx
// 00616aa7  83c007               add eax, 7
// 00616aaa  c1f803               sar eax, 3
// 00616aad  8d441001             lea eax, [eax + edx + 1]
// 00616ab1  8d7840               lea edi, [eax + 0x40]
// 00616ab4  3bbe80020000         cmp edi, dword ptr [esi + 0x280]
// 00616aba  762c                 jbe 0x616ae8
// 00616abc  8b8650020000         mov eax, dword ptr [esi + 0x250]
// 00616ac2  50                   push eax
// 00616ac3  56                   push esi
// 00616ac4  e817a2ffff           call 0x610ce0
// 00616ac9  57                   push edi
// 00616aca  56                   push esi
// 00616acb  e8b0a1ffff           call 0x610c80
// 00616ad0  83c410               add esp, 0x10
// 00616ad3  898650020000         mov dword ptr [esi + 0x250], eax
// 00616ad9  83c020               add eax, 0x20
// 00616adc  8986ec000000         mov dword ptr [esi + 0xec], eax
// 00616ae2  89be80020000         mov dword ptr [esi + 0x280], edi
// 00616ae8  83bed8000000fe       cmp dword ptr [esi + 0xd8], -2
// 00616aef  760e                 jbe 0x616aff
// 00616af1  68808f9c00           push 0x9c8f80
// 00616af6  56                   push esi
// 00616af7  e89496ffff           call 0x610190
// 00616afc  83c408               add esp, 8
// 00616aff  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00616b05  40                   inc eax
// 00616b06  3b8684020000         cmp eax, dword ptr [esi + 0x284]
// 00616b0c  7631                 jbe 0x616b3f
// 00616b0e  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 00616b14  51                   push ecx
// 00616b15  56                   push esi
// 00616b16  e8c5a1ffff           call 0x610ce0
// 00616b1b  8b96d8000000         mov edx, dword ptr [esi + 0xd8]
// 00616b21  42                   inc edx
// 00616b22  52                   push edx
// 00616b23  56                   push esi
// 00616b24  e857a1ffff           call 0x610c80
// 00616b29  8986e8000000         mov dword ptr [esi + 0xe8], eax
// 00616b2f  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00616b35  83c410               add esp, 0x10
// 00616b38  40                   inc eax
// 00616b39  898684020000         mov dword ptr [esi + 0x284], eax
// 00616b3f  50                   push eax
// 00616b40  8b86e8000000         mov eax, dword ptr [esi + 0xe8]
// 00616b46  6a00                 push 0
// 00616b48  50                   push eax
// 00616b49  56                   push esi
// 00616b4a  e8c1a0ffff           call 0x610c10
// 00616b4f  83c410               add esp, 0x10
// 00616b52  834e6c40             or dword ptr [esi + 0x6c], 0x40
// 00616b56  5f                   pop edi
// 00616b57  5e                   pop esi
// 00616b58  5d                   pop ebp
// 00616b59  5b                   pop ebx
// 00616b5a  83c438               add esp, 0x38
// 00616b5d  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_read_start_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
