// from server: 100% by auto
// roc 2011-06 00762520  unit: seg_00760000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762520
//
// 00762520  8b442408             mov eax, dword ptr [esp + 8]
// 00762524  56                   push esi
// 00762525  8b742408             mov esi, dword ptr [esp + 8]
// 00762529  8bce                 mov ecx, esi
// 0076252b  e880fcffff           call 0x7621b0
// 00762530  8b10                 mov edx, dword ptr [eax]
// 00762532  8b4e08               mov ecx, dword ptr [esi + 8]
// 00762535  8911                 mov dword ptr [ecx], edx
// 00762537  8b5004               mov edx, dword ptr [eax + 4]
// 0076253a  895104               mov dword ptr [ecx + 4], edx
// 0076253d  8b4008               mov eax, dword ptr [eax + 8]
// 00762540  894108               mov dword ptr [ecx + 8], eax
// 00762543  83460810             add dword ptr [esi + 8], 0x10
// 00762547  5e                   pop esi
// 00762548  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
