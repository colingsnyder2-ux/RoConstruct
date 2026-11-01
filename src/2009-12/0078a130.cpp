// from server: 100% by auto
// roc 2009-12 0078a130  unit: RBX::UniversalTool  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a130
//
// 0078a130  8b442408             mov eax, dword ptr [esp + 8]
// 0078a134  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0078a138  8d500c               lea edx, [eax + 0xc]
// 0078a13b  894808               mov dword ptr [eax + 8], ecx
// 0078a13e  8910                 mov dword ptr [eax], edx
// 0078a140  c7400400000000       mov dword ptr [eax + 4], 0
// 0078a147  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_buffinit)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
