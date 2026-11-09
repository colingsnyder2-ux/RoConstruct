// from server: 100% by auto
// roc 2009-06 0058a930  unit: seg_00580000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058a930
//
// 0058a930  53                   push ebx
// 0058a931  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0058a935  85db                 test ebx, ebx
// 0058a937  7427                 je 0x58a960
// 0058a939  57                   push edi
// 0058a93a  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0058a93e  85ff                 test edi, edi
// 0058a940  741d                 je 0x58a95f
// 0058a942  56                   push esi
// 0058a943  8b742418             mov esi, dword ptr [esp + 0x18]
// 0058a947  85f6                 test esi, esi
// 0058a949  7613                 jbe 0x58a95e
// 0058a94b  56                   push esi
// 0058a94c  57                   push edi
// 0058a94d  53                   push ebx
// 0058a94e  e88d6cffff           call 0x5815e0
// 0058a953  56                   push esi
// 0058a954  57                   push edi
// 0058a955  53                   push ebx
// 0058a956  e8656fffff           call 0x5818c0
// 0058a95b  83c418               add esp, 0x18
// 0058a95e  5e                   pop esi
// 0058a95f  5f                   pop edi
// 0058a960  5b                   pop ebx
// 0058a961  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk_data)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
