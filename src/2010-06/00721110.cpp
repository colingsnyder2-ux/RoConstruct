// from server: 100% by auto
// roc 2010-06 00721110  unit: RBX::UniversalTool  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721110
//
// 00721110  8b442408             mov eax, dword ptr [esp + 8]
// 00721114  56                   push esi
// 00721115  8b742408             mov esi, dword ptr [esp + 8]
// 00721119  8bce                 mov ecx, esi
// 0072111b  e880fcffff           call 0x720da0
// 00721120  8b10                 mov edx, dword ptr [eax]
// 00721122  8b4e08               mov ecx, dword ptr [esi + 8]
// 00721125  8911                 mov dword ptr [ecx], edx
// 00721127  8b5004               mov edx, dword ptr [eax + 4]
// 0072112a  895104               mov dword ptr [ecx + 4], edx
// 0072112d  8b4008               mov eax, dword ptr [eax + 8]
// 00721130  894108               mov dword ptr [ecx + 8], eax
// 00721133  83460810             add dword ptr [esi + 8], 0x10
// 00721137  5e                   pop esi
// 00721138  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
