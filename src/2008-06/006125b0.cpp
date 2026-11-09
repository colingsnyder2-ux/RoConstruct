// from server: 100% by auto
// roc 2008-06 006125b0  unit: seg_00610000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006125b0
//
// 006125b0  8b442408             mov eax, dword ptr [esp + 8]
// 006125b4  56                   push esi
// 006125b5  8b742408             mov esi, dword ptr [esp + 8]
// 006125b9  8bce                 mov ecx, esi
// 006125bb  e8d0f4ffff           call 0x611a90
// 006125c0  8b4808               mov ecx, dword ptr [eax + 8]
// 006125c3  8bd1                 mov edx, ecx
// 006125c5  83ea05               sub edx, 5
// 006125c8  7418                 je 0x6125e2
// 006125ca  83ea02               sub edx, 2
// 006125cd  740c                 je 0x6125db
// 006125cf  8b4610               mov eax, dword ptr [esi + 0x10]
// 006125d2  8b8c8898000000       mov ecx, dword ptr [eax + ecx*4 + 0x98]
// 006125d9  eb0c                 jmp 0x6125e7
// 006125db  8b08                 mov ecx, dword ptr [eax]
// 006125dd  8b4908               mov ecx, dword ptr [ecx + 8]
// 006125e0  eb05                 jmp 0x6125e7
// 006125e2  8b10                 mov edx, dword ptr [eax]
// 006125e4  8b4a08               mov ecx, dword ptr [edx + 8]
// 006125e7  85c9                 test ecx, ecx
// 006125e9  7504                 jne 0x6125ef
// 006125eb  33c0                 xor eax, eax
// 006125ed  5e                   pop esi
// 006125ee  c3                   ret 
// 006125ef  8b4608               mov eax, dword ptr [esi + 8]
// 006125f2  8908                 mov dword ptr [eax], ecx
// 006125f4  c7400805000000       mov dword ptr [eax + 8], 5
// 006125fb  83460810             add dword ptr [esi + 8], 0x10
// 006125ff  b801000000           mov eax, 1
// 00612604  5e                   pop esi
// 00612605  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getmetatable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
