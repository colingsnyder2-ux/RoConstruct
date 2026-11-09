// from server: 100% by auto
// roc 2009-12 00788f70  unit: RBX::UniversalTool  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788f70
//
// 00788f70  8b442404             mov eax, dword ptr [esp + 4]
// 00788f74  8b4808               mov ecx, dword ptr [eax + 8]
// 00788f77  8b542408             mov edx, dword ptr [esp + 8]
// 00788f7b  8911                 mov dword ptr [ecx], edx
// 00788f7d  c7410802000000       mov dword ptr [ecx + 8], 2
// 00788f84  83400810             add dword ptr [eax + 8], 0x10
// 00788f88  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlightuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
