// from server: 100% by auto
// roc 2011-06 0093ee10  unit: Ogre::RbxMaterialAdapter  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0093ee10
//
// 0093ee10  51                   push ecx
// 0093ee11  8b542410             mov edx, dword ptr [esp + 0x10]
// 0093ee15  56                   push esi
// 0093ee16  8b742410             mov esi, dword ptr [esp + 0x10]
// 0093ee1a  57                   push edi
// 0093ee1b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0093ee1f  c644240800           mov byte ptr [esp + 8], 0
// 0093ee24  8b442408             mov eax, dword ptr [esp + 8]
// 0093ee28  50                   push eax
// 0093ee29  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0093ee2d  52                   push edx
// 0093ee2e  51                   push ecx
// 0093ee2f  50                   push eax
// 0093ee30  56                   push esi
// 0093ee31  57                   push edi
// 0093ee32  e839f9ffff           call 0x93e770
// 0093ee37  8bc6                 mov eax, esi
// 0093ee39  6bc054               imul eax, eax, 0x54
// 0093ee3c  83c418               add esp, 0x18
// 0093ee3f  03c7                 add eax, edi
// 0093ee41  5f                   pop edi
// 0093ee42  5e                   pop esi
// 0093ee43  59                   pop ecx
// 0093ee44  c20c00               ret 0xc
// library ogre-1.7.0/OgreCompositorInstance.cpp (function ?_Ufill@?$vector@VTargetOperation@CompositorInstance@Ogre@@V?$allocator@VTargetOperation@CompositorInstance@Ogre@@@std@@@std@@IAEPAVTargetOperation@CompositorInstance@Ogre@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreCompositorInstance.cpp
