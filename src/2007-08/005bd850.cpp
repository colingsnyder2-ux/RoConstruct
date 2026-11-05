// from server: 100% by auto
// roc 2007-08 005bd850  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd850
//
// 005bd850  8b442408             mov eax, dword ptr [esp + 8]
// 005bd854  56                   push esi
// 005bd855  57                   push edi
// 005bd856  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005bd85a  8bcf                 mov ecx, edi
// 005bd85c  e8cffbffff           call 0x5bd430
// 005bd861  8bf0                 mov esi, eax
// 005bd863  8b442414             mov eax, dword ptr [esp + 0x14]
// 005bd867  8bcf                 mov ecx, edi
// 005bd869  e8c2fbffff           call 0x5bd430
// 005bd86e  81fee82f7c00         cmp esi, 0x7c2fe8
// 005bd874  7414                 je 0x5bd88a
// 005bd876  3de82f7c00           cmp eax, 0x7c2fe8
// 005bd87b  740d                 je 0x5bd88a
// 005bd87d  50                   push eax
// 005bd87e  56                   push esi
// 005bd87f  e8fc110500           call 0x60ea80
// 005bd884  83c408               add esp, 8
// 005bd887  5f                   pop edi
// 005bd888  5e                   pop esi
// 005bd889  c3                   ret 
// 005bd88a  5f                   pop edi
// 005bd88b  33c0                 xor eax, eax
// 005bd88d  5e                   pop esi
// 005bd88e  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawequal)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
