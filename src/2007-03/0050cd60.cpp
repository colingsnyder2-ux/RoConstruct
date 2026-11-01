// from server: 100% by auto
// roc 2007-03 0050cd60  unit: seg_00500000  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050cd60
//
// 0050cd60  53                   push ebx
// 0050cd61  56                   push esi
// 0050cd62  8b742410             mov esi, dword ptr [esp + 0x10]
// 0050cd66  85f6                 test esi, esi
// 0050cd68  57                   push edi
// 0050cd69  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0050cd6d  745b                 je 0x50cdca
// 0050cd6f  85ff                 test edi, edi
// 0050cd71  742c                 je 0x50cd9f
// 0050cd73  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0050cd77  85db                 test ebx, ebx
// 0050cd79  767b                 jbe 0x50cdf6
// 0050cd7b  55                   push ebp
// 0050cd7c  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0050cd80  8b0f                 mov ecx, dword ptr [edi]
// 0050cd82  8b06                 mov eax, dword ptr [esi]
// 0050cd84  51                   push ecx
// 0050cd85  50                   push eax
// 0050cd86  55                   push ebp
// 0050cd87  83c604               add esi, 4
// 0050cd8a  83c704               add edi, 4
// 0050cd8d  e8cefaffff           call 0x50c860
// 0050cd92  83c40c               add esp, 0xc
// 0050cd95  83eb01               sub ebx, 1
// 0050cd98  75e6                 jne 0x50cd80
// 0050cd9a  5d                   pop ebp
// 0050cd9b  5f                   pop edi
// 0050cd9c  5e                   pop esi
// 0050cd9d  5b                   pop ebx
// 0050cd9e  c3                   ret 
// 0050cd9f  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0050cda3  85ff                 test edi, edi
// 0050cda5  764f                 jbe 0x50cdf6
// 0050cda7  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0050cdab  eb03                 jmp 0x50cdb0
// 0050cdad  8d4900               lea ecx, [ecx]
// 0050cdb0  8b06                 mov eax, dword ptr [esi]
// 0050cdb2  6a00                 push 0
// 0050cdb4  50                   push eax
// 0050cdb5  53                   push ebx
// 0050cdb6  e8a5faffff           call 0x50c860
// 0050cdbb  83c40c               add esp, 0xc
// 0050cdbe  83c604               add esi, 4
// 0050cdc1  83ef01               sub edi, 1
// 0050cdc4  75ea                 jne 0x50cdb0
// 0050cdc6  5f                   pop edi
// 0050cdc7  5e                   pop esi
// 0050cdc8  5b                   pop ebx
// 0050cdc9  c3                   ret 
// 0050cdca  85ff                 test edi, edi
// 0050cdcc  7428                 je 0x50cdf6
// 0050cdce  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0050cdd2  85f6                 test esi, esi
// 0050cdd4  7620                 jbe 0x50cdf6
// 0050cdd6  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0050cdda  8d9b00000000         lea ebx, [ebx]
// 0050cde0  8b0f                 mov ecx, dword ptr [edi]
// 0050cde2  51                   push ecx
// 0050cde3  6a00                 push 0
// 0050cde5  53                   push ebx
// 0050cde6  e875faffff           call 0x50c860
// 0050cdeb  83c40c               add esp, 0xc
// 0050cdee  83c704               add edi, 4
// 0050cdf1  83ee01               sub esi, 1
// 0050cdf4  75ea                 jne 0x50cde0
// 0050cdf6  5f                   pop edi
// 0050cdf7  5e                   pop esi
// 0050cdf8  5b                   pop ebx
// 0050cdf9  c3                   ret 
// library libpng-1.2.7/pngread.c (function _png_read_rows)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngread.c
