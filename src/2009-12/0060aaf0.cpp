// from server: 100% by auto
// roc 2009-12 0060aaf0  unit: seg_00600000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060aaf0
//
// 0060aaf0  56                   push esi
// 0060aaf1  8b742408             mov esi, dword ptr [esp + 8]
// 0060aaf5  85f6                 test esi, esi
// 0060aaf7  744b                 je 0x60ab44
// 0060aaf9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0060aafd  894654               mov dword ptr [esi + 0x54], eax
// 0060ab00  8b442410             mov eax, dword ptr [esp + 0x10]
// 0060ab04  85c0                 test eax, eax
// 0060ab06  7405                 je 0x60ab0d
// 0060ab08  894650               mov dword ptr [esi + 0x50], eax
// 0060ab0b  eb07                 jmp 0x60ab14
// 0060ab0d  c74650b0aa6000       mov dword ptr [esi + 0x50], 0x60aab0
// 0060ab14  837e4c00             cmp dword ptr [esi + 0x4c], 0
// 0060ab18  7420                 je 0x60ab3a
// 0060ab1a  6890539c00           push 0x9c5390
// 0060ab1f  56                   push esi
// 0060ab20  c7464c00000000       mov dword ptr [esi + 0x4c], 0
// 0060ab27  e814570000           call 0x610240
// 0060ab2c  685c539c00           push 0x9c535c
// 0060ab31  56                   push esi
// 0060ab32  e809570000           call 0x610240
// 0060ab37  83c410               add esp, 0x10
// 0060ab3a  c7864c01000000000000 mov dword ptr [esi + 0x14c], 0
// 0060ab44  5e                   pop esi
// 0060ab45  c3                   ret 
// library libpng-1.2.16/pngrio.c (function _png_set_read_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrio.c
