// from server: 100% by auto
// roc 2010-06 007219b0  unit: RBX::UniversalTool  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007219b0
//
// 007219b0  8b442408             mov eax, dword ptr [esp + 8]
// 007219b4  56                   push esi
// 007219b5  8b742408             mov esi, dword ptr [esp + 8]
// 007219b9  8bce                 mov ecx, esi
// 007219bb  e8e0f3ffff           call 0x720da0
// 007219c0  8b4e08               mov ecx, dword ptr [esi + 8]
// 007219c3  8d51f0               lea edx, [ecx - 0x10]
// 007219c6  52                   push edx
// 007219c7  83c1e0               add ecx, -0x20
// 007219ca  51                   push ecx
// 007219cb  50                   push eax
// 007219cc  56                   push esi
// 007219cd  e8ce9a0500           call 0x77b4a0
// 007219d2  834608e0             add dword ptr [esi + 8], -0x20
// 007219d6  83c410               add esp, 0x10
// 007219d9  5e                   pop esi
// 007219da  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
