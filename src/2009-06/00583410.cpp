// from server: 100% by auto
// roc 2009-06 00583410  unit: seg_00580000  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00583410
//
// 00583410  53                   push ebx
// 00583411  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00583415  55                   push ebp
// 00583416  85db                 test ebx, ebx
// 00583418  0f8481000000         je 0x58349f
// 0058341e  56                   push esi
// 0058341f  8b742414             mov esi, dword ptr [esp + 0x14]
// 00583423  57                   push edi
// 00583424  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00583428  85f6                 test esi, esi
// 0058342a  744f                 je 0x58347b
// 0058342c  85ff                 test edi, edi
// 0058342e  7427                 je 0x583457
// 00583430  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00583434  85ed                 test ebp, ebp
// 00583436  7665                 jbe 0x58349d
// 00583438  8b0f                 mov ecx, dword ptr [edi]
// 0058343a  8b06                 mov eax, dword ptr [esi]
// 0058343c  51                   push ecx
// 0058343d  50                   push eax
// 0058343e  53                   push ebx
// 0058343f  83c604               add esi, 4
// 00583442  83c704               add edi, 4
// 00583445  e846fbffff           call 0x582f90
// 0058344a  83c40c               add esp, 0xc
// 0058344d  83ed01               sub ebp, 1
// 00583450  75e6                 jne 0x583438
// 00583452  5f                   pop edi
// 00583453  5e                   pop esi
// 00583454  5d                   pop ebp
// 00583455  5b                   pop ebx
// 00583456  c3                   ret 
// 00583457  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0058345b  85ff                 test edi, edi
// 0058345d  763e                 jbe 0x58349d
// 0058345f  90                   nop 
// 00583460  8b06                 mov eax, dword ptr [esi]
// 00583462  6a00                 push 0
// 00583464  50                   push eax
// 00583465  53                   push ebx
// 00583466  e825fbffff           call 0x582f90
// 0058346b  83c40c               add esp, 0xc
// 0058346e  83c604               add esi, 4
// 00583471  83ef01               sub edi, 1
// 00583474  75ea                 jne 0x583460
// 00583476  5f                   pop edi
// 00583477  5e                   pop esi
// 00583478  5d                   pop ebp
// 00583479  5b                   pop ebx
// 0058347a  c3                   ret 
// 0058347b  85ff                 test edi, edi
// 0058347d  741e                 je 0x58349d
// 0058347f  8b742420             mov esi, dword ptr [esp + 0x20]
// 00583483  85f6                 test esi, esi
// 00583485  7616                 jbe 0x58349d
// 00583487  8b0f                 mov ecx, dword ptr [edi]
// 00583489  51                   push ecx
// 0058348a  6a00                 push 0
// 0058348c  53                   push ebx
// 0058348d  e8fefaffff           call 0x582f90
// 00583492  83c40c               add esp, 0xc
// 00583495  83c704               add edi, 4
// 00583498  83ee01               sub esi, 1
// 0058349b  75ea                 jne 0x583487
// 0058349d  5f                   pop edi
// 0058349e  5e                   pop esi
// 0058349f  5d                   pop ebp
// 005834a0  5b                   pop ebx
// 005834a1  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_rows)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
