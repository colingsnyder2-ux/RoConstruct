// from server: 100% by colin
// roc 2007-08 0061e280  unit: RBX::ScoreHud  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061e280
//
// 0061e280  6aff                 push -1
// 0061e282  68397a7500           push 0x757a39
// 0061e287  64a100000000         mov eax, dword ptr fs:[0]
// 0061e28d  50                   push eax
// 0061e28e  64892500000000       mov dword ptr fs:[0], esp
// 0061e295  51                   push ecx
// 0061e296  56                   push esi
// 0061e297  57                   push edi
// 0061e298  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0061e29c  8bf1                 mov esi, ecx
// 0061e29e  57                   push edi
// 0061e29f  8974240c             mov dword ptr [esp + 0xc], esi
// 0061e2a3  ff159ce67700         call dword ptr [0x77e69c]
// 0061e2a9  83c71c               add edi, 0x1c
// 0061e2ac  57                   push edi
// 0061e2ad  8d4e1c               lea ecx, [esi + 0x1c]
// 0061e2b0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0061e2b8  e8d3fdffff           call 0x61e090
// 0061e2bd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0061e2c1  5f                   pop edi
// 0061e2c2  8bc6                 mov eax, esi
// 0061e2c4  5e                   pop esi
// 0061e2c5  64890d00000000       mov dword ptr fs:[0], ecx
// 0061e2cc  83c410               add esp, 0x10
// 0061e2cf  c20400               ret 4
// copied from an identical function in another client (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@PAVParticleEmitter@Ogre@@V?$allocator@PAVParticleEmitter@Ogre@@@std@@@2@@std@@QAE@ABU01@@Z)

// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreSceneManager.cpp