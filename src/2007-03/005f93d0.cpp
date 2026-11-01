// from server: 100% by auto
// roc 2007-03 005f93d0  unit: seg_005f0000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f93d0
//
// 005f93d0  56                   push esi
// 005f93d1  8b742408             mov esi, dword ptr [esp + 8]
// 005f93d5  8b4610               mov eax, dword ptr [esi + 0x10]
// 005f93d8  83783000             cmp dword ptr [eax + 0x30], 0
// 005f93dc  7410                 je 0x5f93ee
// 005f93de  8bff                 mov edi, edi
// 005f93e0  e82bffffff           call 0x5f9310
// 005f93e5  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005f93e8  83793000             cmp dword ptr [ecx + 0x30], 0
// 005f93ec  75f2                 jne 0x5f93e0
// 005f93ee  5e                   pop esi
// 005f93ef  c3                   ret 
// library lua-5.1.1/lgc.c (function _luaC_callGCTM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
