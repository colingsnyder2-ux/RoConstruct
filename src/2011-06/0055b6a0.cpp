// from server: 100% by auto
// roc 2011-06 0055b6a0  unit: seg_00550000  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055b6a0
//
// 0055b6a0  53                   push ebx
// 0055b6a1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0055b6a5  55                   push ebp
// 0055b6a6  85db                 test ebx, ebx
// 0055b6a8  0f8481000000         je 0x55b72f
// 0055b6ae  56                   push esi
// 0055b6af  8b742414             mov esi, dword ptr [esp + 0x14]
// 0055b6b3  57                   push edi
// 0055b6b4  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0055b6b8  85f6                 test esi, esi
// 0055b6ba  744f                 je 0x55b70b
// 0055b6bc  85ff                 test edi, edi
// 0055b6be  7427                 je 0x55b6e7
// 0055b6c0  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0055b6c4  85ed                 test ebp, ebp
// 0055b6c6  7665                 jbe 0x55b72d
// 0055b6c8  8b0f                 mov ecx, dword ptr [edi]
// 0055b6ca  8b06                 mov eax, dword ptr [esi]
// 0055b6cc  51                   push ecx
// 0055b6cd  50                   push eax
// 0055b6ce  53                   push ebx
// 0055b6cf  83c604               add esi, 4
// 0055b6d2  83c704               add edi, 4
// 0055b6d5  e846fbffff           call 0x55b220
// 0055b6da  83c40c               add esp, 0xc
// 0055b6dd  83ed01               sub ebp, 1
// 0055b6e0  75e6                 jne 0x55b6c8
// 0055b6e2  5f                   pop edi
// 0055b6e3  5e                   pop esi
// 0055b6e4  5d                   pop ebp
// 0055b6e5  5b                   pop ebx
// 0055b6e6  c3                   ret 
// 0055b6e7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0055b6eb  85ff                 test edi, edi
// 0055b6ed  763e                 jbe 0x55b72d
// 0055b6ef  90                   nop 
// 0055b6f0  8b06                 mov eax, dword ptr [esi]
// 0055b6f2  6a00                 push 0
// 0055b6f4  50                   push eax
// 0055b6f5  53                   push ebx
// 0055b6f6  e825fbffff           call 0x55b220
// 0055b6fb  83c40c               add esp, 0xc
// 0055b6fe  83c604               add esi, 4
// 0055b701  83ef01               sub edi, 1
// 0055b704  75ea                 jne 0x55b6f0
// 0055b706  5f                   pop edi
// 0055b707  5e                   pop esi
// 0055b708  5d                   pop ebp
// 0055b709  5b                   pop ebx
// 0055b70a  c3                   ret 
// 0055b70b  85ff                 test edi, edi
// 0055b70d  741e                 je 0x55b72d
// 0055b70f  8b742420             mov esi, dword ptr [esp + 0x20]
// 0055b713  85f6                 test esi, esi
// 0055b715  7616                 jbe 0x55b72d
// 0055b717  8b0f                 mov ecx, dword ptr [edi]
// 0055b719  51                   push ecx
// 0055b71a  6a00                 push 0
// 0055b71c  53                   push ebx
// 0055b71d  e8fefaffff           call 0x55b220
// 0055b722  83c40c               add esp, 0xc
// 0055b725  83c704               add edi, 4
// 0055b728  83ee01               sub esi, 1
// 0055b72b  75ea                 jne 0x55b717
// 0055b72d  5f                   pop edi
// 0055b72e  5e                   pop esi
// 0055b72f  5d                   pop ebp
// 0055b730  5b                   pop ebx
// 0055b731  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_rows)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
