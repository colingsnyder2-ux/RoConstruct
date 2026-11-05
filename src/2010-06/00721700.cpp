// from server: 100% by auto
// roc 2010-06 00721700  unit: RBX::UniversalTool  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721700
//
// 00721700  8b442404             mov eax, dword ptr [esp + 4]
// 00721704  8b4808               mov ecx, dword ptr [eax + 8]
// 00721707  33d2                 xor edx, edx
// 00721709  39542408             cmp dword ptr [esp + 8], edx
// 0072170d  c7410801000000       mov dword ptr [ecx + 8], 1
// 00721714  0f95c2               setne dl
// 00721717  8911                 mov dword ptr [ecx], edx
// 00721719  83400810             add dword ptr [eax + 8], 0x10
// 0072171d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
