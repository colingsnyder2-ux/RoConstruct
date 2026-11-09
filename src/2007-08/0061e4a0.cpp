// from server: 100% by colin
// roc 2007-08 0061e4a0  unit: RBX::ScoreHud  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061e4a0
//
// 0061e4a0  6aff                 push -1
// 0061e4a2  68397a7500           push 0x757a39
// 0061e4a7  64a100000000         mov eax, dword ptr fs:[0]
// 0061e4ad  50                   push eax
// 0061e4ae  64892500000000       mov dword ptr fs:[0], esp
// 0061e4b5  51                   push ecx
// 0061e4b6  8b442414             mov eax, dword ptr [esp + 0x14]
// 0061e4ba  56                   push esi
// 0061e4bb  8bf1                 mov esi, ecx
// 0061e4bd  50                   push eax
// 0061e4be  89742408             mov dword ptr [esp + 8], esi
// 0061e4c2  ff159ce67700         call dword ptr [0x77e69c]
// 0061e4c8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0061e4cc  51                   push ecx
// 0061e4cd  8d4e1c               lea ecx, [esi + 0x1c]
// 0061e4d0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0061e4d8  e8b3fbffff           call 0x61e090
// 0061e4dd  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0061e4e1  8bc6                 mov eax, esi
// 0061e4e3  5e                   pop esi
// 0061e4e4  64890d00000000       mov dword ptr fs:[0], ecx
// 0061e4eb  83c410               add esp, 0x10
// 0061e4ee  c20800               ret 8
// copied from an identical function in another client (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@ABV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@1@@Z)

// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreSceneManager.cpp