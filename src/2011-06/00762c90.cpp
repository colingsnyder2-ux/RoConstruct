// from server: 100% by auto
// roc 2011-06 00762c90  unit: seg_00760000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762c90
//
// 00762c90  56                   push esi
// 00762c91  8b742408             mov esi, dword ptr [esp + 8]
// 00762c95  8b4610               mov eax, dword ptr [esi + 0x10]
// 00762c98  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00762c9b  57                   push edi
// 00762c9c  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00762c9f  7209                 jb 0x762caa
// 00762ca1  56                   push esi
// 00762ca2  e8f9440700           call 0x7d71a0
// 00762ca7  83c404               add esp, 4
// 00762caa  8b542414             mov edx, dword ptr [esp + 0x14]
// 00762cae  8b442410             mov eax, dword ptr [esp + 0x10]
// 00762cb2  8b7e08               mov edi, dword ptr [esi + 8]
// 00762cb5  52                   push edx
// 00762cb6  50                   push eax
// 00762cb7  56                   push esi
// 00762cb8  e8536b0700           call 0x7d9810
// 00762cbd  83c40c               add esp, 0xc
// 00762cc0  8907                 mov dword ptr [edi], eax
// 00762cc2  c7470805000000       mov dword ptr [edi + 8], 5
// 00762cc9  83460810             add dword ptr [esi + 8], 0x10
// 00762ccd  5f                   pop edi
// 00762cce  5e                   pop esi
// 00762ccf  c3                   ret 
// library lua-5.1/lapi.c (function _lua_createtable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
