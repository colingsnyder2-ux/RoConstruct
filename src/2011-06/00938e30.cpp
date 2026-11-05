// from server: 100% by auto
// roc 2011-06 00938e30  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00938e30
//
// 00938e30  51                   push ecx
// 00938e31  8b542410             mov edx, dword ptr [esp + 0x10]
// 00938e35  56                   push esi
// 00938e36  8b742410             mov esi, dword ptr [esp + 0x10]
// 00938e3a  57                   push edi
// 00938e3b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00938e3f  c644240800           mov byte ptr [esp + 8], 0
// 00938e44  8b442408             mov eax, dword ptr [esp + 8]
// 00938e48  50                   push eax
// 00938e49  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00938e4d  52                   push edx
// 00938e4e  51                   push ecx
// 00938e4f  50                   push eax
// 00938e50  56                   push esi
// 00938e51  57                   push edi
// 00938e52  e8c9fbffff           call 0x938a20
// 00938e57  8d0c76               lea ecx, [esi + esi*2]
// 00938e5a  83c418               add esp, 0x18
// 00938e5d  8d04cf               lea eax, [edi + ecx*8]
// 00938e60  5f                   pop edi
// 00938e61  5e                   pop esi
// 00938e62  59                   pop ecx
// 00938e63  c20c00               ret 0xc
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Ufill@?$vector@VSortedVertex@?$ConvexHull2@N@Wml@@V?$allocator@VSortedVertex@?$ConvexHull2@N@Wml@@@std@@@std@@IAEPAVSortedVertex@?$ConvexHull2@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
