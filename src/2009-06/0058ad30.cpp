// from server: 100% by auto
// roc 2009-06 0058ad30  unit: seg_00580000  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058ad30
//
// 0058ad30  83ec0c               sub esp, 0xc
// 0058ad33  55                   push ebp
// 0058ad34  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0058ad38  56                   push esi
// 0058ad39  8b742418             mov esi, dword ptr [esp + 0x18]
// 0058ad3d  f6863002000001       test byte ptr [esi + 0x230], 1
// 0058ad44  c644240c50           mov byte ptr [esp + 0xc], 0x50
// 0058ad49  c644240d4c           mov byte ptr [esp + 0xd], 0x4c
// 0058ad4e  c644240e54           mov byte ptr [esp + 0xe], 0x54
// 0058ad53  c644240f45           mov byte ptr [esp + 0xf], 0x45
// 0058ad58  c644241000           mov byte ptr [esp + 0x10], 0
// 0058ad5d  7504                 jne 0x58ad63
// 0058ad5f  85ed                 test ebp, ebp
// 0058ad61  7408                 je 0x58ad6b
// 0058ad63  81fd00010000         cmp ebp, 0x100
// 0058ad69  7617                 jbe 0x58ad82
// 0058ad6b  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 0058ad72  686ceb8c00           push 0x8ceb6c
// 0058ad77  56                   push esi
// 0058ad78  7517                 jne 0x58ad91
// 0058ad7a  e8e1330000           call 0x58e160
// 0058ad7f  83c408               add esp, 8
// 0058ad82  f6862601000002       test byte ptr [esi + 0x126], 2
// 0058ad89  7514                 jne 0x58ad9f
// 0058ad8b  6834eb8c00           push 0x8ceb34
// 0058ad90  56                   push esi
// 0058ad91  e87a340000           call 0x58e210
// 0058ad96  83c408               add esp, 8
// 0058ad99  5e                   pop esi
// 0058ad9a  5d                   pop ebp
// 0058ad9b  83c40c               add esp, 0xc
// 0058ad9e  c3                   ret 
// 0058ad9f  8d446d00             lea eax, [ebp + ebp*2]
// 0058ada3  50                   push eax
// 0058ada4  8d4c2410             lea ecx, [esp + 0x10]
// 0058ada8  51                   push ecx
// 0058ada9  56                   push esi
// 0058adaa  6689ae18010000       mov word ptr [esi + 0x118], bp
// 0058adb1  e80afbffff           call 0x58a8c0
// 0058adb6  83c40c               add esp, 0xc
// 0058adb9  85ed                 test ebp, ebp
// 0058adbb  7642                 jbe 0x58adff
// 0058adbd  57                   push edi
// 0058adbe  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0058adc2  83c702               add edi, 2
// 0058adc5  8a57fe               mov dl, byte ptr [edi - 2]
// 0058adc8  8a47ff               mov al, byte ptr [edi - 1]
// 0058adcb  8a0f                 mov cl, byte ptr [edi]
// 0058adcd  8854241c             mov byte ptr [esp + 0x1c], dl
// 0058add1  6a03                 push 3
// 0058add3  8d542420             lea edx, [esp + 0x20]
// 0058add7  52                   push edx
// 0058add8  56                   push esi
// 0058add9  88442429             mov byte ptr [esp + 0x29], al
// 0058addd  884c242a             mov byte ptr [esp + 0x2a], cl
// 0058ade1  e8fa67ffff           call 0x5815e0
// 0058ade6  6a03                 push 3
// 0058ade8  8d44242c             lea eax, [esp + 0x2c]
// 0058adec  50                   push eax
// 0058aded  56                   push esi
// 0058adee  e8cd6affff           call 0x5818c0
// 0058adf3  83c418               add esp, 0x18
// 0058adf6  83c703               add edi, 3
// 0058adf9  83ed01               sub ebp, 1
// 0058adfc  75c7                 jne 0x58adc5
// 0058adfe  5f                   pop edi
// 0058adff  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0058ae05  8bd0                 mov edx, eax
// 0058ae07  8bc8                 mov ecx, eax
// 0058ae09  c1e918               shr ecx, 0x18
// 0058ae0c  c1ea10               shr edx, 0x10
// 0058ae0f  884c2408             mov byte ptr [esp + 8], cl
// 0058ae13  88542409             mov byte ptr [esp + 9], dl
// 0058ae17  6a04                 push 4
// 0058ae19  8d54240c             lea edx, [esp + 0xc]
// 0058ae1d  8bc8                 mov ecx, eax
// 0058ae1f  52                   push edx
// 0058ae20  c1e908               shr ecx, 8
// 0058ae23  56                   push esi
// 0058ae24  884c2416             mov byte ptr [esp + 0x16], cl
// 0058ae28  88442417             mov byte ptr [esp + 0x17], al
// 0058ae2c  e8af67ffff           call 0x5815e0
// 0058ae31  83c40c               add esp, 0xc
// 0058ae34  834e6802             or dword ptr [esi + 0x68], 2
// 0058ae38  5e                   pop esi
// 0058ae39  5d                   pop ebp
// 0058ae3a  83c40c               add esp, 0xc
// 0058ae3d  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
