// from server: 100% by auto
// roc 2007-08 005bdf20  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdf20
//
// 005bdf20  8b442408             mov eax, dword ptr [esp + 8]
// 005bdf24  56                   push esi
// 005bdf25  8b742408             mov esi, dword ptr [esp + 8]
// 005bdf29  8bce                 mov ecx, esi
// 005bdf2b  e800f5ffff           call 0x5bd430
// 005bdf30  8b4808               mov ecx, dword ptr [eax + 8]
// 005bdf33  8bd1                 mov edx, ecx
// 005bdf35  83ea05               sub edx, 5
// 005bdf38  7418                 je 0x5bdf52
// 005bdf3a  83ea02               sub edx, 2
// 005bdf3d  740c                 je 0x5bdf4b
// 005bdf3f  8b4610               mov eax, dword ptr [esi + 0x10]
// 005bdf42  8b8c8898000000       mov ecx, dword ptr [eax + ecx*4 + 0x98]
// 005bdf49  eb0c                 jmp 0x5bdf57
// 005bdf4b  8b08                 mov ecx, dword ptr [eax]
// 005bdf4d  8b4908               mov ecx, dword ptr [ecx + 8]
// 005bdf50  eb05                 jmp 0x5bdf57
// 005bdf52  8b10                 mov edx, dword ptr [eax]
// 005bdf54  8b4a08               mov ecx, dword ptr [edx + 8]
// 005bdf57  85c9                 test ecx, ecx
// 005bdf59  7504                 jne 0x5bdf5f
// 005bdf5b  33c0                 xor eax, eax
// 005bdf5d  5e                   pop esi
// 005bdf5e  c3                   ret 
// 005bdf5f  8b4608               mov eax, dword ptr [esi + 8]
// 005bdf62  8908                 mov dword ptr [eax], ecx
// 005bdf64  c7400805000000       mov dword ptr [eax + 8], 5
// 005bdf6b  83460810             add dword ptr [esi + 8], 0x10
// 005bdf6f  b801000000           mov eax, 1
// 005bdf74  5e                   pop esi
// 005bdf75  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getmetatable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
