// from server: 100% by auto
// roc 2011-06 00614c90  unit: RBX::MergeBinder  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00614c90
//
// 00614c90  56                   push esi
// 00614c91  6a20                 push 0x20
// 00614c93  e8c6531f00           call 0x80a05e
// 00614c98  8bf0                 mov esi, eax
// 00614c9a  83c404               add esp, 4
// 00614c9d  85f6                 test esi, esi
// 00614c9f  7422                 je 0x614cc3
// 00614ca1  8b442418             mov eax, dword ptr [esp + 0x18]
// 00614ca5  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00614ca9  8b542410             mov edx, dword ptr [esp + 0x10]
// 00614cad  50                   push eax
// 00614cae  8b442410             mov eax, dword ptr [esp + 0x10]
// 00614cb2  51                   push ecx
// 00614cb3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00614cb7  52                   push edx
// 00614cb8  50                   push eax
// 00614cb9  51                   push ecx
// 00614cba  8bce                 mov ecx, esi
// 00614cbc  e88ffeffff           call 0x614b50
// 00614cc1  8bc6                 mov eax, esi
// 00614cc3  5e                   pop esi
// 00614cc4  c21400               ret 0x14
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ?_Buynode@?$_Tree@V?$_Tmap_traits@GVHardwareVertexBufferSharedPtr@Ogre@@U?$less@G@std@@V?$allocator@U?$pair@$$CBGVHardwareVertexBufferSharedPtr@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@GVHardwareVertexBufferSharedPtr@Ogre@@U?$less@G@std@@V?$allocator@U?$pair@$$CBGVHardwareVertexBufferSharedPtr@Ogre@@@std@@@4@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBGVHardwareVertexBufferSharedPtr@Ogre@@@2@D@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
