// from server: 100% by auto
// roc 2009-12 0060c980  unit: seg_00600000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060c980
//
// 0060c980  53                   push ebx
// 0060c981  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0060c985  85db                 test ebx, ebx
// 0060c987  7427                 je 0x60c9b0
// 0060c989  57                   push edi
// 0060c98a  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0060c98e  85ff                 test edi, edi
// 0060c990  741d                 je 0x60c9af
// 0060c992  56                   push esi
// 0060c993  8b742418             mov esi, dword ptr [esp + 0x18]
// 0060c997  85f6                 test esi, esi
// 0060c999  7613                 jbe 0x60c9ae
// 0060c99b  56                   push esi
// 0060c99c  57                   push edi
// 0060c99d  53                   push ebx
// 0060c99e  e8ed69ffff           call 0x603390
// 0060c9a3  56                   push esi
// 0060c9a4  57                   push edi
// 0060c9a5  53                   push ebx
// 0060c9a6  e8c56cffff           call 0x603670
// 0060c9ab  83c418               add esp, 0x18
// 0060c9ae  5e                   pop esi
// 0060c9af  5f                   pop edi
// 0060c9b0  5b                   pop ebx
// 0060c9b1  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk_data)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
