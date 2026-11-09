// from server: 100% by auto
// roc 2008-06 00611b10  unit: seg_00610000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611b10
//
// 00611b10  8b542408             mov edx, dword ptr [esp + 8]
// 00611b14  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00611b18  8b4108               mov eax, dword ptr [ecx + 8]
// 00611b1b  56                   push esi
// 00611b1c  8b32                 mov esi, dword ptr [edx]
// 00611b1e  8930                 mov dword ptr [eax], esi
// 00611b20  8b7204               mov esi, dword ptr [edx + 4]
// 00611b23  897004               mov dword ptr [eax + 4], esi
// 00611b26  8b5208               mov edx, dword ptr [edx + 8]
// 00611b29  895008               mov dword ptr [eax + 8], edx
// 00611b2c  83410810             add dword ptr [ecx + 8], 0x10
// 00611b30  5e                   pop esi
// 00611b31  c3                   ret 
// library lua-5.1/lapi.c (function _luaA_pushobject)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
