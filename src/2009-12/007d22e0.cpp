// from server: 100% by auto
// roc 2009-12 007d22e0  unit: seg_007d0000  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d22e0
//
// 007d22e0  837e2400             cmp dword ptr [esi + 0x24], 0
// 007d22e4  7455                 je 0x7d233b
// 007d22e6  8b06                 mov eax, dword ptr [esi]
// 007d22e8  83f80d               cmp eax, 0xd
// 007d22eb  742c                 je 0x7d2319
// 007d22ed  83f80e               cmp eax, 0xe
// 007d22f0  7427                 je 0x7d2319
// 007d22f2  85c0                 test eax, eax
// 007d22f4  740a                 je 0x7d2300
// 007d22f6  56                   push esi
// 007d22f7  57                   push edi
// 007d22f8  e813a90000           call 0x7dcc10
// 007d22fd  83c408               add esp, 8
// 007d2300  8b4624               mov eax, dword ptr [esi + 0x24]
// 007d2303  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007d2306  8b5618               mov edx, dword ptr [esi + 0x18]
// 007d2309  50                   push eax
// 007d230a  8b4208               mov eax, dword ptr [edx + 8]
// 007d230d  51                   push ecx
// 007d230e  50                   push eax
// 007d230f  57                   push edi
// 007d2310  e84ba30000           call 0x7dc660
// 007d2315  83c410               add esp, 0x10
// 007d2318  c3                   ret 
// 007d2319  6aff                 push -1
// 007d231b  56                   push esi
// 007d231c  57                   push edi
// 007d231d  e8de9f0000           call 0x7dc300
// 007d2322  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007d2325  8b5618               mov edx, dword ptr [esi + 0x18]
// 007d2328  8b4208               mov eax, dword ptr [edx + 8]
// 007d232b  6aff                 push -1
// 007d232d  51                   push ecx
// 007d232e  50                   push eax
// 007d232f  57                   push edi
// 007d2330  e82ba30000           call 0x7dc660
// 007d2335  83c41c               add esp, 0x1c
// 007d2338  ff4e20               dec dword ptr [esi + 0x20]
// 007d233b  c3                   ret 
// library lua-5.1/lparser.c (function _lastlistfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
