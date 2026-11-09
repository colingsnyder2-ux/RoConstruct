// from server: 100% by auto
// roc 2010-06 0056e2a0  unit: G3D::LineSegment  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056e2a0
//
// 0056e2a0  53                   push ebx
// 0056e2a1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0056e2a5  85db                 test ebx, ebx
// 0056e2a7  7427                 je 0x56e2d0
// 0056e2a9  57                   push edi
// 0056e2aa  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0056e2ae  85ff                 test edi, edi
// 0056e2b0  741d                 je 0x56e2cf
// 0056e2b2  56                   push esi
// 0056e2b3  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056e2b7  85f6                 test esi, esi
// 0056e2b9  7613                 jbe 0x56e2ce
// 0056e2bb  56                   push esi
// 0056e2bc  57                   push edi
// 0056e2bd  53                   push ebx
// 0056e2be  e83d6affff           call 0x564d00
// 0056e2c3  56                   push esi
// 0056e2c4  57                   push edi
// 0056e2c5  53                   push ebx
// 0056e2c6  e8156dffff           call 0x564fe0
// 0056e2cb  83c418               add esp, 0x18
// 0056e2ce  5e                   pop esi
// 0056e2cf  5f                   pop edi
// 0056e2d0  5b                   pop ebx
// 0056e2d1  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk_data)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
