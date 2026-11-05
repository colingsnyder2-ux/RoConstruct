// from server: 100% by auto
// roc 2009-12 0078a510  unit: RBX::UniversalTool  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a510
//
// 0078a510  83ec08               sub esp, 8
// 0078a513  8b442410             mov eax, dword ptr [esp + 0x10]
// 0078a517  8b542418             mov edx, dword ptr [esp + 0x18]
// 0078a51b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0078a51f  52                   push edx
// 0078a520  89442404             mov dword ptr [esp + 4], eax
// 0078a524  8d442404             lea eax, [esp + 4]
// 0078a528  50                   push eax
// 0078a529  894c240c             mov dword ptr [esp + 0xc], ecx
// 0078a52d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0078a531  68f0a47800           push 0x78a4f0
// 0078a536  51                   push ecx
// 0078a537  e854f0ffff           call 0x789590
// 0078a53c  83c418               add esp, 0x18
// 0078a53f  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_loadbuffer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
