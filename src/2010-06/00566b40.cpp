// from server: 100% by auto
// roc 2010-06 00566b40  unit: seg_00560000  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00566b40
//
// 00566b40  53                   push ebx
// 00566b41  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00566b45  55                   push ebp
// 00566b46  85db                 test ebx, ebx
// 00566b48  0f8481000000         je 0x566bcf
// 00566b4e  56                   push esi
// 00566b4f  8b742414             mov esi, dword ptr [esp + 0x14]
// 00566b53  57                   push edi
// 00566b54  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00566b58  85f6                 test esi, esi
// 00566b5a  744f                 je 0x566bab
// 00566b5c  85ff                 test edi, edi
// 00566b5e  7427                 je 0x566b87
// 00566b60  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00566b64  85ed                 test ebp, ebp
// 00566b66  7665                 jbe 0x566bcd
// 00566b68  8b0f                 mov ecx, dword ptr [edi]
// 00566b6a  8b06                 mov eax, dword ptr [esi]
// 00566b6c  51                   push ecx
// 00566b6d  50                   push eax
// 00566b6e  53                   push ebx
// 00566b6f  83c604               add esi, 4
// 00566b72  83c704               add edi, 4
// 00566b75  e846fbffff           call 0x5666c0
// 00566b7a  83c40c               add esp, 0xc
// 00566b7d  83ed01               sub ebp, 1
// 00566b80  75e6                 jne 0x566b68
// 00566b82  5f                   pop edi
// 00566b83  5e                   pop esi
// 00566b84  5d                   pop ebp
// 00566b85  5b                   pop ebx
// 00566b86  c3                   ret 
// 00566b87  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00566b8b  85ff                 test edi, edi
// 00566b8d  763e                 jbe 0x566bcd
// 00566b8f  90                   nop 
// 00566b90  8b06                 mov eax, dword ptr [esi]
// 00566b92  6a00                 push 0
// 00566b94  50                   push eax
// 00566b95  53                   push ebx
// 00566b96  e825fbffff           call 0x5666c0
// 00566b9b  83c40c               add esp, 0xc
// 00566b9e  83c604               add esi, 4
// 00566ba1  83ef01               sub edi, 1
// 00566ba4  75ea                 jne 0x566b90
// 00566ba6  5f                   pop edi
// 00566ba7  5e                   pop esi
// 00566ba8  5d                   pop ebp
// 00566ba9  5b                   pop ebx
// 00566baa  c3                   ret 
// 00566bab  85ff                 test edi, edi
// 00566bad  741e                 je 0x566bcd
// 00566baf  8b742420             mov esi, dword ptr [esp + 0x20]
// 00566bb3  85f6                 test esi, esi
// 00566bb5  7616                 jbe 0x566bcd
// 00566bb7  8b0f                 mov ecx, dword ptr [edi]
// 00566bb9  51                   push ecx
// 00566bba  6a00                 push 0
// 00566bbc  53                   push ebx
// 00566bbd  e8fefaffff           call 0x5666c0
// 00566bc2  83c40c               add esp, 0xc
// 00566bc5  83c704               add edi, 4
// 00566bc8  83ee01               sub esi, 1
// 00566bcb  75ea                 jne 0x566bb7
// 00566bcd  5f                   pop edi
// 00566bce  5e                   pop esi
// 00566bcf  5d                   pop ebp
// 00566bd0  5b                   pop ebx
// 00566bd1  c3                   ret 
// library libpng-1.2.16/pngread.c (function _png_read_rows)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngread.c
