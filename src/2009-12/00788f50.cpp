// from server: 100% by auto
// roc 2009-12 00788f50  unit: RBX::UniversalTool  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788f50
//
// 00788f50  8b442404             mov eax, dword ptr [esp + 4]
// 00788f54  8b4808               mov ecx, dword ptr [eax + 8]
// 00788f57  33d2                 xor edx, edx
// 00788f59  39542408             cmp dword ptr [esp + 8], edx
// 00788f5d  c7410801000000       mov dword ptr [ecx + 8], 1
// 00788f64  0f95c2               setne dl
// 00788f67  8911                 mov dword ptr [ecx], edx
// 00788f69  83400810             add dword ptr [eax + 8], 0x10
// 00788f6d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushboolean)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
