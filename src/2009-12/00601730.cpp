// from server: 100% by auto
// roc 2009-12 00601730  unit: G3D::_internal::DialogTemplate  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00601730
//
// 00601730  56                   push esi
// 00601731  8b742408             mov esi, dword ptr [esp + 8]
// 00601735  85f6                 test esi, esi
// 00601737  0f84c9000000         je 0x601806
// 0060173d  8b86e4000000         mov eax, dword ptr [esi + 0xe4]
// 00601743  3b86d0000000         cmp eax, dword ptr [esi + 0xd0]
// 00601749  0f83b7000000         jae 0x601806
// 0060174f  57                   push edi
// 00601750  8d7e74               lea edi, [esi + 0x74]
// 00601753  6a02                 push 2
// 00601755  57                   push edi
// 00601756  e865f60000           call 0x610dc0
// 0060175b  83c408               add esp, 8
// 0060175e  85c0                 test eax, eax
// 00601760  741b                 je 0x60177d
// 00601762  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 00601768  85c0                 test eax, eax
// 0060176a  7403                 je 0x60176f
// 0060176c  50                   push eax
// 0060176d  eb05                 jmp 0x601774
// 0060176f  68bc319c00           push 0x9c31bc
// 00601774  56                   push esi
// 00601775  e816ea0000           call 0x610190
// 0060177a  83c408               add esp, 8
// 0060177d  83be8400000000       cmp dword ptr [esi + 0x84], 0
// 00601784  7531                 jne 0x6017b7
// 00601786  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0060178c  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 00601792  51                   push ecx
// 00601793  52                   push edx
// 00601794  56                   push esi
// 00601795  e8a6c70000           call 0x60df40
// 0060179a  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 006017a0  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 006017a6  83c40c               add esp, 0xc
// 006017a9  898680000000         mov dword ptr [esi + 0x80], eax
// 006017af  898e84000000         mov dword ptr [esi + 0x84], ecx
// 006017b5  eb9c                 jmp 0x601753
// 006017b7  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 006017bd  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 006017c3  5f                   pop edi
// 006017c4  3bc1                 cmp eax, ecx
// 006017c6  742b                 je 0x6017f3
// 006017c8  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 006017ce  2bc1                 sub eax, ecx
// 006017d0  50                   push eax
// 006017d1  52                   push edx
// 006017d2  56                   push esi
// 006017d3  e868c70000           call 0x60df40
// 006017d8  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 006017de  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 006017e4  83c40c               add esp, 0xc
// 006017e7  898680000000         mov dword ptr [esi + 0x80], eax
// 006017ed  898e84000000         mov dword ptr [esi + 0x84], ecx
// 006017f3  56                   push esi
// 006017f4  c7865401000000000000 mov dword ptr [esi + 0x154], 0
// 006017fe  e8ed1b0000           call 0x6033f0
// 00601803  83c404               add esp, 4
// 00601806  5e                   pop esi
// 00601807  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_flush)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
