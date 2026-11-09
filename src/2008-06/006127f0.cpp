// from server: 100% by auto
// roc 2008-06 006127f0  unit: seg_00610000  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006127f0
//
// 006127f0  8b442408             mov eax, dword ptr [esp + 8]
// 006127f4  56                   push esi
// 006127f5  57                   push edi
// 006127f6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006127fa  8bcf                 mov ecx, edi
// 006127fc  e88ff2ffff           call 0x611a90
// 00612801  8b4f08               mov ecx, dword ptr [edi + 8]
// 00612804  8379f800             cmp dword ptr [ecx - 8], 0
// 00612808  7504                 jne 0x61280e
// 0061280a  33c9                 xor ecx, ecx
// 0061280c  eb03                 jmp 0x612811
// 0061280e  8b49f0               mov ecx, dword ptr [ecx - 0x10]
// 00612811  8b5008               mov edx, dword ptr [eax + 8]
// 00612814  8bf2                 mov esi, edx
// 00612816  83ee05               sub esi, 5
// 00612819  7449                 je 0x612864
// 0061281b  83ee02               sub esi, 2
// 0061281e  7416                 je 0x612836
// 00612820  8b4710               mov eax, dword ptr [edi + 0x10]
// 00612823  898c9098000000       mov dword ptr [eax + edx*4 + 0x98], ecx
// 0061282a  834708f0             add dword ptr [edi + 8], -0x10
// 0061282e  5f                   pop edi
// 0061282f  b801000000           mov eax, 1
// 00612834  5e                   pop esi
// 00612835  c3                   ret 
// 00612836  8b10                 mov edx, dword ptr [eax]
// 00612838  894a08               mov dword ptr [edx + 8], ecx
// 0061283b  85c9                 test ecx, ecx
// 0061283d  7446                 je 0x612885
// 0061283f  f6410503             test byte ptr [ecx + 5], 3
// 00612843  7440                 je 0x612885
// 00612845  8b00                 mov eax, dword ptr [eax]
// 00612847  f6400504             test byte ptr [eax + 5], 4
// 0061284b  7438                 je 0x612885
// 0061284d  51                   push ecx
// 0061284e  50                   push eax
// 0061284f  57                   push edi
// 00612850  e82b9c0400           call 0x65c480
// 00612855  83c40c               add esp, 0xc
// 00612858  834708f0             add dword ptr [edi + 8], -0x10
// 0061285c  5f                   pop edi
// 0061285d  b801000000           mov eax, 1
// 00612862  5e                   pop esi
// 00612863  c3                   ret 
// 00612864  8b10                 mov edx, dword ptr [eax]
// 00612866  894a08               mov dword ptr [edx + 8], ecx
// 00612869  85c9                 test ecx, ecx
// 0061286b  7418                 je 0x612885
// 0061286d  f6410503             test byte ptr [ecx + 5], 3
// 00612871  7412                 je 0x612885
// 00612873  8b00                 mov eax, dword ptr [eax]
// 00612875  f6400504             test byte ptr [eax + 5], 4
// 00612879  740a                 je 0x612885
// 0061287b  50                   push eax
// 0061287c  57                   push edi
// 0061287d  e83e9c0400           call 0x65c4c0
// 00612882  83c408               add esp, 8
// 00612885  834708f0             add dword ptr [edi + 8], -0x10
// 00612889  5f                   pop edi
// 0061288a  b801000000           mov eax, 1
// 0061288f  5e                   pop esi
// 00612890  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setmetatable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
