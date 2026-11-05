// from server: 100% by auto
// roc 2011-06 00762960  unit: seg_00760000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762960
//
// 00762960  56                   push esi
// 00762961  8b742408             mov esi, dword ptr [esp + 8]
// 00762965  8b4610               mov eax, dword ptr [esi + 0x10]
// 00762968  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0076296b  57                   push edi
// 0076296c  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0076296f  7209                 jb 0x76297a
// 00762971  56                   push esi
// 00762972  e829480700           call 0x7d71a0
// 00762977  83c404               add esp, 4
// 0076297a  8b542414             mov edx, dword ptr [esp + 0x14]
// 0076297e  8b442410             mov eax, dword ptr [esp + 0x10]
// 00762982  8b7e08               mov edi, dword ptr [esi + 8]
// 00762985  52                   push edx
// 00762986  50                   push eax
// 00762987  56                   push esi
// 00762988  e893780700           call 0x7da220
// 0076298d  83c40c               add esp, 0xc
// 00762990  8907                 mov dword ptr [edi], eax
// 00762992  c7470804000000       mov dword ptr [edi + 8], 4
// 00762999  83460810             add dword ptr [esi + 8], 0x10
// 0076299d  5f                   pop edi
// 0076299e  5e                   pop esi
// 0076299f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
