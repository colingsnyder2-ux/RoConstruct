// from server: 100% by auto
// roc 2012-06 00832b40  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832b40
//
// 00832b40  56                   push esi
// 00832b41  8b742408             mov esi, dword ptr [esp + 8]
// 00832b45  8b4610               mov eax, dword ptr [esi + 0x10]
// 00832b48  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00832b4b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00832b4e  7209                 jb 0x832b59
// 00832b50  56                   push esi
// 00832b51  e85a071000           call 0x9332b0
// 00832b56  83c404               add esp, 4
// 00832b59  8b4614               mov eax, dword ptr [esi + 0x14]
// 00832b5c  3b4628               cmp eax, dword ptr [esi + 0x28]
// 00832b5f  7505                 jne 0x832b66
// 00832b61  8b4648               mov eax, dword ptr [esi + 0x48]
// 00832b64  eb08                 jmp 0x832b6e
// 00832b66  8b5004               mov edx, dword ptr [eax + 4]
// 00832b69  8b02                 mov eax, dword ptr [edx]
// 00832b6b  8b400c               mov eax, dword ptr [eax + 0xc]
// 00832b6e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00832b72  50                   push eax
// 00832b73  51                   push ecx
// 00832b74  56                   push esi
// 00832b75  e8a6381000           call 0x936420
// 00832b7a  8b4e08               mov ecx, dword ptr [esi + 8]
// 00832b7d  8901                 mov dword ptr [ecx], eax
// 00832b7f  83c40c               add esp, 0xc
// 00832b82  c7410807000000       mov dword ptr [ecx + 8], 7
// 00832b89  83460810             add dword ptr [esi + 8], 0x10
// 00832b8d  83c018               add eax, 0x18
// 00832b90  5e                   pop esi
// 00832b91  c3                   ret 
// library lua-5.1/lapi.c (function _lua_newuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
