// from server: 100% by auto
// roc 2012-06 00656520  unit: seg_00650000  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00656520
//
// 00656520  83ec0c               sub esp, 0xc
// 00656523  55                   push ebp
// 00656524  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00656528  56                   push esi
// 00656529  8b742418             mov esi, dword ptr [esp + 0x18]
// 0065652d  f6863002000001       test byte ptr [esi + 0x230], 1
// 00656534  c644240c50           mov byte ptr [esp + 0xc], 0x50
// 00656539  c644240d4c           mov byte ptr [esp + 0xd], 0x4c
// 0065653e  c644240e54           mov byte ptr [esp + 0xe], 0x54
// 00656543  c644240f45           mov byte ptr [esp + 0xf], 0x45
// 00656548  c644241000           mov byte ptr [esp + 0x10], 0
// 0065654d  7504                 jne 0x656553
// 0065654f  85ed                 test ebp, ebp
// 00656551  7408                 je 0x65655b
// 00656553  81fd00010000         cmp ebp, 0x100
// 00656559  7617                 jbe 0x656572
// 0065655b  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 00656562  688499b800           push 0xb89984
// 00656567  56                   push esi
// 00656568  7517                 jne 0x656581
// 0065656a  e8417cffff           call 0x64e1b0
// 0065656f  83c408               add esp, 8
// 00656572  f6862601000002       test byte ptr [esi + 0x126], 2
// 00656579  7514                 jne 0x65658f
// 0065657b  684c99b800           push 0xb8994c
// 00656580  56                   push esi
// 00656581  e8da7cffff           call 0x64e260
// 00656586  83c408               add esp, 8
// 00656589  5e                   pop esi
// 0065658a  5d                   pop ebp
// 0065658b  83c40c               add esp, 0xc
// 0065658e  c3                   ret 
// 0065658f  8d446d00             lea eax, [ebp + ebp*2]
// 00656593  50                   push eax
// 00656594  8d4c2410             lea ecx, [esp + 0x10]
// 00656598  51                   push ecx
// 00656599  56                   push esi
// 0065659a  6689ae18010000       mov word ptr [esi + 0x118], bp
// 006565a1  e81afbffff           call 0x6560c0
// 006565a6  83c40c               add esp, 0xc
// 006565a9  85ed                 test ebp, ebp
// 006565ab  7642                 jbe 0x6565ef
// 006565ad  57                   push edi
// 006565ae  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006565b2  83c702               add edi, 2
// 006565b5  8a57fe               mov dl, byte ptr [edi - 2]
// 006565b8  8a47ff               mov al, byte ptr [edi - 1]
// 006565bb  8a0f                 mov cl, byte ptr [edi]
// 006565bd  8854241c             mov byte ptr [esp + 0x1c], dl
// 006565c1  6a03                 push 3
// 006565c3  8d542420             lea edx, [esp + 0x20]
// 006565c7  52                   push edx
// 006565c8  56                   push esi
// 006565c9  88442429             mov byte ptr [esp + 0x29], al
// 006565cd  884c242a             mov byte ptr [esp + 0x2a], cl
// 006565d1  e8ea10ffff           call 0x6476c0
// 006565d6  6a03                 push 3
// 006565d8  8d44242c             lea eax, [esp + 0x2c]
// 006565dc  50                   push eax
// 006565dd  56                   push esi
// 006565de  e8ad78feff           call 0x63de90
// 006565e3  83c418               add esp, 0x18
// 006565e6  83c703               add edi, 3
// 006565e9  83ed01               sub ebp, 1
// 006565ec  75c7                 jne 0x6565b5
// 006565ee  5f                   pop edi
// 006565ef  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 006565f5  8bd0                 mov edx, eax
// 006565f7  8bc8                 mov ecx, eax
// 006565f9  c1e918               shr ecx, 0x18
// 006565fc  c1ea10               shr edx, 0x10
// 006565ff  884c2408             mov byte ptr [esp + 8], cl
// 00656603  88542409             mov byte ptr [esp + 9], dl
// 00656607  6a04                 push 4
// 00656609  8d54240c             lea edx, [esp + 0xc]
// 0065660d  8bc8                 mov ecx, eax
// 0065660f  52                   push edx
// 00656610  c1e908               shr ecx, 8
// 00656613  56                   push esi
// 00656614  884c2416             mov byte ptr [esp + 0x16], cl
// 00656618  88442417             mov byte ptr [esp + 0x17], al
// 0065661c  e89f10ffff           call 0x6476c0
// 00656621  83c40c               add esp, 0xc
// 00656624  834e6802             or dword ptr [esi + 0x68], 2
// 00656628  5e                   pop esi
// 00656629  5d                   pop ebp
// 0065662a  83c40c               add esp, 0xc
// 0065662d  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
