// from server: 100% by auto
// roc 2011-06 00762230  unit: seg_00760000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762230
//
// 00762230  8b542408             mov edx, dword ptr [esp + 8]
// 00762234  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00762238  8b4108               mov eax, dword ptr [ecx + 8]
// 0076223b  56                   push esi
// 0076223c  8b32                 mov esi, dword ptr [edx]
// 0076223e  8930                 mov dword ptr [eax], esi
// 00762240  8b7204               mov esi, dword ptr [edx + 4]
// 00762243  897004               mov dword ptr [eax + 4], esi
// 00762246  8b5208               mov edx, dword ptr [edx + 8]
// 00762249  895008               mov dword ptr [eax + 8], edx
// 0076224c  83410810             add dword ptr [ecx + 8], 0x10
// 00762250  5e                   pop esi
// 00762251  c3                   ret 
// library lua-5.1/lapi.c (function _luaA_pushobject)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
