// from server: 100% by auto
// roc 2007-03 005fd980  unit: seg_005f0000  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd980
//
// 005fd980  56                   push esi
// 005fd981  57                   push edi
// 005fd982  8b7830               mov edi, dword ptr [eax + 0x30]
// 005fd985  8b01                 mov eax, dword ptr [ecx]
// 005fd987  8bf2                 mov esi, edx
// 005fd989  2b74240c             sub esi, dword ptr [esp + 0xc]
// 005fd98d  83f80d               cmp eax, 0xd
// 005fd990  7431                 je 0x5fd9c3
// 005fd992  83f80e               cmp eax, 0xe
// 005fd995  742c                 je 0x5fd9c3
// 005fd997  85c0                 test eax, eax
// 005fd999  740a                 je 0x5fd9a5
// 005fd99b  51                   push ecx
// 005fd99c  57                   push edi
// 005fd99d  e81e780100           call 0x6151c0
// 005fd9a2  83c408               add esp, 8
// 005fd9a5  85f6                 test esi, esi
// 005fd9a7  7e3e                 jle 0x5fd9e7
// 005fd9a9  53                   push ebx
// 005fd9aa  8b5f24               mov ebx, dword ptr [edi + 0x24]
// 005fd9ad  56                   push esi
// 005fd9ae  57                   push edi
// 005fd9af  e82c6d0100           call 0x6146e0
// 005fd9b4  56                   push esi
// 005fd9b5  53                   push ebx
// 005fd9b6  57                   push edi
// 005fd9b7  e8f4720100           call 0x614cb0
// 005fd9bc  83c414               add esp, 0x14
// 005fd9bf  5b                   pop ebx
// 005fd9c0  5f                   pop edi
// 005fd9c1  5e                   pop esi
// 005fd9c2  c3                   ret 
// 005fd9c3  83c601               add esi, 1
// 005fd9c6  7902                 jns 0x5fd9ca
// 005fd9c8  33f6                 xor esi, esi
// 005fd9ca  56                   push esi
// 005fd9cb  51                   push ecx
// 005fd9cc  57                   push edi
// 005fd9cd  e8ee6e0100           call 0x6148c0
// 005fd9d2  83c40c               add esp, 0xc
// 005fd9d5  83fe01               cmp esi, 1
// 005fd9d8  7e0d                 jle 0x5fd9e7
// 005fd9da  83c6ff               add esi, -1
// 005fd9dd  56                   push esi
// 005fd9de  57                   push edi
// 005fd9df  e8fc6c0100           call 0x6146e0
// 005fd9e4  83c408               add esp, 8
// 005fd9e7  5f                   pop edi
// 005fd9e8  5e                   pop esi
// 005fd9e9  c3                   ret 
// library lua-5.1.1/lparser.c (function _adjust_assign)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
