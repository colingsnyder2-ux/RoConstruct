// from server: 100% by auto
// roc 2009-12 00788fc0  unit: RBX::UniversalTool  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788fc0
//
// 00788fc0  8b442408             mov eax, dword ptr [esp + 8]
// 00788fc4  56                   push esi
// 00788fc5  8b742408             mov esi, dword ptr [esp + 8]
// 00788fc9  8bce                 mov ecx, esi
// 00788fcb  e820f6ffff           call 0x7885f0
// 00788fd0  8b4e08               mov ecx, dword ptr [esi + 8]
// 00788fd3  83c1f0               add ecx, -0x10
// 00788fd6  51                   push ecx
// 00788fd7  51                   push ecx
// 00788fd8  50                   push eax
// 00788fd9  56                   push esi
// 00788fda  e881510400           call 0x7ce160
// 00788fdf  83c410               add esp, 0x10
// 00788fe2  5e                   pop esi
// 00788fe3  c3                   ret 
// library lua-5.1/lapi.c (function _lua_gettable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
