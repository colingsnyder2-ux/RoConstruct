// from server: 100% by auto
// roc 2011-06 0056aa20  unit: seg_00560000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056aa20
//
// 0056aa20  53                   push ebx
// 0056aa21  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0056aa25  85db                 test ebx, ebx
// 0056aa27  7427                 je 0x56aa50
// 0056aa29  57                   push edi
// 0056aa2a  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0056aa2e  85ff                 test edi, edi
// 0056aa30  741d                 je 0x56aa4f
// 0056aa32  56                   push esi
// 0056aa33  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056aa37  85f6                 test esi, esi
// 0056aa39  7613                 jbe 0x56aa4e
// 0056aa3b  56                   push esi
// 0056aa3c  57                   push edi
// 0056aa3d  53                   push ebx
// 0056aa3e  e8fdfdfeff           call 0x55a840
// 0056aa43  56                   push esi
// 0056aa44  57                   push edi
// 0056aa45  53                   push ebx
// 0056aa46  e8055efeff           call 0x550850
// 0056aa4b  83c418               add esp, 0x18
// 0056aa4e  5e                   pop esi
// 0056aa4f  5f                   pop edi
// 0056aa50  5b                   pop ebx
// 0056aa51  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk_data)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
