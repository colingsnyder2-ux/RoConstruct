// from server: 100% by auto
// roc 2012-06 00647760  unit: seg_00640000  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00647760
//
// 00647760  56                   push esi
// 00647761  8b742408             mov esi, dword ptr [esp + 8]
// 00647765  85f6                 test esi, esi
// 00647767  745b                 je 0x6477c4
// 00647769  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0064776d  894654               mov dword ptr [esi + 0x54], eax
// 00647770  8b442410             mov eax, dword ptr [esp + 0x10]
// 00647774  85c0                 test eax, eax
// 00647776  7405                 je 0x64777d
// 00647778  89464c               mov dword ptr [esi + 0x4c], eax
// 0064777b  eb07                 jmp 0x647784
// 0064777d  c7464ce0766400       mov dword ptr [esi + 0x4c], 0x6476e0
// 00647784  8b442414             mov eax, dword ptr [esp + 0x14]
// 00647788  85c0                 test eax, eax
// 0064778a  7408                 je 0x647794
// 0064778c  89864c010000         mov dword ptr [esi + 0x14c], eax
// 00647792  eb0a                 jmp 0x64779e
// 00647794  c7864c01000040776400 mov dword ptr [esi + 0x14c], 0x647740
// 0064779e  837e5000             cmp dword ptr [esi + 0x50], 0
// 006477a2  7420                 je 0x6477c4
// 006477a4  68a064b800           push 0xb864a0
// 006477a9  56                   push esi
// 006477aa  c7465000000000       mov dword ptr [esi + 0x50], 0
// 006477b1  e8aa6a0000           call 0x64e260
// 006477b6  686864b800           push 0xb86468
// 006477bb  56                   push esi
// 006477bc  e89f6a0000           call 0x64e260
// 006477c1  83c410               add esp, 0x10
// 006477c4  5e                   pop esi
// 006477c5  c3                   ret 
// library libpng-1.2.16/pngwio.c (function _png_set_write_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwio.c
