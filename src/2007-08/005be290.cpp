// from server: 100% by auto
// roc 2007-08 005be290  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005be290
//
// 005be290  8b442408             mov eax, dword ptr [esp + 8]
// 005be294  56                   push esi
// 005be295  8b742408             mov esi, dword ptr [esp + 8]
// 005be299  8b4e08               mov ecx, dword ptr [esi + 8]
// 005be29c  57                   push edi
// 005be29d  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005be2a1  83c001               add eax, 1
// 005be2a4  c1e004               shl eax, 4
// 005be2a7  57                   push edi
// 005be2a8  2bc8                 sub ecx, eax
// 005be2aa  51                   push ecx
// 005be2ab  56                   push esi
// 005be2ac  e81f800000           call 0x5c62d0
// 005be2b1  83c40c               add esp, 0xc
// 005be2b4  83ffff               cmp edi, -1
// 005be2b7  750e                 jne 0x5be2c7
// 005be2b9  8b4614               mov eax, dword ptr [esi + 0x14]
// 005be2bc  8b7608               mov esi, dword ptr [esi + 8]
// 005be2bf  3b7008               cmp esi, dword ptr [eax + 8]
// 005be2c2  7203                 jb 0x5be2c7
// 005be2c4  897008               mov dword ptr [eax + 8], esi
// 005be2c7  5f                   pop edi
// 005be2c8  5e                   pop esi
// 005be2c9  c3                   ret 
// library lua-5.1/lapi.c (function _lua_call)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
