// from server: 100% by auto
// roc 2007-03 005b9630  unit: seg_005b0000  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9630
//
// 005b9630  8b442408             mov eax, dword ptr [esp + 8]
// 005b9634  56                   push esi
// 005b9635  57                   push edi
// 005b9636  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005b963a  8bcf                 mov ecx, edi
// 005b963c  e86ff2ffff           call 0x5b88b0
// 005b9641  8b4f08               mov ecx, dword ptr [edi + 8]
// 005b9644  8379f800             cmp dword ptr [ecx - 8], 0
// 005b9648  7504                 jne 0x5b964e
// 005b964a  33c9                 xor ecx, ecx
// 005b964c  eb03                 jmp 0x5b9651
// 005b964e  8b49f0               mov ecx, dword ptr [ecx - 0x10]
// 005b9651  8b5008               mov edx, dword ptr [eax + 8]
// 005b9654  8bf2                 mov esi, edx
// 005b9656  83ee05               sub esi, 5
// 005b9659  7449                 je 0x5b96a4
// 005b965b  83ee02               sub esi, 2
// 005b965e  7416                 je 0x5b9676
// 005b9660  8b4710               mov eax, dword ptr [edi + 0x10]
// 005b9663  898c9098000000       mov dword ptr [eax + edx*4 + 0x98], ecx
// 005b966a  834708f0             add dword ptr [edi + 8], -0x10
// 005b966e  5f                   pop edi
// 005b966f  b801000000           mov eax, 1
// 005b9674  5e                   pop esi
// 005b9675  c3                   ret 
// 005b9676  85c9                 test ecx, ecx
// 005b9678  8b10                 mov edx, dword ptr [eax]
// 005b967a  894a08               mov dword ptr [edx + 8], ecx
// 005b967d  7446                 je 0x5b96c5
// 005b967f  f6410503             test byte ptr [ecx + 5], 3
// 005b9683  7440                 je 0x5b96c5
// 005b9685  8b00                 mov eax, dword ptr [eax]
// 005b9687  f6400504             test byte ptr [eax + 5], 4
// 005b968b  7438                 je 0x5b96c5
// 005b968d  51                   push ecx
// 005b968e  50                   push eax
// 005b968f  57                   push edi
// 005b9690  e80b020400           call 0x5f98a0
// 005b9695  83c40c               add esp, 0xc
// 005b9698  834708f0             add dword ptr [edi + 8], -0x10
// 005b969c  5f                   pop edi
// 005b969d  b801000000           mov eax, 1
// 005b96a2  5e                   pop esi
// 005b96a3  c3                   ret 
// 005b96a4  85c9                 test ecx, ecx
// 005b96a6  8b10                 mov edx, dword ptr [eax]
// 005b96a8  894a08               mov dword ptr [edx + 8], ecx
// 005b96ab  7418                 je 0x5b96c5
// 005b96ad  f6410503             test byte ptr [ecx + 5], 3
// 005b96b1  7412                 je 0x5b96c5
// 005b96b3  8b00                 mov eax, dword ptr [eax]
// 005b96b5  f6400504             test byte ptr [eax + 5], 4
// 005b96b9  740a                 je 0x5b96c5
// 005b96bb  50                   push eax
// 005b96bc  57                   push edi
// 005b96bd  e81e020400           call 0x5f98e0
// 005b96c2  83c408               add esp, 8
// 005b96c5  834708f0             add dword ptr [edi + 8], -0x10
// 005b96c9  5f                   pop edi
// 005b96ca  b801000000           mov eax, 1
// 005b96cf  5e                   pop esi
// 005b96d0  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_setmetatable)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
