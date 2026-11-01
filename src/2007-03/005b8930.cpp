// from server: 100% by auto
// roc 2007-03 005b8930  unit: seg_005b0000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8930
//
// 005b8930  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005b8934  56                   push esi
// 005b8935  8b742408             mov esi, dword ptr [esp + 8]
// 005b8939  8b4608               mov eax, dword ptr [esi + 8]
// 005b893c  8bd0                 mov edx, eax
// 005b893e  2b560c               sub edx, dword ptr [esi + 0xc]
// 005b8941  c1fa04               sar edx, 4
// 005b8944  03d1                 add edx, ecx
// 005b8946  81fa00080000         cmp edx, 0x800
// 005b894c  7e04                 jle 0x5b8952
// 005b894e  33c0                 xor eax, eax
// 005b8950  5e                   pop esi
// 005b8951  c3                   ret 
// 005b8952  8b561c               mov edx, dword ptr [esi + 0x1c]
// 005b8955  57                   push edi
// 005b8956  8bf9                 mov edi, ecx
// 005b8958  c1e704               shl edi, 4
// 005b895b  2bd0                 sub edx, eax
// 005b895d  3bd7                 cmp edx, edi
// 005b895f  7f0a                 jg 0x5b896b
// 005b8961  51                   push ecx
// 005b8962  56                   push esi
// 005b8963  e888730000           call 0x5bfcf0
// 005b8968  83c408               add esp, 8
// 005b896b  8b4608               mov eax, dword ptr [esi + 8]
// 005b896e  8b7614               mov esi, dword ptr [esi + 0x14]
// 005b8971  03c7                 add eax, edi
// 005b8973  394608               cmp dword ptr [esi + 8], eax
// 005b8976  5f                   pop edi
// 005b8977  7303                 jae 0x5b897c
// 005b8979  894608               mov dword ptr [esi + 8], eax
// 005b897c  b801000000           mov eax, 1
// 005b8981  5e                   pop esi
// 005b8982  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_checkstack)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
