// from server: 100% by auto
// roc 2007-03 005c2d40  unit: seg_005c0000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c2d40
//
// 005c2d40  8b442404             mov eax, dword ptr [esp + 4]
// 005c2d44  8b482c               mov ecx, dword ptr [eax + 0x2c]
// 005c2d47  68ff000000           push 0xff
// 005c2d4c  51                   push ecx
// 005c2d4d  50                   push eax
// 005c2d4e  e87dfbffff           call 0x5c28d0
// 005c2d53  83c40c               add esp, 0xc
// 005c2d56  f7d8                 neg eax
// 005c2d58  1bc0                 sbb eax, eax
// 005c2d5a  f7d8                 neg eax
// 005c2d5c  c3                   ret 
// library lua-5.1.1/ldebug.c (function _luaG_checkcode)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
