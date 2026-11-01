// from server: 100% by auto
// roc 2007-03 00600f90  unit: seg_00600000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600f90
//
// 00600f90  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00600f94  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00600f98  53                   push ebx
// 00600f99  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00600f9d  56                   push esi
// 00600f9e  8b7334               mov esi, dword ptr [ebx + 0x34]
// 00600fa1  57                   push edi
// 00600fa2  50                   push eax
// 00600fa3  51                   push ecx
// 00600fa4  56                   push esi
// 00600fa5  e876b7ffff           call 0x5fc720
// 00600faa  8b5330               mov edx, dword ptr [ebx + 0x30]
// 00600fad  8bf8                 mov edi, eax
// 00600faf  8b4204               mov eax, dword ptr [edx + 4]
// 00600fb2  57                   push edi
// 00600fb3  50                   push eax
// 00600fb4  56                   push esi
// 00600fb5  e8b6b5ffff           call 0x5fc570
// 00600fba  83c418               add esp, 0x18
// 00600fbd  83780800             cmp dword ptr [eax + 8], 0
// 00600fc1  750d                 jne 0x600fd0
// 00600fc3  c70001000000         mov dword ptr [eax], 1
// 00600fc9  c7400801000000       mov dword ptr [eax + 8], 1
// 00600fd0  8bc7                 mov eax, edi
// 00600fd2  5f                   pop edi
// 00600fd3  5e                   pop esi
// 00600fd4  5b                   pop ebx
// 00600fd5  c3                   ret 
// library lua-5.1.1/llex.c (function _luaX_newstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 llex.c
