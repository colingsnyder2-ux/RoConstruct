// from server: 100% by auto
// roc 2007-08 005be5b0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be5b0
//
// 005be5b0  56                   push esi
// 005be5b1  8b742408             mov esi, dword ptr [esp + 8]
// 005be5b5  8b4610               mov eax, dword ptr [esi + 0x10]
// 005be5b8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005be5bb  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005be5be  7209                 jb 0x5be5c9
// 005be5c0  56                   push esi
// 005be5c1  e83a180500           call 0x60fe00
// 005be5c6  83c404               add esp, 4
// 005be5c9  8b4614               mov eax, dword ptr [esi + 0x14]
// 005be5cc  3b4628               cmp eax, dword ptr [esi + 0x28]
// 005be5cf  7505                 jne 0x5be5d6
// 005be5d1  8b4648               mov eax, dword ptr [esi + 0x48]
// 005be5d4  eb08                 jmp 0x5be5de
// 005be5d6  8b5004               mov edx, dword ptr [eax + 4]
// 005be5d9  8b02                 mov eax, dword ptr [edx]
// 005be5db  8b400c               mov eax, dword ptr [eax + 0xc]
// 005be5de  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005be5e2  50                   push eax
// 005be5e3  51                   push ecx
// 005be5e4  56                   push esi
// 005be5e5  e8c6480500           call 0x612eb0
// 005be5ea  8b4e08               mov ecx, dword ptr [esi + 8]
// 005be5ed  8901                 mov dword ptr [ecx], eax
// 005be5ef  83c40c               add esp, 0xc
// 005be5f2  c7410807000000       mov dword ptr [ecx + 8], 7
// 005be5f9  83460810             add dword ptr [esi + 8], 0x10
// 005be5fd  83c018               add eax, 0x18
// 005be600  5e                   pop esi
// 005be601  c3                   ret 
// library lua-5.1/lapi.c (function _lua_newuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
