// from server: 100% by auto
// roc 2009-06 006b8c50  unit: RBX::UniversalTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8c50
//
// 006b8c50  8b542408             mov edx, dword ptr [esp + 8]
// 006b8c54  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b8c58  8b4108               mov eax, dword ptr [ecx + 8]
// 006b8c5b  56                   push esi
// 006b8c5c  8b32                 mov esi, dword ptr [edx]
// 006b8c5e  8930                 mov dword ptr [eax], esi
// 006b8c60  8b7204               mov esi, dword ptr [edx + 4]
// 006b8c63  897004               mov dword ptr [eax + 4], esi
// 006b8c66  8b5208               mov edx, dword ptr [edx + 8]
// 006b8c69  895008               mov dword ptr [eax + 8], edx
// 006b8c6c  83410810             add dword ptr [ecx + 8], 0x10
// 006b8c70  5e                   pop esi
// 006b8c71  c3                   ret 
// library lua-5.1/lapi.c (function _luaA_pushobject)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
