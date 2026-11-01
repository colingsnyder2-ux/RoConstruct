// from server: 100% by auto
// roc 2007-03 005c0730  unit: seg_005c0000  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c0730
//
// 005c0730  83ec14               sub esp, 0x14
// 005c0733  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005c0737  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005c073b  56                   push esi
// 005c073c  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005c0740  8b5674               mov edx, dword ptr [esi + 0x74]
// 005c0743  57                   push edi
// 005c0744  89442408             mov dword ptr [esp + 8], eax
// 005c0748  8b4608               mov eax, dword ptr [esi + 8]
// 005c074b  2b4620               sub eax, dword ptr [esi + 0x20]
// 005c074e  52                   push edx
// 005c074f  50                   push eax
// 005c0750  894c2420             mov dword ptr [esp + 0x20], ecx
// 005c0754  8d4c2410             lea ecx, [esp + 0x10]
// 005c0758  51                   push ecx
// 005c0759  68b0005c00           push 0x5c00b0
// 005c075e  56                   push esi
// 005c075f  c744242000000000     mov dword ptr [esp + 0x20], 0
// 005c0767  c744242800000000     mov dword ptr [esp + 0x28], 0
// 005c076f  e8bcfeffff           call 0x5c0630
// 005c0774  8b542428             mov edx, dword ptr [esp + 0x28]
// 005c0778  6a00                 push 0
// 005c077a  8bf8                 mov edi, eax
// 005c077c  8b442424             mov eax, dword ptr [esp + 0x24]
// 005c0780  52                   push edx
// 005c0781  50                   push eax
// 005c0782  56                   push esi
// 005c0783  e818cc0300           call 0x5fd3a0
// 005c0788  83c424               add esp, 0x24
// 005c078b  8bc7                 mov eax, edi
// 005c078d  5f                   pop edi
// 005c078e  5e                   pop esi
// 005c078f  83c414               add esp, 0x14
// 005c0792  c3                   ret 
// library lua-5.1.1/ldo.c (function _luaD_protectedparser)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
