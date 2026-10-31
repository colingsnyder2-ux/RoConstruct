// from server: 100% by EspClaude
// roc 2009-06 0048d380  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048d380
//
// 0048d380  6aff                 push -1
// 0048d382  68991c8700           push 0x871c99
// 0048d387  64a100000000         mov eax, dword ptr fs:[0]
// 0048d38d  50                   push eax
// 0048d38e  64892500000000       mov dword ptr fs:[0], esp
// 0048d395  51                   push ecx
// 0048d396  56                   push esi
// 0048d397  57                   push edi
// 0048d398  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0048d39c  8bf1                 mov esi, ecx
// 0048d39e  57                   push edi
// 0048d39f  8974240c             mov dword ptr [esp + 0xc], esi
// 0048d3a3  ff15b8e48900         call dword ptr [0x89e4b8]
// 0048d3a9  83c71c               add edi, 0x1c
// 0048d3ac  57                   push edi
// 0048d3ad  8d4e1c               lea ecx, [esi + 0x1c]
// 0048d3b0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0048d3b8  e8e3fdffff           call 0x48d1a0
// 0048d3bd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0048d3c1  5f                   pop edi
// 0048d3c2  8bc6                 mov eax, esi
// 0048d3c4  5e                   pop esi
// 0048d3c5  64890d00000000       mov dword ptr fs:[0], ecx
// 0048d3cc  83c410               add esp, 0x10
// 0048d3cf  c20400               ret 4
// copied from an identical function in another client (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@QAE@ABU01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardSet.cpp