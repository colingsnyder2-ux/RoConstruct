// from server: 100% by auto
// roc 2010-06 00564640  unit: seg_00560000  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00564640
//
// 00564640  53                   push ebx
// 00564641  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00564645  85db                 test ebx, ebx
// 00564647  0f84e1000000         je 0x56472e
// 0056464d  56                   push esi
// 0056464e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00564652  85f6                 test esi, esi
// 00564654  0f84d3000000         je 0x56472d
// 0056465a  8b442414             mov eax, dword ptr [esp + 0x14]
// 0056465e  85c0                 test eax, eax
// 00564660  0f84c7000000         je 0x56472d
// 00564666  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 0056466b  0f84bc000000         je 0x56472d
// 00564671  8d5001               lea edx, [eax + 1]
// 00564674  8a08                 mov cl, byte ptr [eax]
// 00564676  40                   inc eax
// 00564677  84c9                 test cl, cl
// 00564679  75f9                 jne 0x564674
// 0056467b  55                   push ebp
// 0056467c  2bc2                 sub eax, edx
// 0056467e  57                   push edi
// 0056467f  8d6801               lea ebp, [eax + 1]
// 00564682  55                   push ebp
// 00564683  53                   push ebx
// 00564684  e8a7df0000           call 0x572630
// 00564689  8bf8                 mov edi, eax
// 0056468b  83c408               add esp, 8
// 0056468e  85ff                 test edi, edi
// 00564690  7513                 jne 0x5646a5
// 00564692  682014a200           push 0xa21420
// 00564697  53                   push ebx
// 00564698  e8c3d40000           call 0x571b60
// 0056469d  83c408               add esp, 8
// 005646a0  5f                   pop edi
// 005646a1  5d                   pop ebp
// 005646a2  5e                   pop esi
// 005646a3  5b                   pop ebx
// 005646a4  c3                   ret 
// 005646a5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005646a9  55                   push ebp
// 005646aa  50                   push eax
// 005646ab  57                   push edi
// 005646ac  e875472400           call 0x7a8e26
// 005646b1  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 005646b5  55                   push ebp
// 005646b6  53                   push ebx
// 005646b7  e874df0000           call 0x572630
// 005646bc  8bd8                 mov ebx, eax
// 005646be  83c414               add esp, 0x14
// 005646c1  85db                 test ebx, ebx
// 005646c3  751e                 jne 0x5646e3
// 005646c5  8b742414             mov esi, dword ptr [esp + 0x14]
// 005646c9  57                   push edi
// 005646ca  56                   push esi
// 005646cb  e830df0000           call 0x572600
// 005646d0  68f013a200           push 0xa213f0
// 005646d5  56                   push esi
// 005646d6  e885d40000           call 0x571b60
// 005646db  83c410               add esp, 0x10
// 005646de  5f                   pop edi
// 005646df  5d                   pop ebp
// 005646e0  5e                   pop esi
// 005646e1  5b                   pop ebx
// 005646e2  c3                   ret 
// 005646e3  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005646e7  55                   push ebp
// 005646e8  51                   push ecx
// 005646e9  53                   push ebx
// 005646ea  e837472400           call 0x7a8e26
// 005646ef  8b542420             mov edx, dword ptr [esp + 0x20]
// 005646f3  6a00                 push 0
// 005646f5  6a10                 push 0x10
// 005646f7  56                   push esi
// 005646f8  52                   push edx
// 005646f9  e832090000           call 0x565030
// 005646fe  8a44243c             mov al, byte ptr [esp + 0x3c]
// 00564702  838eb800000010       or dword ptr [esi + 0xb8], 0x10
// 00564709  83c41c               add esp, 0x1c
// 0056470c  814e0800100000       or dword ptr [esi + 8], 0x1000
// 00564713  89bec4000000         mov dword ptr [esi + 0xc4], edi
// 00564719  5f                   pop edi
// 0056471a  89aecc000000         mov dword ptr [esi + 0xcc], ebp
// 00564720  899ec8000000         mov dword ptr [esi + 0xc8], ebx
// 00564726  8886d0000000         mov byte ptr [esi + 0xd0], al
// 0056472c  5d                   pop ebp
// 0056472d  5e                   pop esi
// 0056472e  5b                   pop ebx
// 0056472f  c3                   ret 
// library libpng-1.2.24/pngset.c (function _png_set_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngset.c
