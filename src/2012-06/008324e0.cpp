// from server: 100% by auto
// roc 2012-06 008324e0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008324e0
//
// 008324e0  8b442408             mov eax, dword ptr [esp + 8]
// 008324e4  56                   push esi
// 008324e5  8b742408             mov esi, dword ptr [esp + 8]
// 008324e9  8bce                 mov ecx, esi
// 008324eb  e850f4ffff           call 0x831940
// 008324f0  8b4808               mov ecx, dword ptr [eax + 8]
// 008324f3  83e906               sub ecx, 6
// 008324f6  7439                 je 0x832531
// 008324f8  83e901               sub ecx, 1
// 008324fb  7434                 je 0x832531
// 008324fd  83e901               sub ecx, 1
// 00832500  7410                 je 0x832512
// 00832502  8b4608               mov eax, dword ptr [esi + 8]
// 00832505  c7400800000000       mov dword ptr [eax + 8], 0
// 0083250c  83460810             add dword ptr [esi + 8], 0x10
// 00832510  5e                   pop esi
// 00832511  c3                   ret 
// 00832512  8b00                 mov eax, dword ptr [eax]
// 00832514  8b5048               mov edx, dword ptr [eax + 0x48]
// 00832517  8b4e08               mov ecx, dword ptr [esi + 8]
// 0083251a  83c048               add eax, 0x48
// 0083251d  8911                 mov dword ptr [ecx], edx
// 0083251f  8b5004               mov edx, dword ptr [eax + 4]
// 00832522  895104               mov dword ptr [ecx + 4], edx
// 00832525  8b4008               mov eax, dword ptr [eax + 8]
// 00832528  894108               mov dword ptr [ecx + 8], eax
// 0083252b  83460810             add dword ptr [esi + 8], 0x10
// 0083252f  5e                   pop esi
// 00832530  c3                   ret 
// 00832531  8b10                 mov edx, dword ptr [eax]
// 00832533  8b4e08               mov ecx, dword ptr [esi + 8]
// 00832536  8b420c               mov eax, dword ptr [edx + 0xc]
// 00832539  c7410805000000       mov dword ptr [ecx + 8], 5
// 00832540  8901                 mov dword ptr [ecx], eax
// 00832542  83460810             add dword ptr [esi + 8], 0x10
// 00832546  5e                   pop esi
// 00832547  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfenv)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
