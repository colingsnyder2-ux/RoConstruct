// from server: 100% by auto
// roc 2012-06 00831b50  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831b50
//
// 00831b50  8b442408             mov eax, dword ptr [esp + 8]
// 00831b54  56                   push esi
// 00831b55  8b742408             mov esi, dword ptr [esp + 8]
// 00831b59  8bce                 mov ecx, esi
// 00831b5b  e8e0fdffff           call 0x831940
// 00831b60  83c010               add eax, 0x10
// 00831b63  3b4608               cmp eax, dword ptr [esi + 8]
// 00831b66  7323                 jae 0x831b8b
// 00831b68  8d48f0               lea ecx, [eax - 0x10]
// 00831b6b  eb03                 jmp 0x831b70
// 00831b6d  8d4900               lea ecx, [ecx]
// 00831b70  8b10                 mov edx, dword ptr [eax]
// 00831b72  8911                 mov dword ptr [ecx], edx
// 00831b74  8b5004               mov edx, dword ptr [eax + 4]
// 00831b77  895104               mov dword ptr [ecx + 4], edx
// 00831b7a  8b5118               mov edx, dword ptr [ecx + 0x18]
// 00831b7d  895108               mov dword ptr [ecx + 8], edx
// 00831b80  83c010               add eax, 0x10
// 00831b83  83c110               add ecx, 0x10
// 00831b86  3b4608               cmp eax, dword ptr [esi + 8]
// 00831b89  72e5                 jb 0x831b70
// 00831b8b  834608f0             add dword ptr [esi + 8], -0x10
// 00831b8f  5e                   pop esi
// 00831b90  c3                   ret 
// library lua-5.1/lapi.c (function _lua_remove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
