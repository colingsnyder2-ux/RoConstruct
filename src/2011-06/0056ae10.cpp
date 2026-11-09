// from server: 100% by auto
// roc 2011-06 0056ae10  unit: seg_00560000  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056ae10
//
// 0056ae10  83ec0c               sub esp, 0xc
// 0056ae13  55                   push ebp
// 0056ae14  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0056ae18  56                   push esi
// 0056ae19  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056ae1d  f6863002000001       test byte ptr [esi + 0x230], 1
// 0056ae24  c644240c50           mov byte ptr [esp + 0xc], 0x50
// 0056ae29  c644240d4c           mov byte ptr [esp + 0xd], 0x4c
// 0056ae2e  c644240e54           mov byte ptr [esp + 0xe], 0x54
// 0056ae33  c644240f45           mov byte ptr [esp + 0xf], 0x45
// 0056ae38  c644241000           mov byte ptr [esp + 0x10], 0
// 0056ae3d  7504                 jne 0x56ae43
// 0056ae3f  85ed                 test ebp, ebp
// 0056ae41  7408                 je 0x56ae4b
// 0056ae43  81fd00010000         cmp ebp, 0x100
// 0056ae49  7617                 jbe 0x56ae62
// 0056ae4b  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 0056ae52  68345ba800           push 0xa85b34
// 0056ae57  56                   push esi
// 0056ae58  7517                 jne 0x56ae71
// 0056ae5a  e8d164ffff           call 0x561330
// 0056ae5f  83c408               add esp, 8
// 0056ae62  f6862601000002       test byte ptr [esi + 0x126], 2
// 0056ae69  7514                 jne 0x56ae7f
// 0056ae6b  68fc5aa800           push 0xa85afc
// 0056ae70  56                   push esi
// 0056ae71  e86a65ffff           call 0x5613e0
// 0056ae76  83c408               add esp, 8
// 0056ae79  5e                   pop esi
// 0056ae7a  5d                   pop ebp
// 0056ae7b  83c40c               add esp, 0xc
// 0056ae7e  c3                   ret 
// 0056ae7f  8d446d00             lea eax, [ebp + ebp*2]
// 0056ae83  50                   push eax
// 0056ae84  8d4c2410             lea ecx, [esp + 0x10]
// 0056ae88  51                   push ecx
// 0056ae89  56                   push esi
// 0056ae8a  6689ae18010000       mov word ptr [esi + 0x118], bp
// 0056ae91  e81afbffff           call 0x56a9b0
// 0056ae96  83c40c               add esp, 0xc
// 0056ae99  85ed                 test ebp, ebp
// 0056ae9b  7642                 jbe 0x56aedf
// 0056ae9d  57                   push edi
// 0056ae9e  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0056aea2  83c702               add edi, 2
// 0056aea5  8a57fe               mov dl, byte ptr [edi - 2]
// 0056aea8  8a47ff               mov al, byte ptr [edi - 1]
// 0056aeab  8a0f                 mov cl, byte ptr [edi]
// 0056aead  8854241c             mov byte ptr [esp + 0x1c], dl
// 0056aeb1  6a03                 push 3
// 0056aeb3  8d542420             lea edx, [esp + 0x20]
// 0056aeb7  52                   push edx
// 0056aeb8  56                   push esi
// 0056aeb9  88442429             mov byte ptr [esp + 0x29], al
// 0056aebd  884c242a             mov byte ptr [esp + 0x2a], cl
// 0056aec1  e87af9feff           call 0x55a840
// 0056aec6  6a03                 push 3
// 0056aec8  8d44242c             lea eax, [esp + 0x2c]
// 0056aecc  50                   push eax
// 0056aecd  56                   push esi
// 0056aece  e87d59feff           call 0x550850
// 0056aed3  83c418               add esp, 0x18
// 0056aed6  83c703               add edi, 3
// 0056aed9  83ed01               sub ebp, 1
// 0056aedc  75c7                 jne 0x56aea5
// 0056aede  5f                   pop edi
// 0056aedf  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056aee5  8bd0                 mov edx, eax
// 0056aee7  8bc8                 mov ecx, eax
// 0056aee9  c1e918               shr ecx, 0x18
// 0056aeec  c1ea10               shr edx, 0x10
// 0056aeef  884c2408             mov byte ptr [esp + 8], cl
// 0056aef3  88542409             mov byte ptr [esp + 9], dl
// 0056aef7  6a04                 push 4
// 0056aef9  8d54240c             lea edx, [esp + 0xc]
// 0056aefd  8bc8                 mov ecx, eax
// 0056aeff  52                   push edx
// 0056af00  c1e908               shr ecx, 8
// 0056af03  56                   push esi
// 0056af04  884c2416             mov byte ptr [esp + 0x16], cl
// 0056af08  88442417             mov byte ptr [esp + 0x17], al
// 0056af0c  e82ff9feff           call 0x55a840
// 0056af11  83c40c               add esp, 0xc
// 0056af14  834e6802             or dword ptr [esi + 0x68], 2
// 0056af18  5e                   pop esi
// 0056af19  5d                   pop ebp
// 0056af1a  83c40c               add esp, 0xc
// 0056af1d  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
