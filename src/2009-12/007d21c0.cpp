// from server: 100% by auto
// roc 2009-12 007d21c0  unit: seg_007d0000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d21c0
//
// 007d21c0  56                   push esi
// 007d21c1  e86a450000           call 0x7d6730
// 007d21c6  6a00                 push 0
// 007d21c8  57                   push edi
// 007d21c9  56                   push esi
// 007d21ca  e8e10e0000           call 0x7d30b0
// 007d21cf  8b4630               mov eax, dword ptr [esi + 0x30]
// 007d21d2  57                   push edi
// 007d21d3  50                   push eax
// 007d21d4  e807ab0000           call 0x7dcce0
// 007d21d9  83c418               add esp, 0x18
// 007d21dc  837e105d             cmp dword ptr [esi + 0x10], 0x5d
// 007d21e0  7421                 je 0x7d2203
// 007d21e2  6a5d                 push 0x5d
// 007d21e4  56                   push esi
// 007d21e5  e856300000           call 0x7d5240
// 007d21ea  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007d21ed  50                   push eax
// 007d21ee  68d0ed9e00           push 0x9eedd0
// 007d21f3  51                   push ecx
// 007d21f4  e88783fcff           call 0x79a580
// 007d21f9  50                   push eax
// 007d21fa  56                   push esi
// 007d21fb  e840310000           call 0x7d5340
// 007d2200  83c41c               add esp, 0x1c
// 007d2203  56                   push esi
// 007d2204  e827450000           call 0x7d6730
// 007d2209  59                   pop ecx
// 007d220a  c3                   ret 
// library lua-5.1/lparser.c (function _yindex)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
