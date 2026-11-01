// from server: 100% by auto
// roc 2009-12 00788da0  unit: RBX::UniversalTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788da0
//
// 00788da0  56                   push esi
// 00788da1  8b742408             mov esi, dword ptr [esp + 8]
// 00788da5  8b4610               mov eax, dword ptr [esi + 0x10]
// 00788da8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00788dab  57                   push edi
// 00788dac  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00788daf  7209                 jb 0x788dba
// 00788db1  56                   push esi
// 00788db2  e8594e0400           call 0x7cdc10
// 00788db7  83c404               add esp, 4
// 00788dba  8b542414             mov edx, dword ptr [esp + 0x14]
// 00788dbe  8b442410             mov eax, dword ptr [esp + 0x10]
// 00788dc2  8b7e08               mov edi, dword ptr [esi + 8]
// 00788dc5  52                   push edx
// 00788dc6  50                   push eax
// 00788dc7  56                   push esi
// 00788dc8  e8c37d0400           call 0x7d0b90
// 00788dcd  83c40c               add esp, 0xc
// 00788dd0  8907                 mov dword ptr [edi], eax
// 00788dd2  c7470804000000       mov dword ptr [edi + 8], 4
// 00788dd9  83460810             add dword ptr [esi + 8], 0x10
// 00788ddd  5f                   pop edi
// 00788dde  5e                   pop esi
// 00788ddf  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
