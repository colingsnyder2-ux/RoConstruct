// from server: 100% by auto
// roc 2011-06 0055a8e0  unit: seg_00550000  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055a8e0
//
// 0055a8e0  56                   push esi
// 0055a8e1  8b742408             mov esi, dword ptr [esp + 8]
// 0055a8e5  85f6                 test esi, esi
// 0055a8e7  745b                 je 0x55a944
// 0055a8e9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0055a8ed  894654               mov dword ptr [esi + 0x54], eax
// 0055a8f0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0055a8f4  85c0                 test eax, eax
// 0055a8f6  7405                 je 0x55a8fd
// 0055a8f8  89464c               mov dword ptr [esi + 0x4c], eax
// 0055a8fb  eb07                 jmp 0x55a904
// 0055a8fd  c7464c60a85500       mov dword ptr [esi + 0x4c], 0x55a860
// 0055a904  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055a908  85c0                 test eax, eax
// 0055a90a  7408                 je 0x55a914
// 0055a90c  89864c010000         mov dword ptr [esi + 0x14c], eax
// 0055a912  eb0a                 jmp 0x55a91e
// 0055a914  c7864c010000c0a85500 mov dword ptr [esi + 0x14c], 0x55a8c0
// 0055a91e  837e5000             cmp dword ptr [esi + 0x50], 0
// 0055a922  7420                 je 0x55a944
// 0055a924  68f025a800           push 0xa825f0
// 0055a929  56                   push esi
// 0055a92a  c7465000000000       mov dword ptr [esi + 0x50], 0
// 0055a931  e8aa6a0000           call 0x5613e0
// 0055a936  68b825a800           push 0xa825b8
// 0055a93b  56                   push esi
// 0055a93c  e89f6a0000           call 0x5613e0
// 0055a941  83c410               add esp, 0x10
// 0055a944  5e                   pop esi
// 0055a945  c3                   ret 
// library libpng-1.2.16/pngwio.c (function _png_set_write_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwio.c
