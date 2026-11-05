// from server: 100% by EspClaude
// roc 2009-06 006e2b90  unit: RBX::ScoreHud  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e2b90
//
// 006e2b90  6aff                 push -1
// 006e2b92  68991c8700           push 0x871c99
// 006e2b97  64a100000000         mov eax, dword ptr fs:[0]
// 006e2b9d  50                   push eax
// 006e2b9e  64892500000000       mov dword ptr fs:[0], esp
// 006e2ba5  51                   push ecx
// 006e2ba6  8b442414             mov eax, dword ptr [esp + 0x14]
// 006e2baa  56                   push esi
// 006e2bab  8bf1                 mov esi, ecx
// 006e2bad  50                   push eax
// 006e2bae  89742408             mov dword ptr [esp + 8], esi
// 006e2bb2  ff15b8e48900         call dword ptr [0x89e4b8]
// 006e2bb8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006e2bbc  51                   push ecx
// 006e2bbd  8d4e1c               lea ecx, [esi + 0x1c]
// 006e2bc0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 006e2bc8  e8f3fcffff           call 0x6e28c0
// 006e2bcd  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006e2bd1  8bc6                 mov eax, esi
// 006e2bd3  5e                   pop esi
// 006e2bd4  64890d00000000       mov dword ptr fs:[0], ecx
// 006e2bdb  83c410               add esp, 0x10
// 006e2bde  c20800               ret 8
// copied from an identical function in another client (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@ABV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardSet.cpp