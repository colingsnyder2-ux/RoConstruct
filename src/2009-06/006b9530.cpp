// from server: 100% by auto
// roc 2009-06 006b9530  unit: RBX::UniversalTool  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9530
//
// 006b9530  8b442404             mov eax, dword ptr [esp + 4]
// 006b9534  8b4808               mov ecx, dword ptr [eax + 8]
// 006b9537  33d2                 xor edx, edx
// 006b9539  39542408             cmp dword ptr [esp + 8], edx
// 006b953d  c7410801000000       mov dword ptr [ecx + 8], 1
// 006b9544  0f95c2               setne dl
// 006b9547  8911                 mov dword ptr [ecx], edx
// 006b9549  83400810             add dword ptr [eax + 8], 0x10
// 006b954d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
