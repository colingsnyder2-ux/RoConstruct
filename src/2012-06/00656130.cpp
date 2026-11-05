// from server: 100% by auto
// roc 2012-06 00656130  unit: seg_00650000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00656130
//
// 00656130  53                   push ebx
// 00656131  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00656135  85db                 test ebx, ebx
// 00656137  7427                 je 0x656160
// 00656139  57                   push edi
// 0065613a  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0065613e  85ff                 test edi, edi
// 00656140  741d                 je 0x65615f
// 00656142  56                   push esi
// 00656143  8b742418             mov esi, dword ptr [esp + 0x18]
// 00656147  85f6                 test esi, esi
// 00656149  7613                 jbe 0x65615e
// 0065614b  56                   push esi
// 0065614c  57                   push edi
// 0065614d  53                   push ebx
// 0065614e  e86d15ffff           call 0x6476c0
// 00656153  56                   push esi
// 00656154  57                   push edi
// 00656155  53                   push ebx
// 00656156  e8357dfeff           call 0x63de90
// 0065615b  83c418               add esp, 0x18
// 0065615e  5e                   pop esi
// 0065615f  5f                   pop edi
// 00656160  5b                   pop ebx
// 00656161  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk_data)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
