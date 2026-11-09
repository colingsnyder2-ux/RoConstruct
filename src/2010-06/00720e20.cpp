// from server: 100% by auto
// roc 2010-06 00720e20  unit: RBX::UniversalTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00720e20
//
// 00720e20  8b542408             mov edx, dword ptr [esp + 8]
// 00720e24  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00720e28  8b4108               mov eax, dword ptr [ecx + 8]
// 00720e2b  56                   push esi
// 00720e2c  8b32                 mov esi, dword ptr [edx]
// 00720e2e  8930                 mov dword ptr [eax], esi
// 00720e30  8b7204               mov esi, dword ptr [edx + 4]
// 00720e33  897004               mov dword ptr [eax + 4], esi
// 00720e36  8b5208               mov edx, dword ptr [edx + 8]
// 00720e39  895008               mov dword ptr [eax + 8], edx
// 00720e3c  83410810             add dword ptr [ecx + 8], 0x10
// 00720e40  5e                   pop esi
// 00720e41  c3                   ret 
// library lua-5.1/lapi.c (function _luaA_pushobject)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
