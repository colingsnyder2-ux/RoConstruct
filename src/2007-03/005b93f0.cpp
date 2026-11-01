// from server: 100% by auto
// roc 2007-03 005b93f0  unit: seg_005b0000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b93f0
//
// 005b93f0  8b442408             mov eax, dword ptr [esp + 8]
// 005b93f4  56                   push esi
// 005b93f5  8b742408             mov esi, dword ptr [esp + 8]
// 005b93f9  8bce                 mov ecx, esi
// 005b93fb  e8b0f4ffff           call 0x5b88b0
// 005b9400  8b4808               mov ecx, dword ptr [eax + 8]
// 005b9403  8bd1                 mov edx, ecx
// 005b9405  83ea05               sub edx, 5
// 005b9408  7418                 je 0x5b9422
// 005b940a  83ea02               sub edx, 2
// 005b940d  740c                 je 0x5b941b
// 005b940f  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b9412  8b8c8898000000       mov ecx, dword ptr [eax + ecx*4 + 0x98]
// 005b9419  eb0c                 jmp 0x5b9427
// 005b941b  8b08                 mov ecx, dword ptr [eax]
// 005b941d  8b4908               mov ecx, dword ptr [ecx + 8]
// 005b9420  eb05                 jmp 0x5b9427
// 005b9422  8b10                 mov edx, dword ptr [eax]
// 005b9424  8b4a08               mov ecx, dword ptr [edx + 8]
// 005b9427  85c9                 test ecx, ecx
// 005b9429  7504                 jne 0x5b942f
// 005b942b  33c0                 xor eax, eax
// 005b942d  5e                   pop esi
// 005b942e  c3                   ret 
// 005b942f  8b4608               mov eax, dword ptr [esi + 8]
// 005b9432  8908                 mov dword ptr [eax], ecx
// 005b9434  c7400805000000       mov dword ptr [eax + 8], 5
// 005b943b  83460810             add dword ptr [esi + 8], 0x10
// 005b943f  b801000000           mov eax, 1
// 005b9444  5e                   pop esi
// 005b9445  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_getmetatable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
