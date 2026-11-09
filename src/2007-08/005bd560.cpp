// from server: 100% by auto
// roc 2007-08 005bd560  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd560
//
// 005bd560  8b442404             mov eax, dword ptr [esp + 4]
// 005bd564  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005bd567  8b542408             mov edx, dword ptr [esp + 8]
// 005bd56b  8b4158               mov eax, dword ptr [ecx + 0x58]
// 005bd56e  895158               mov dword ptr [ecx + 0x58], edx
// 005bd571  c3                   ret 
// library lua-5.1/lapi.c (function _lua_atpanic)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
