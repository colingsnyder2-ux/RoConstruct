// from server: 100% by Yeetserama
// roc 2011-06 0095f640  unit: Ogre::RbxSceneUpdater::?1??debugCheckFrame::NodeVisiter  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0095f640
//
// 0095f640  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0095f644  83ec0c               sub esp, 0xc
// 0095f647  85c9                 test ecx, ecx
// 0095f649  7712                 ja 0x95f65d
// 0095f64b  33c9                 xor ecx, ecx
// 0095f64d  c1e106               shl ecx, 6
// 0095f650  51                   push ecx
// 0095f651  e808aaeaff           call 0x80a05e
// 0095f656  83c404               add esp, 4
// 0095f659  83c40c               add esp, 0xc
// 0095f65c  c3                   ret 
// 0095f65d  83c8ff               or eax, 0xffffffff
// 0095f660  33d2                 xor edx, edx
// 0095f662  f7f1                 div ecx
// 0095f664  83f840               cmp eax, 0x40
// 0095f667  73e4                 jae 0x95f64d
// 0095f669  8d442410             lea eax, [esp + 0x10]
// 0095f66d  50                   push eax
// 0095f66e  8d4c2404             lea ecx, [esp + 4]
// 0095f672  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0095f67a  ff156c0aa400         call dword ptr [0xa40a6c]
// 0095f680  68c472b800           push 0xb872c4
// 0095f685  8d4c2404             lea ecx, [esp + 4]
// 0095f689  51                   push ecx
// 0095f68a  c7442408b4b5a500     mov dword ptr [esp + 8], 0xa5b5b4
// 0095f692  e815baeaff           call 0x80b0ac
// copied from an identical function in another client (function ??$_Allocate@U_Node@?$_Tree_nod@V?$_Tmap_traits@W4TextureEffectType@TextureUnitState@Ogre@@UTextureEffect@23@U?$less@W4TextureEffectType@TextureUnitState@Ogre@@@std@@V?$allocator@U?$pair@$$CBW4TextureEffectType@TextureUnitState@Ogre@@UTextureEffect@23@@std@@@6@$00@std@@@std@@@std@@YAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@W4TextureEffectType@TextureUnitState@Ogre@@UTextureEffect@23@U?$less@W4TextureEffectType@TextureUnitState@Ogre@@@std@@V?$allocator@U?$pair@$$CBW4TextureEffectType@TextureUnitState@Ogre@@UTextureEffect@23@@std@@@6@$00@std@@@0@IPAU120@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardSet.cpp