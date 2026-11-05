// from server: 100% by auto
// roc 2009-12 0060cd80  unit: seg_00600000  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060cd80
//
// 0060cd80  83ec0c               sub esp, 0xc
// 0060cd83  55                   push ebp
// 0060cd84  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0060cd88  56                   push esi
// 0060cd89  8b742418             mov esi, dword ptr [esp + 0x18]
// 0060cd8d  f6863002000001       test byte ptr [esi + 0x230], 1
// 0060cd94  c644240c50           mov byte ptr [esp + 0xc], 0x50
// 0060cd99  c644240d4c           mov byte ptr [esp + 0xd], 0x4c
// 0060cd9e  c644240e54           mov byte ptr [esp + 0xe], 0x54
// 0060cda3  c644240f45           mov byte ptr [esp + 0xf], 0x45
// 0060cda8  c644241000           mov byte ptr [esp + 0x10], 0
// 0060cdad  7504                 jne 0x60cdb3
// 0060cdaf  85ed                 test ebp, ebp
// 0060cdb1  7408                 je 0x60cdbb
// 0060cdb3  81fd00010000         cmp ebp, 0x100
// 0060cdb9  7617                 jbe 0x60cdd2
// 0060cdbb  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 0060cdc2  68045a9c00           push 0x9c5a04
// 0060cdc7  56                   push esi
// 0060cdc8  7517                 jne 0x60cde1
// 0060cdca  e8c1330000           call 0x610190
// 0060cdcf  83c408               add esp, 8
// 0060cdd2  f6862601000002       test byte ptr [esi + 0x126], 2
// 0060cdd9  7514                 jne 0x60cdef
// 0060cddb  68cc599c00           push 0x9c59cc
// 0060cde0  56                   push esi
// 0060cde1  e85a340000           call 0x610240
// 0060cde6  83c408               add esp, 8
// 0060cde9  5e                   pop esi
// 0060cdea  5d                   pop ebp
// 0060cdeb  83c40c               add esp, 0xc
// 0060cdee  c3                   ret 
// 0060cdef  8d446d00             lea eax, [ebp + ebp*2]
// 0060cdf3  50                   push eax
// 0060cdf4  8d4c2410             lea ecx, [esp + 0x10]
// 0060cdf8  51                   push ecx
// 0060cdf9  56                   push esi
// 0060cdfa  6689ae18010000       mov word ptr [esi + 0x118], bp
// 0060ce01  e80afbffff           call 0x60c910
// 0060ce06  83c40c               add esp, 0xc
// 0060ce09  85ed                 test ebp, ebp
// 0060ce0b  7642                 jbe 0x60ce4f
// 0060ce0d  57                   push edi
// 0060ce0e  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0060ce12  83c702               add edi, 2
// 0060ce15  8a57fe               mov dl, byte ptr [edi - 2]
// 0060ce18  8a47ff               mov al, byte ptr [edi - 1]
// 0060ce1b  8a0f                 mov cl, byte ptr [edi]
// 0060ce1d  8854241c             mov byte ptr [esp + 0x1c], dl
// 0060ce21  6a03                 push 3
// 0060ce23  8d542420             lea edx, [esp + 0x20]
// 0060ce27  52                   push edx
// 0060ce28  56                   push esi
// 0060ce29  88442429             mov byte ptr [esp + 0x29], al
// 0060ce2d  884c242a             mov byte ptr [esp + 0x2a], cl
// 0060ce31  e85a65ffff           call 0x603390
// 0060ce36  6a03                 push 3
// 0060ce38  8d44242c             lea eax, [esp + 0x2c]
// 0060ce3c  50                   push eax
// 0060ce3d  56                   push esi
// 0060ce3e  e82d68ffff           call 0x603670
// 0060ce43  83c418               add esp, 0x18
// 0060ce46  83c703               add edi, 3
// 0060ce49  83ed01               sub ebp, 1
// 0060ce4c  75c7                 jne 0x60ce15
// 0060ce4e  5f                   pop edi
// 0060ce4f  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0060ce55  8bd0                 mov edx, eax
// 0060ce57  8bc8                 mov ecx, eax
// 0060ce59  c1e918               shr ecx, 0x18
// 0060ce5c  c1ea10               shr edx, 0x10
// 0060ce5f  884c2408             mov byte ptr [esp + 8], cl
// 0060ce63  88542409             mov byte ptr [esp + 9], dl
// 0060ce67  6a04                 push 4
// 0060ce69  8d54240c             lea edx, [esp + 0xc]
// 0060ce6d  8bc8                 mov ecx, eax
// 0060ce6f  52                   push edx
// 0060ce70  c1e908               shr ecx, 8
// 0060ce73  56                   push esi
// 0060ce74  884c2416             mov byte ptr [esp + 0x16], cl
// 0060ce78  88442417             mov byte ptr [esp + 0x17], al
// 0060ce7c  e80f65ffff           call 0x603390
// 0060ce81  83c40c               add esp, 0xc
// 0060ce84  834e6802             or dword ptr [esi + 0x68], 2
// 0060ce88  5e                   pop esi
// 0060ce89  5d                   pop ebp
// 0060ce8a  83c40c               add esp, 0xc
// 0060ce8d  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
