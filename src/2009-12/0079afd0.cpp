// from server: 100% by auto
// roc 2009-12 0079afd0  unit: lua_exception  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079afd0
//
// 0079afd0  8b442404             mov eax, dword ptr [esp + 4]
// 0079afd4  8b482c               mov ecx, dword ptr [eax + 0x2c]
// 0079afd7  68ff000000           push 0xff
// 0079afdc  51                   push ecx
// 0079afdd  50                   push eax
// 0079afde  e83dfbffff           call 0x79ab20
// 0079afe3  83c40c               add esp, 0xc
// 0079afe6  f7d8                 neg eax
// 0079afe8  1bc0                 sbb eax, eax
// 0079afea  f7d8                 neg eax
// 0079afec  c3                   ret 
// library lua-5.1/ldebug.c (function _luaG_checkcode)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
