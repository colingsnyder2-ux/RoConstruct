// from server: 100% by EspClaude
// roc 2009-06 006e2ab0  unit: RBX::ScoreHud  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e2ab0
//
// 006e2ab0  6aff                 push -1
// 006e2ab2  68991c8700           push 0x871c99
// 006e2ab7  64a100000000         mov eax, dword ptr fs:[0]
// 006e2abd  50                   push eax
// 006e2abe  64892500000000       mov dword ptr fs:[0], esp
// 006e2ac5  51                   push ecx
// 006e2ac6  56                   push esi
// 006e2ac7  57                   push edi
// 006e2ac8  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006e2acc  8bf1                 mov esi, ecx
// 006e2ace  57                   push edi
// 006e2acf  8974240c             mov dword ptr [esp + 0xc], esi
// 006e2ad3  ff15b8e48900         call dword ptr [0x89e4b8]
// 006e2ad9  83c71c               add edi, 0x1c
// 006e2adc  57                   push edi
// 006e2add  8d4e1c               lea ecx, [esi + 0x1c]
// 006e2ae0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 006e2ae8  e8d3fdffff           call 0x6e28c0
// 006e2aed  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006e2af1  5f                   pop edi
// 006e2af2  8bc6                 mov eax, esi
// 006e2af4  5e                   pop esi
// 006e2af5  64890d00000000       mov dword ptr fs:[0], ecx
// 006e2afc  83c410               add esp, 0x10
// 006e2aff  c20400               ret 4
// copied from an identical function in another client (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@QAE@ABU01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardSet.cpp