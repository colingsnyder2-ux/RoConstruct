// from server: 100% by auto
// roc 2009-12 00789c80  unit: RBX::UniversalTool  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789c80
//
// 00789c80  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00789c84  83ec64               sub esp, 0x64
// 00789c87  56                   push esi
// 00789c88  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00789c8c  8d442404             lea eax, [esp + 4]
// 00789c90  50                   push eax
// 00789c91  51                   push ecx
// 00789c92  56                   push esi
// 00789c93  e8080b0100           call 0x79a7a0
// 00789c98  83c40c               add esp, 0xc
// 00789c9b  85c0                 test eax, eax
// 00789c9d  7434                 je 0x789cd3
// 00789c9f  8d542404             lea edx, [esp + 4]
// 00789ca3  52                   push edx
// 00789ca4  68fc9c9e00           push 0x9e9cfc
// 00789ca9  56                   push esi
// 00789caa  e811180100           call 0x79b4c0
// 00789caf  8b442424             mov eax, dword ptr [esp + 0x24]
// 00789cb3  83c40c               add esp, 0xc
// 00789cb6  85c0                 test eax, eax
// 00789cb8  7e19                 jle 0x789cd3
// 00789cba  50                   push eax
// 00789cbb  8d44242c             lea eax, [esp + 0x2c]
// 00789cbf  50                   push eax
// 00789cc0  68f49c9e00           push 0x9e9cf4
// 00789cc5  56                   push esi
// 00789cc6  e8b5f1ffff           call 0x788e80
// 00789ccb  83c410               add esp, 0x10
// 00789cce  5e                   pop esi
// 00789ccf  83c464               add esp, 0x64
// 00789cd2  c3                   ret 
// 00789cd3  6a00                 push 0
// 00789cd5  6856fd9900           push 0x99fd56
// 00789cda  56                   push esi
// 00789cdb  e8c0f0ffff           call 0x788da0
// 00789ce0  83c40c               add esp, 0xc
// 00789ce3  5e                   pop esi
// 00789ce4  83c464               add esp, 0x64
// 00789ce7  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_where)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
