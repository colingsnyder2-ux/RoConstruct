// from server: 100% by auto
// roc 2009-12 00788670  unit: RBX::UniversalTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788670
//
// 00788670  8b542408             mov edx, dword ptr [esp + 8]
// 00788674  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00788678  8b4108               mov eax, dword ptr [ecx + 8]
// 0078867b  56                   push esi
// 0078867c  8b32                 mov esi, dword ptr [edx]
// 0078867e  8930                 mov dword ptr [eax], esi
// 00788680  8b7204               mov esi, dword ptr [edx + 4]
// 00788683  897004               mov dword ptr [eax + 4], esi
// 00788686  8b5208               mov edx, dword ptr [edx + 8]
// 00788689  895008               mov dword ptr [eax + 8], edx
// 0078868c  83410810             add dword ptr [ecx + 8], 0x10
// 00788690  5e                   pop esi
// 00788691  c3                   ret 
// library lua-5.1/lapi.c (function _luaA_pushobject)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
