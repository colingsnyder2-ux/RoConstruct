// from server: 100% by auto
// roc 2011-06 0072a960  unit: RBX::VInstance::?$NonFactoryProduct  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0072a960
//
// 0072a960  51                   push ecx
// 0072a961  8b542410             mov edx, dword ptr [esp + 0x10]
// 0072a965  56                   push esi
// 0072a966  8b742410             mov esi, dword ptr [esp + 0x10]
// 0072a96a  57                   push edi
// 0072a96b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0072a96f  c644240800           mov byte ptr [esp + 8], 0
// 0072a974  8b442408             mov eax, dword ptr [esp + 8]
// 0072a978  50                   push eax
// 0072a979  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0072a97d  52                   push edx
// 0072a97e  51                   push ecx
// 0072a97f  50                   push eax
// 0072a980  56                   push esi
// 0072a981  57                   push edi
// 0072a982  e849ba0100           call 0x7463d0
// 0072a987  8d0cf6               lea ecx, [esi + esi*8]
// 0072a98a  83c418               add esp, 0x18
// 0072a98d  8d048f               lea eax, [edi + ecx*4]
// 0072a990  5f                   pop edi
// 0072a991  5e                   pop esi
// 0072a992  59                   pop ecx
// 0072a993  c20c00               ret 0xc
// library ogre-1.7.0/OgreSubMesh.cpp (function ?_Ufill@?$vector@UCluster@Ogre@@V?$allocator@UCluster@Ogre@@@std@@@std@@IAEPAUCluster@Ogre@@PAU34@IABU34@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreSubMesh.cpp
