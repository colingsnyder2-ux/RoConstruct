// from server: 100% by auto
// roc 2008-06 00612610  unit: seg_00610000  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612610
//
// 00612610  8b442408             mov eax, dword ptr [esp + 8]
// 00612614  56                   push esi
// 00612615  8b742408             mov esi, dword ptr [esp + 8]
// 00612619  8bce                 mov ecx, esi
// 0061261b  e870f4ffff           call 0x611a90
// 00612620  8b4808               mov ecx, dword ptr [eax + 8]
// 00612623  83e906               sub ecx, 6
// 00612626  7439                 je 0x612661
// 00612628  83e901               sub ecx, 1
// 0061262b  7434                 je 0x612661
// 0061262d  83e901               sub ecx, 1
// 00612630  7410                 je 0x612642
// 00612632  8b4608               mov eax, dword ptr [esi + 8]
// 00612635  c7400800000000       mov dword ptr [eax + 8], 0
// 0061263c  83460810             add dword ptr [esi + 8], 0x10
// 00612640  5e                   pop esi
// 00612641  c3                   ret 
// 00612642  8b00                 mov eax, dword ptr [eax]
// 00612644  8b5048               mov edx, dword ptr [eax + 0x48]
// 00612647  8b4e08               mov ecx, dword ptr [esi + 8]
// 0061264a  83c048               add eax, 0x48
// 0061264d  8911                 mov dword ptr [ecx], edx
// 0061264f  8b5004               mov edx, dword ptr [eax + 4]
// 00612652  895104               mov dword ptr [ecx + 4], edx
// 00612655  8b4008               mov eax, dword ptr [eax + 8]
// 00612658  894108               mov dword ptr [ecx + 8], eax
// 0061265b  83460810             add dword ptr [esi + 8], 0x10
// 0061265f  5e                   pop esi
// 00612660  c3                   ret 
// 00612661  8b10                 mov edx, dword ptr [eax]
// 00612663  8b4e08               mov ecx, dword ptr [esi + 8]
// 00612666  8b420c               mov eax, dword ptr [edx + 0xc]
// 00612669  c7410805000000       mov dword ptr [ecx + 8], 5
// 00612670  8901                 mov dword ptr [ecx], eax
// 00612672  83460810             add dword ptr [esi + 8], 0x10
// 00612676  5e                   pop esi
// 00612677  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfenv)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
