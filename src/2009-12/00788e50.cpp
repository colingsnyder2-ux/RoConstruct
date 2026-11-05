// from server: 100% by auto
// roc 2009-12 00788e50  unit: RBX::UniversalTool  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788e50
//
// 00788e50  56                   push esi
// 00788e51  8b742408             mov esi, dword ptr [esp + 8]
// 00788e55  8b4610               mov eax, dword ptr [esi + 0x10]
// 00788e58  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00788e5b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00788e5e  7209                 jb 0x788e69
// 00788e60  56                   push esi
// 00788e61  e8aa4d0400           call 0x7cdc10
// 00788e66  83c404               add esp, 4
// 00788e69  8b542410             mov edx, dword ptr [esp + 0x10]
// 00788e6d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00788e71  52                   push edx
// 00788e72  50                   push eax
// 00788e73  56                   push esi
// 00788e74  e817140100           call 0x79a290
// 00788e79  83c40c               add esp, 0xc
// 00788e7c  5e                   pop esi
// 00788e7d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
