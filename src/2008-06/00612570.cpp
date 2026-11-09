// from server: 100% by auto
// roc 2008-06 00612570  unit: seg_00610000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612570
//
// 00612570  56                   push esi
// 00612571  8b742408             mov esi, dword ptr [esp + 8]
// 00612575  8b4610               mov eax, dword ptr [esi + 0x10]
// 00612578  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0061257b  57                   push edi
// 0061257c  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0061257f  7209                 jb 0x61258a
// 00612581  56                   push esi
// 00612582  e8099e0400           call 0x65c390
// 00612587  83c404               add esp, 4
// 0061258a  8b542414             mov edx, dword ptr [esp + 0x14]
// 0061258e  8b442410             mov eax, dword ptr [esp + 0x10]
// 00612592  8b7e08               mov edi, dword ptr [esi + 8]
// 00612595  52                   push edx
// 00612596  50                   push eax
// 00612597  56                   push esi
// 00612598  e873c30400           call 0x65e910
// 0061259d  83c40c               add esp, 0xc
// 006125a0  8907                 mov dword ptr [edi], eax
// 006125a2  c7470805000000       mov dword ptr [edi + 8], 5
// 006125a9  83460810             add dword ptr [esi + 8], 0x10
// 006125ad  5f                   pop edi
// 006125ae  5e                   pop esi
// 006125af  c3                   ret 
// library lua-5.1/lapi.c (function _lua_createtable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
