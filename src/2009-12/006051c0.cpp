// from server: 100% by auto
// roc 2009-12 006051c0  unit: seg_00600000  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006051c0
//
// 006051c0  53                   push ebx
// 006051c1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 006051c5  55                   push ebp
// 006051c6  85db                 test ebx, ebx
// 006051c8  0f8481000000         je 0x60524f
// 006051ce  56                   push esi
// 006051cf  8b742414             mov esi, dword ptr [esp + 0x14]
// 006051d3  57                   push edi
// 006051d4  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006051d8  85f6                 test esi, esi
// 006051da  744f                 je 0x60522b
// 006051dc  85ff                 test edi, edi
// 006051de  7427                 je 0x605207
// 006051e0  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 006051e4  85ed                 test ebp, ebp
// 006051e6  7665                 jbe 0x60524d
// 006051e8  8b0f                 mov ecx, dword ptr [edi]
// 006051ea  8b06                 mov eax, dword ptr [esi]
// 006051ec  51                   push ecx
// 006051ed  50                   push eax
// 006051ee  53                   push ebx
// 006051ef  83c604               add esi, 4
// 006051f2  83c704               add edi, 4
// 006051f5  e846fbffff           call 0x604d40
// 006051fa  83c40c               add esp, 0xc
// 006051fd  83ed01               sub ebp, 1
// 00605200  75e6                 jne 0x6051e8
// 00605202  5f                   pop edi
// 00605203  5e                   pop esi
// 00605204  5d                   pop ebp
// 00605205  5b                   pop ebx
// 00605206  c3                   ret 
// 00605207  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0060520b  85ff                 test edi, edi
// 0060520d  763e                 jbe 0x60524d
// 0060520f  90                   nop 
// 00605210  8b06                 mov eax, dword ptr [esi]
// 00605212  6a00                 push 0
// 00605214  50                   push eax
// 00605215  53                   push ebx
// 00605216  e825fbffff           call 0x604d40
// 0060521b  83c40c               add esp, 0xc
// 0060521e  83c604               add esi, 4
// 00605221  83ef01               sub edi, 1
// 00605224  75ea                 jne 0x605210
// 00605226  5f                   pop edi
// 00605227  5e                   pop esi
// 00605228  5d                   pop ebp
// 00605229  5b                   pop ebx
// 0060522a  c3                   ret 
// 0060522b  85ff                 test edi, edi
// 0060522d  741e                 je 0x60524d
// 0060522f  8b742420             mov esi, dword ptr [esp + 0x20]
// 00605233  85f6                 test esi, esi
// 00605235  7616                 jbe 0x60524d
// 00605237  8b0f                 mov ecx, dword ptr [edi]
// 00605239  51                   push ecx
// 0060523a  6a00                 push 0
// 0060523c  53                   push ebx
// 0060523d  e8fefaffff           call 0x604d40
// 00605242  83c40c               add esp, 0xc
// 00605245  83c704               add edi, 4
// 00605248  83ee01               sub esi, 1
// 0060524b  75ea                 jne 0x605237
// 0060524d  5f                   pop edi
// 0060524e  5e                   pop esi
// 0060524f  5d                   pop ebp
// 00605250  5b                   pop ebx
// 00605251  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_rows)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
