// from server: 100% by auto
// roc 2007-08 005bdf80  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdf80
//
// 005bdf80  8b442408             mov eax, dword ptr [esp + 8]
// 005bdf84  56                   push esi
// 005bdf85  8b742408             mov esi, dword ptr [esp + 8]
// 005bdf89  8bce                 mov ecx, esi
// 005bdf8b  e8a0f4ffff           call 0x5bd430
// 005bdf90  8b4808               mov ecx, dword ptr [eax + 8]
// 005bdf93  83e906               sub ecx, 6
// 005bdf96  7439                 je 0x5bdfd1
// 005bdf98  83e901               sub ecx, 1
// 005bdf9b  7434                 je 0x5bdfd1
// 005bdf9d  83e901               sub ecx, 1
// 005bdfa0  7410                 je 0x5bdfb2
// 005bdfa2  8b4608               mov eax, dword ptr [esi + 8]
// 005bdfa5  c7400800000000       mov dword ptr [eax + 8], 0
// 005bdfac  83460810             add dword ptr [esi + 8], 0x10
// 005bdfb0  5e                   pop esi
// 005bdfb1  c3                   ret 
// 005bdfb2  8b00                 mov eax, dword ptr [eax]
// 005bdfb4  8b5048               mov edx, dword ptr [eax + 0x48]
// 005bdfb7  8b4e08               mov ecx, dword ptr [esi + 8]
// 005bdfba  83c048               add eax, 0x48
// 005bdfbd  8911                 mov dword ptr [ecx], edx
// 005bdfbf  8b5004               mov edx, dword ptr [eax + 4]
// 005bdfc2  895104               mov dword ptr [ecx + 4], edx
// 005bdfc5  8b4008               mov eax, dword ptr [eax + 8]
// 005bdfc8  894108               mov dword ptr [ecx + 8], eax
// 005bdfcb  83460810             add dword ptr [esi + 8], 0x10
// 005bdfcf  5e                   pop esi
// 005bdfd0  c3                   ret 
// 005bdfd1  8b10                 mov edx, dword ptr [eax]
// 005bdfd3  8b4e08               mov ecx, dword ptr [esi + 8]
// 005bdfd6  8b420c               mov eax, dword ptr [edx + 0xc]
// 005bdfd9  c7410805000000       mov dword ptr [ecx + 8], 5
// 005bdfe0  8901                 mov dword ptr [ecx], eax
// 005bdfe2  83460810             add dword ptr [esi + 8], 0x10
// 005bdfe6  5e                   pop esi
// 005bdfe7  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfenv)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
