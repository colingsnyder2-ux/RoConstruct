// from server: 100% by auto
// roc 2008-06 0065e970  unit: seg_00650000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065e970
//
// 0065e970  56                   push esi
// 0065e971  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0065e975  8b4610               mov eax, dword ptr [esi + 0x10]
// 0065e978  57                   push edi
// 0065e979  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0065e97d  3dd0c38400           cmp eax, 0x84c3d0
// 0065e982  741a                 je 0x65e99e
// 0065e984  8a4e07               mov cl, byte ptr [esi + 7]
// 0065e987  ba01000000           mov edx, 1
// 0065e98c  d3e2                 shl edx, cl
// 0065e98e  6a00                 push 0
// 0065e990  c1e205               shl edx, 5
// 0065e993  52                   push edx
// 0065e994  50                   push eax
// 0065e995  57                   push edi
// 0065e996  e8551d0000           call 0x6606f0
// 0065e99b  83c410               add esp, 0x10
// 0065e99e  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0065e9a1  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0065e9a4  6a00                 push 0
// 0065e9a6  c1e004               shl eax, 4
// 0065e9a9  50                   push eax
// 0065e9aa  51                   push ecx
// 0065e9ab  57                   push edi
// 0065e9ac  e83f1d0000           call 0x6606f0
// 0065e9b1  6a00                 push 0
// 0065e9b3  6a20                 push 0x20
// 0065e9b5  56                   push esi
// 0065e9b6  57                   push edi
// 0065e9b7  e8341d0000           call 0x6606f0
// 0065e9bc  83c420               add esp, 0x20
// 0065e9bf  5f                   pop edi
// 0065e9c0  5e                   pop esi
// 0065e9c1  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_free)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
