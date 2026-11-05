// from server: 100% by auto
// roc 2011-06 00762d50  unit: seg_00760000  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762d50
//
// 00762d50  8b442408             mov eax, dword ptr [esp + 8]
// 00762d54  56                   push esi
// 00762d55  8b742408             mov esi, dword ptr [esp + 8]
// 00762d59  8bce                 mov ecx, esi
// 00762d5b  e850f4ffff           call 0x7621b0
// 00762d60  8b4808               mov ecx, dword ptr [eax + 8]
// 00762d63  83e906               sub ecx, 6
// 00762d66  7439                 je 0x762da1
// 00762d68  83e901               sub ecx, 1
// 00762d6b  7434                 je 0x762da1
// 00762d6d  83e901               sub ecx, 1
// 00762d70  7410                 je 0x762d82
// 00762d72  8b4608               mov eax, dword ptr [esi + 8]
// 00762d75  c7400800000000       mov dword ptr [eax + 8], 0
// 00762d7c  83460810             add dword ptr [esi + 8], 0x10
// 00762d80  5e                   pop esi
// 00762d81  c3                   ret 
// 00762d82  8b00                 mov eax, dword ptr [eax]
// 00762d84  8b5048               mov edx, dword ptr [eax + 0x48]
// 00762d87  8b4e08               mov ecx, dword ptr [esi + 8]
// 00762d8a  83c048               add eax, 0x48
// 00762d8d  8911                 mov dword ptr [ecx], edx
// 00762d8f  8b5004               mov edx, dword ptr [eax + 4]
// 00762d92  895104               mov dword ptr [ecx + 4], edx
// 00762d95  8b4008               mov eax, dword ptr [eax + 8]
// 00762d98  894108               mov dword ptr [ecx + 8], eax
// 00762d9b  83460810             add dword ptr [esi + 8], 0x10
// 00762d9f  5e                   pop esi
// 00762da0  c3                   ret 
// 00762da1  8b10                 mov edx, dword ptr [eax]
// 00762da3  8b4e08               mov ecx, dword ptr [esi + 8]
// 00762da6  8b420c               mov eax, dword ptr [edx + 0xc]
// 00762da9  c7410805000000       mov dword ptr [ecx + 8], 5
// 00762db0  8901                 mov dword ptr [ecx], eax
// 00762db2  83460810             add dword ptr [esi + 8], 0x10
// 00762db6  5e                   pop esi
// 00762db7  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfenv)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
