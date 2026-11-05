// from server: 100% by EspClaude
// roc 2009-06 005da270  unit: RBX::ContentProvider::HashApprovalDictionary::VValue::?$sp_counted_impl_p  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005da270
//
// 005da270  64a100000000         mov eax, dword ptr fs:[0]
// 005da276  8b542404             mov edx, dword ptr [esp + 4]
// 005da27a  6aff                 push -1
// 005da27c  68b2db8500           push 0x85dbb2
// 005da281  50                   push eax
// 005da282  64892500000000       mov dword ptr fs:[0], esp
// 005da289  8b4118               mov eax, dword ptr [ecx + 0x18]
// 005da28c  83ec44               sub esp, 0x44
// 005da28f  56                   push esi
// 005da290  be66666606           mov esi, 0x6666666
// 005da295  2bf0                 sub esi, eax
// 005da297  3bf2                 cmp esi, edx
// 005da299  5e                   pop esi
// 005da29a  7358                 jae 0x5da2f4
// 005da29c  68d00b8b00           push 0x8b0bd0
// 005da2a1  8d4c2404             lea ecx, [esp + 4]
// 005da2a5  ff15b4e48900         call dword ptr [0x89e4b4]
// 005da2ab  8d4c241c             lea ecx, [esp + 0x1c]
// 005da2af  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 005da2b7  ff15b8e98900         call dword ptr [0x89e9b8]
// 005da2bd  8d0424               lea eax, [esp]
// 005da2c0  50                   push eax
// 005da2c1  8d4c242c             lea ecx, [esp + 0x2c]
// 005da2c5  c644245001           mov byte ptr [esp + 0x50], 1
// 005da2ca  c744242044c98a00     mov dword ptr [esp + 0x20], 0x8ac944
// 005da2d2  ff15b8e48900         call dword ptr [0x89e4b8]
// 005da2d8  6834929700           push 0x979234
// 005da2dd  8d4c2420             lea ecx, [esp + 0x20]
// 005da2e1  51                   push ecx
// 005da2e2  c644245400           mov byte ptr [esp + 0x54], 0
// 005da2e7  c744242450c98a00     mov dword ptr [esp + 0x24], 0x8ac950
// 005da2ef  e856f71300           call 0x719a4a
// 005da2f4  03c2                 add eax, edx
// 005da2f6  894118               mov dword ptr [ecx + 0x18], eax
// 005da2f9  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 005da2fd  64890d00000000       mov dword ptr fs:[0], ecx
// 005da304  83c450               add esp, 0x50
// 005da307  c20400               ret 4
// copied from an identical function in another client (function ?_Incsize@?$list@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@@std@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardSet.cpp