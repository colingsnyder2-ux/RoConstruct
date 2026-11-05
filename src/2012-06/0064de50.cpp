// from server: 100% by auto
// roc 2012-06 0064de50  unit: seg_00640000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0064de50
//
// 0064de50  56                   push esi
// 0064de51  8b742408             mov esi, dword ptr [esp + 8]
// 0064de55  85f6                 test esi, esi
// 0064de57  744b                 je 0x64dea4
// 0064de59  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0064de5d  894654               mov dword ptr [esi + 0x54], eax
// 0064de60  8b442410             mov eax, dword ptr [esp + 0x10]
// 0064de64  85c0                 test eax, eax
// 0064de66  7405                 je 0x64de6d
// 0064de68  894650               mov dword ptr [esi + 0x50], eax
// 0064de6b  eb07                 jmp 0x64de74
// 0064de6d  c7465010de6400       mov dword ptr [esi + 0x50], 0x64de10
// 0064de74  837e4c00             cmp dword ptr [esi + 0x4c], 0
// 0064de78  7420                 je 0x64de9a
// 0064de7a  68306bb800           push 0xb86b30
// 0064de7f  56                   push esi
// 0064de80  c7464c00000000       mov dword ptr [esi + 0x4c], 0
// 0064de87  e8d4030000           call 0x64e260
// 0064de8c  68fc6ab800           push 0xb86afc
// 0064de91  56                   push esi
// 0064de92  e8c9030000           call 0x64e260
// 0064de97  83c410               add esp, 0x10
// 0064de9a  c7864c01000000000000 mov dword ptr [esi + 0x14c], 0
// 0064dea4  5e                   pop esi
// 0064dea5  c3                   ret 
// library libpng-1.2.16/pngrio.c (function _png_set_read_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrio.c
