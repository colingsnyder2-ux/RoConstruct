// from server: 100% by auto
// roc 2007-08 005bdff0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdff0
//
// 005bdff0  8b442408             mov eax, dword ptr [esp + 8]
// 005bdff4  56                   push esi
// 005bdff5  8b742408             mov esi, dword ptr [esp + 8]
// 005bdff9  8bce                 mov ecx, esi
// 005bdffb  e830f4ffff           call 0x5bd430
// 005be000  8b4e08               mov ecx, dword ptr [esi + 8]
// 005be003  8d51f0               lea edx, [ecx - 0x10]
// 005be006  52                   push edx
// 005be007  83c1e0               add ecx, -0x20
// 005be00a  51                   push ecx
// 005be00b  50                   push eax
// 005be00c  56                   push esi
// 005be00d  e82e240500           call 0x610440
// 005be012  834608e0             add dword ptr [esi + 8], -0x20
// 005be016  83c410               add esp, 0x10
// 005be019  5e                   pop esi
// 005be01a  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
