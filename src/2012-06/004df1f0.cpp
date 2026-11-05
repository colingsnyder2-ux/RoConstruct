// roc 2012-06 004df1f0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004df1f0
//
// 004df1f0  51                   push ecx
// 004df1f1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004df1f5  56                   push esi
// 004df1f6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004df1fa  57                   push edi
// 004df1fb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004df1ff  c644240800           mov byte ptr [esp + 8], 0
// 004df204  8b442408             mov eax, dword ptr [esp + 8]
// 004df208  50                   push eax
// 004df209  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004df20d  52                   push edx
// 004df20e  51                   push ecx
// 004df20f  50                   push eax
// 004df210  56                   push esi
// 004df211  57                   push edi
// 004df212  e8c9fbffff           call 0x4dede0
// 004df217  8d0c76               lea ecx, [esi + esi*2]
// 004df21a  83c418               add esp, 0x18
// 004df21d  8d04cf               lea eax, [edi + ecx*8]
// 004df220  5f                   pop edi
// 004df221  5e                   pop esi
// 004df222  59                   pop ecx
// 004df223  c20c00               ret 0xc
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Ufill@?$vector@VSortedVertex@?$ConvexHull2@N@Wml@@V?$allocator@VSortedVertex@?$ConvexHull2@N@Wml@@@std@@@std@@IAEPAVSortedVertex@?$ConvexHull2@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
