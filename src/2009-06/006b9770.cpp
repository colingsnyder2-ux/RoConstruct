// from server: 100% by auto
// roc 2009-06 006b9770  unit: RBX::UniversalTool  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9770
//
// 006b9770  8b442408             mov eax, dword ptr [esp + 8]
// 006b9774  56                   push esi
// 006b9775  8b742408             mov esi, dword ptr [esp + 8]
// 006b9779  8bce                 mov ecx, esi
// 006b977b  e850f4ffff           call 0x6b8bd0
// 006b9780  8b4808               mov ecx, dword ptr [eax + 8]
// 006b9783  83e906               sub ecx, 6
// 006b9786  7439                 je 0x6b97c1
// 006b9788  83e901               sub ecx, 1
// 006b978b  7434                 je 0x6b97c1
// 006b978d  83e901               sub ecx, 1
// 006b9790  7410                 je 0x6b97a2
// 006b9792  8b4608               mov eax, dword ptr [esi + 8]
// 006b9795  c7400800000000       mov dword ptr [eax + 8], 0
// 006b979c  83460810             add dword ptr [esi + 8], 0x10
// 006b97a0  5e                   pop esi
// 006b97a1  c3                   ret 
// 006b97a2  8b00                 mov eax, dword ptr [eax]
// 006b97a4  8b5048               mov edx, dword ptr [eax + 0x48]
// 006b97a7  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b97aa  83c048               add eax, 0x48
// 006b97ad  8911                 mov dword ptr [ecx], edx
// 006b97af  8b5004               mov edx, dword ptr [eax + 4]
// 006b97b2  895104               mov dword ptr [ecx + 4], edx
// 006b97b5  8b4008               mov eax, dword ptr [eax + 8]
// 006b97b8  894108               mov dword ptr [ecx + 8], eax
// 006b97bb  83460810             add dword ptr [esi + 8], 0x10
// 006b97bf  5e                   pop esi
// 006b97c0  c3                   ret 
// 006b97c1  8b10                 mov edx, dword ptr [eax]
// 006b97c3  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b97c6  8b420c               mov eax, dword ptr [edx + 0xc]
// 006b97c9  c7410805000000       mov dword ptr [ecx + 8], 5
// 006b97d0  8901                 mov dword ptr [ecx], eax
// 006b97d2  83460810             add dword ptr [esi + 8], 0x10
// 006b97d6  5e                   pop esi
// 006b97d7  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfenv)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
