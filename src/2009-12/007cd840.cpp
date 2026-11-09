// from server: 100% by auto
// roc 2009-12 007cd840  unit: RBX::PartDropTool  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cd840
//
// 007cd840  56                   push esi
// 007cd841  8b742408             mov esi, dword ptr [esp + 8]
// 007cd845  8b4610               mov eax, dword ptr [esi + 0x10]
// 007cd848  83783000             cmp dword ptr [eax + 0x30], 0
// 007cd84c  7410                 je 0x7cd85e
// 007cd84e  8bff                 mov edi, edi
// 007cd850  e82bffffff           call 0x7cd780
// 007cd855  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007cd858  83793000             cmp dword ptr [ecx + 0x30], 0
// 007cd85c  75f2                 jne 0x7cd850
// 007cd85e  5e                   pop esi
// 007cd85f  c3                   ret 
// library lua-5.1/lgc.c (function _luaC_callGCTM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
