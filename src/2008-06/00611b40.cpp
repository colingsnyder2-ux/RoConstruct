// from server: 100% by auto
// roc 2008-06 00611b40  unit: seg_00610000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611b40
//
// 00611b40  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00611b44  56                   push esi
// 00611b45  8b742408             mov esi, dword ptr [esp + 8]
// 00611b49  8b4608               mov eax, dword ptr [esi + 8]
// 00611b4c  8bd0                 mov edx, eax
// 00611b4e  2b560c               sub edx, dword ptr [esi + 0xc]
// 00611b51  c1fa04               sar edx, 4
// 00611b54  03d1                 add edx, ecx
// 00611b56  81fa00080000         cmp edx, 0x800
// 00611b5c  7e04                 jle 0x611b62
// 00611b5e  33c0                 xor eax, eax
// 00611b60  5e                   pop esi
// 00611b61  c3                   ret 
// 00611b62  8b561c               mov edx, dword ptr [esi + 0x1c]
// 00611b65  57                   push edi
// 00611b66  8bf9                 mov edi, ecx
// 00611b68  c1e704               shl edi, 4
// 00611b6b  2bd0                 sub edx, eax
// 00611b6d  3bd7                 cmp edx, edi
// 00611b6f  7f0a                 jg 0x611b7b
// 00611b71  51                   push ecx
// 00611b72  56                   push esi
// 00611b73  e8d8ff0000           call 0x621b50
// 00611b78  83c408               add esp, 8
// 00611b7b  8b4608               mov eax, dword ptr [esi + 8]
// 00611b7e  8b7614               mov esi, dword ptr [esi + 0x14]
// 00611b81  03c7                 add eax, edi
// 00611b83  5f                   pop edi
// 00611b84  394608               cmp dword ptr [esi + 8], eax
// 00611b87  7303                 jae 0x611b8c
// 00611b89  894608               mov dword ptr [esi + 8], eax
// 00611b8c  b801000000           mov eax, 1
// 00611b91  5e                   pop esi
// 00611b92  c3                   ret 
// library lua-5.1/lapi.c (function _lua_checkstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
