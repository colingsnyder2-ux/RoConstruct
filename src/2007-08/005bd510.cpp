// from server: 100% by auto
// roc 2007-08 005bd510  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd510
//
// 005bd510  56                   push esi
// 005bd511  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005bd515  57                   push edi
// 005bd516  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005bd51a  3bfe                 cmp edi, esi
// 005bd51c  743e                 je 0x5bd55c
// 005bd51e  53                   push ebx
// 005bd51f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005bd523  8bc3                 mov eax, ebx
// 005bd525  f7d8                 neg eax
// 005bd527  c1e004               shl eax, 4
// 005bd52a  014708               add dword ptr [edi + 8], eax
// 005bd52d  85db                 test ebx, ebx
// 005bd52f  7e2a                 jle 0x5bd55b
// 005bd531  33d2                 xor edx, edx
// 005bd533  55                   push ebp
// 005bd534  8b4e08               mov ecx, dword ptr [esi + 8]
// 005bd537  8b4708               mov eax, dword ptr [edi + 8]
// 005bd53a  03c2                 add eax, edx
// 005bd53c  8d6910               lea ebp, [ecx + 0x10]
// 005bd53f  896e08               mov dword ptr [esi + 8], ebp
// 005bd542  8b28                 mov ebp, dword ptr [eax]
// 005bd544  8929                 mov dword ptr [ecx], ebp
// 005bd546  8b6804               mov ebp, dword ptr [eax + 4]
// 005bd549  896904               mov dword ptr [ecx + 4], ebp
// 005bd54c  8b4008               mov eax, dword ptr [eax + 8]
// 005bd54f  83c210               add edx, 0x10
// 005bd552  83eb01               sub ebx, 1
// 005bd555  894108               mov dword ptr [ecx + 8], eax
// 005bd558  75da                 jne 0x5bd534
// 005bd55a  5d                   pop ebp
// 005bd55b  5b                   pop ebx
// 005bd55c  5f                   pop edi
// 005bd55d  5e                   pop esi
// 005bd55e  c3                   ret 
// library lua-5.1/lapi.c (function _lua_xmove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
