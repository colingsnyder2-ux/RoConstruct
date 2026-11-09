// from server: 100% by auto
// roc 2009-06 0057f950  unit: G3D::_internal::DialogTemplate  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0057f950
//
// 0057f950  56                   push esi
// 0057f951  8b742408             mov esi, dword ptr [esp + 8]
// 0057f955  85f6                 test esi, esi
// 0057f957  0f84c9000000         je 0x57fa26
// 0057f95d  8b86e4000000         mov eax, dword ptr [esi + 0xe4]
// 0057f963  3b86d0000000         cmp eax, dword ptr [esi + 0xd0]
// 0057f969  0f83b7000000         jae 0x57fa26
// 0057f96f  57                   push edi
// 0057f970  8d7e74               lea edi, [esi + 0x74]
// 0057f973  6a02                 push 2
// 0057f975  57                   push edi
// 0057f976  e815f40000           call 0x58ed90
// 0057f97b  83c408               add esp, 8
// 0057f97e  85c0                 test eax, eax
// 0057f980  741b                 je 0x57f99d
// 0057f982  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 0057f988  85c0                 test eax, eax
// 0057f98a  7403                 je 0x57f98f
// 0057f98c  50                   push eax
// 0057f98d  eb05                 jmp 0x57f994
// 0057f98f  6814c38c00           push 0x8cc314
// 0057f994  56                   push esi
// 0057f995  e8c6e70000           call 0x58e160
// 0057f99a  83c408               add esp, 8
// 0057f99d  83be8400000000       cmp dword ptr [esi + 0x84], 0
// 0057f9a4  7531                 jne 0x57f9d7
// 0057f9a6  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0057f9ac  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 0057f9b2  51                   push ecx
// 0057f9b3  52                   push edx
// 0057f9b4  56                   push esi
// 0057f9b5  e836c50000           call 0x58bef0
// 0057f9ba  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0057f9c0  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0057f9c6  83c40c               add esp, 0xc
// 0057f9c9  898680000000         mov dword ptr [esi + 0x80], eax
// 0057f9cf  898e84000000         mov dword ptr [esi + 0x84], ecx
// 0057f9d5  eb9c                 jmp 0x57f973
// 0057f9d7  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0057f9dd  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 0057f9e3  5f                   pop edi
// 0057f9e4  3bc1                 cmp eax, ecx
// 0057f9e6  742b                 je 0x57fa13
// 0057f9e8  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 0057f9ee  2bc1                 sub eax, ecx
// 0057f9f0  50                   push eax
// 0057f9f1  52                   push edx
// 0057f9f2  56                   push esi
// 0057f9f3  e8f8c40000           call 0x58bef0
// 0057f9f8  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0057f9fe  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0057fa04  83c40c               add esp, 0xc
// 0057fa07  898680000000         mov dword ptr [esi + 0x80], eax
// 0057fa0d  898e84000000         mov dword ptr [esi + 0x84], ecx
// 0057fa13  56                   push esi
// 0057fa14  c7865401000000000000 mov dword ptr [esi + 0x154], 0
// 0057fa1e  e81d1c0000           call 0x581640
// 0057fa23  83c404               add esp, 4
// 0057fa26  5e                   pop esi
// 0057fa27  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_flush)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
