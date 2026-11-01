// from server: 100% by auto
// roc 2009-12 00788e80  unit: RBX::UniversalTool  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788e80
//
// 00788e80  56                   push esi
// 00788e81  8b742408             mov esi, dword ptr [esp + 8]
// 00788e85  8b4610               mov eax, dword ptr [esi + 0x10]
// 00788e88  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00788e8b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00788e8e  7209                 jb 0x788e99
// 00788e90  56                   push esi
// 00788e91  e87a4d0400           call 0x7cdc10
// 00788e96  83c404               add esp, 4
// 00788e99  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00788e9d  8d542410             lea edx, [esp + 0x10]
// 00788ea1  52                   push edx
// 00788ea2  50                   push eax
// 00788ea3  56                   push esi
// 00788ea4  e8e7130100           call 0x79a290
// 00788ea9  83c40c               add esp, 0xc
// 00788eac  5e                   pop esi
// 00788ead  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushfstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
