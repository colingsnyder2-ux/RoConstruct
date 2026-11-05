// roc 2012-06 007076d0  unit: MemoryBinder  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007076d0
//
// 007076d0  56                   push esi
// 007076d1  6a20                 push 0x20
// 007076d3  e842aa2700           call 0x98211a
// 007076d8  8bf0                 mov esi, eax
// 007076da  83c404               add esp, 4
// 007076dd  85f6                 test esi, esi
// 007076df  7422                 je 0x707703
// 007076e1  8b442418             mov eax, dword ptr [esp + 0x18]
// 007076e5  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007076e9  8b542410             mov edx, dword ptr [esp + 0x10]
// 007076ed  50                   push eax
// 007076ee  8b442410             mov eax, dword ptr [esp + 0x10]
// 007076f2  51                   push ecx
// 007076f3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007076f7  52                   push edx
// 007076f8  50                   push eax
// 007076f9  51                   push ecx
// 007076fa  8bce                 mov ecx, esi
// 007076fc  e85fffffff           call 0x707660
// 00707701  8bc6                 mov eax, esi
// 00707703  5e                   pop esi
// 00707704  c21400               ret 0x14
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ?_Buynode@?$_Tree@V?$_Tmap_traits@GVHardwareVertexBufferSharedPtr@Ogre@@U?$less@G@std@@V?$allocator@U?$pair@$$CBGVHardwareVertexBufferSharedPtr@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@GVHardwareVertexBufferSharedPtr@Ogre@@U?$less@G@std@@V?$allocator@U?$pair@$$CBGVHardwareVertexBufferSharedPtr@Ogre@@@std@@@4@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBGVHardwareVertexBufferSharedPtr@Ogre@@@2@D@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
