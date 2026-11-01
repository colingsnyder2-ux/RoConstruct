// from server: 100% by auto
// roc 2007-03 005b9450  unit: seg_005b0000  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9450
//
// 005b9450  8b442408             mov eax, dword ptr [esp + 8]
// 005b9454  56                   push esi
// 005b9455  8b742408             mov esi, dword ptr [esp + 8]
// 005b9459  8bce                 mov ecx, esi
// 005b945b  e850f4ffff           call 0x5b88b0
// 005b9460  8b4808               mov ecx, dword ptr [eax + 8]
// 005b9463  83e906               sub ecx, 6
// 005b9466  7439                 je 0x5b94a1
// 005b9468  83e901               sub ecx, 1
// 005b946b  7434                 je 0x5b94a1
// 005b946d  83e901               sub ecx, 1
// 005b9470  7410                 je 0x5b9482
// 005b9472  8b4608               mov eax, dword ptr [esi + 8]
// 005b9475  c7400800000000       mov dword ptr [eax + 8], 0
// 005b947c  83460810             add dword ptr [esi + 8], 0x10
// 005b9480  5e                   pop esi
// 005b9481  c3                   ret 
// 005b9482  8b00                 mov eax, dword ptr [eax]
// 005b9484  8b5048               mov edx, dword ptr [eax + 0x48]
// 005b9487  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b948a  83c048               add eax, 0x48
// 005b948d  8911                 mov dword ptr [ecx], edx
// 005b948f  8b5004               mov edx, dword ptr [eax + 4]
// 005b9492  895104               mov dword ptr [ecx + 4], edx
// 005b9495  8b4008               mov eax, dword ptr [eax + 8]
// 005b9498  894108               mov dword ptr [ecx + 8], eax
// 005b949b  83460810             add dword ptr [esi + 8], 0x10
// 005b949f  5e                   pop esi
// 005b94a0  c3                   ret 
// 005b94a1  8b10                 mov edx, dword ptr [eax]
// 005b94a3  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b94a6  8b420c               mov eax, dword ptr [edx + 0xc]
// 005b94a9  c7410805000000       mov dword ptr [ecx + 8], 5
// 005b94b0  8901                 mov dword ptr [ecx], eax
// 005b94b2  83460810             add dword ptr [esi + 8], 0x10
// 005b94b6  5e                   pop esi
// 005b94b7  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_getfenv)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
