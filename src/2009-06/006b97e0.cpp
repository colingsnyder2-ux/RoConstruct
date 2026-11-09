// from server: 100% by auto
// roc 2009-06 006b97e0  unit: RBX::UniversalTool  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b97e0
//
// 006b97e0  8b442408             mov eax, dword ptr [esp + 8]
// 006b97e4  56                   push esi
// 006b97e5  8b742408             mov esi, dword ptr [esp + 8]
// 006b97e9  8bce                 mov ecx, esi
// 006b97eb  e8e0f3ffff           call 0x6b8bd0
// 006b97f0  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b97f3  8d51f0               lea edx, [ecx - 0x10]
// 006b97f6  52                   push edx
// 006b97f7  83c1e0               add ecx, -0x20
// 006b97fa  51                   push ecx
// 006b97fb  50                   push eax
// 006b97fc  56                   push esi
// 006b97fd  e8fe090300           call 0x6ea200
// 006b9802  834608e0             add dword ptr [esi + 8], -0x20
// 006b9806  83c410               add esp, 0x10
// 006b9809  5e                   pop esi
// 006b980a  c3                   ret 
// library lua-5.1/lapi.c (function _lua_settable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
