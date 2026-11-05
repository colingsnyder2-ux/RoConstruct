// from server: 100% by auto
// roc 2010-06 0056e6a0  unit: G3D::LineSegment  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056e6a0
//
// 0056e6a0  83ec0c               sub esp, 0xc
// 0056e6a3  55                   push ebp
// 0056e6a4  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0056e6a8  56                   push esi
// 0056e6a9  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056e6ad  f6863002000001       test byte ptr [esi + 0x230], 1
// 0056e6b4  c644240c50           mov byte ptr [esp + 0xc], 0x50
// 0056e6b9  c644240d4c           mov byte ptr [esp + 0xd], 0x4c
// 0056e6be  c644240e54           mov byte ptr [esp + 0xe], 0x54
// 0056e6c3  c644240f45           mov byte ptr [esp + 0xf], 0x45
// 0056e6c8  c644241000           mov byte ptr [esp + 0x10], 0
// 0056e6cd  7504                 jne 0x56e6d3
// 0056e6cf  85ed                 test ebp, ebp
// 0056e6d1  7408                 je 0x56e6db
// 0056e6d3  81fd00010000         cmp ebp, 0x100
// 0056e6d9  7617                 jbe 0x56e6f2
// 0056e6db  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 0056e6e2  687837a200           push 0xa23778
// 0056e6e7  56                   push esi
// 0056e6e8  7517                 jne 0x56e701
// 0056e6ea  e8c1330000           call 0x571ab0
// 0056e6ef  83c408               add esp, 8
// 0056e6f2  f6862601000002       test byte ptr [esi + 0x126], 2
// 0056e6f9  7514                 jne 0x56e70f
// 0056e6fb  684037a200           push 0xa23740
// 0056e700  56                   push esi
// 0056e701  e85a340000           call 0x571b60
// 0056e706  83c408               add esp, 8
// 0056e709  5e                   pop esi
// 0056e70a  5d                   pop ebp
// 0056e70b  83c40c               add esp, 0xc
// 0056e70e  c3                   ret 
// 0056e70f  8d446d00             lea eax, [ebp + ebp*2]
// 0056e713  50                   push eax
// 0056e714  8d4c2410             lea ecx, [esp + 0x10]
// 0056e718  51                   push ecx
// 0056e719  56                   push esi
// 0056e71a  6689ae18010000       mov word ptr [esi + 0x118], bp
// 0056e721  e80afbffff           call 0x56e230
// 0056e726  83c40c               add esp, 0xc
// 0056e729  85ed                 test ebp, ebp
// 0056e72b  7642                 jbe 0x56e76f
// 0056e72d  57                   push edi
// 0056e72e  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0056e732  83c702               add edi, 2
// 0056e735  8a57fe               mov dl, byte ptr [edi - 2]
// 0056e738  8a47ff               mov al, byte ptr [edi - 1]
// 0056e73b  8a0f                 mov cl, byte ptr [edi]
// 0056e73d  8854241c             mov byte ptr [esp + 0x1c], dl
// 0056e741  6a03                 push 3
// 0056e743  8d542420             lea edx, [esp + 0x20]
// 0056e747  52                   push edx
// 0056e748  56                   push esi
// 0056e749  88442429             mov byte ptr [esp + 0x29], al
// 0056e74d  884c242a             mov byte ptr [esp + 0x2a], cl
// 0056e751  e8aa65ffff           call 0x564d00
// 0056e756  6a03                 push 3
// 0056e758  8d44242c             lea eax, [esp + 0x2c]
// 0056e75c  50                   push eax
// 0056e75d  56                   push esi
// 0056e75e  e87d68ffff           call 0x564fe0
// 0056e763  83c418               add esp, 0x18
// 0056e766  83c703               add edi, 3
// 0056e769  83ed01               sub ebp, 1
// 0056e76c  75c7                 jne 0x56e735
// 0056e76e  5f                   pop edi
// 0056e76f  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056e775  8bd0                 mov edx, eax
// 0056e777  8bc8                 mov ecx, eax
// 0056e779  c1e918               shr ecx, 0x18
// 0056e77c  c1ea10               shr edx, 0x10
// 0056e77f  884c2408             mov byte ptr [esp + 8], cl
// 0056e783  88542409             mov byte ptr [esp + 9], dl
// 0056e787  6a04                 push 4
// 0056e789  8d54240c             lea edx, [esp + 0xc]
// 0056e78d  8bc8                 mov ecx, eax
// 0056e78f  52                   push edx
// 0056e790  c1e908               shr ecx, 8
// 0056e793  56                   push esi
// 0056e794  884c2416             mov byte ptr [esp + 0x16], cl
// 0056e798  88442417             mov byte ptr [esp + 0x17], al
// 0056e79c  e85f65ffff           call 0x564d00
// 0056e7a1  83c40c               add esp, 0xc
// 0056e7a4  834e6802             or dword ptr [esi + 0x68], 2
// 0056e7a8  5e                   pop esi
// 0056e7a9  5d                   pop ebp
// 0056e7aa  83c40c               add esp, 0xc
// 0056e7ad  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
