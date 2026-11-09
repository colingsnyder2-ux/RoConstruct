// from server: 100% by auto
// roc 2012-06 00648520  unit: seg_00640000  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00648520
//
// 00648520  53                   push ebx
// 00648521  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00648525  55                   push ebp
// 00648526  85db                 test ebx, ebx
// 00648528  0f8481000000         je 0x6485af
// 0064852e  56                   push esi
// 0064852f  8b742414             mov esi, dword ptr [esp + 0x14]
// 00648533  57                   push edi
// 00648534  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00648538  85f6                 test esi, esi
// 0064853a  744f                 je 0x64858b
// 0064853c  85ff                 test edi, edi
// 0064853e  7427                 je 0x648567
// 00648540  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00648544  85ed                 test ebp, ebp
// 00648546  7665                 jbe 0x6485ad
// 00648548  8b0f                 mov ecx, dword ptr [edi]
// 0064854a  8b06                 mov eax, dword ptr [esi]
// 0064854c  51                   push ecx
// 0064854d  50                   push eax
// 0064854e  53                   push ebx
// 0064854f  83c604               add esi, 4
// 00648552  83c704               add edi, 4
// 00648555  e846fbffff           call 0x6480a0
// 0064855a  83c40c               add esp, 0xc
// 0064855d  83ed01               sub ebp, 1
// 00648560  75e6                 jne 0x648548
// 00648562  5f                   pop edi
// 00648563  5e                   pop esi
// 00648564  5d                   pop ebp
// 00648565  5b                   pop ebx
// 00648566  c3                   ret 
// 00648567  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0064856b  85ff                 test edi, edi
// 0064856d  763e                 jbe 0x6485ad
// 0064856f  90                   nop 
// 00648570  8b06                 mov eax, dword ptr [esi]
// 00648572  6a00                 push 0
// 00648574  50                   push eax
// 00648575  53                   push ebx
// 00648576  e825fbffff           call 0x6480a0
// 0064857b  83c40c               add esp, 0xc
// 0064857e  83c604               add esi, 4
// 00648581  83ef01               sub edi, 1
// 00648584  75ea                 jne 0x648570
// 00648586  5f                   pop edi
// 00648587  5e                   pop esi
// 00648588  5d                   pop ebp
// 00648589  5b                   pop ebx
// 0064858a  c3                   ret 
// 0064858b  85ff                 test edi, edi
// 0064858d  741e                 je 0x6485ad
// 0064858f  8b742420             mov esi, dword ptr [esp + 0x20]
// 00648593  85f6                 test esi, esi
// 00648595  7616                 jbe 0x6485ad
// 00648597  8b0f                 mov ecx, dword ptr [edi]
// 00648599  51                   push ecx
// 0064859a  6a00                 push 0
// 0064859c  53                   push ebx
// 0064859d  e8fefaffff           call 0x6480a0
// 006485a2  83c40c               add esp, 0xc
// 006485a5  83c704               add edi, 4
// 006485a8  83ee01               sub esi, 1
// 006485ab  75ea                 jne 0x648597
// 006485ad  5f                   pop edi
// 006485ae  5e                   pop esi
// 006485af  5d                   pop ebp
// 006485b0  5b                   pop ebx
// 006485b1  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_rows)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
