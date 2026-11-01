// from server: 100% by auto
// roc 2011-06 00953610  unit: Ogre::UTVertexSurfaceTex::?$SpecializedMeshGen  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00953610
//
// 00953610  51                   push ecx
// 00953611  8b542410             mov edx, dword ptr [esp + 0x10]
// 00953615  56                   push esi
// 00953616  8b742410             mov esi, dword ptr [esp + 0x10]
// 0095361a  57                   push edi
// 0095361b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0095361f  c644240800           mov byte ptr [esp + 8], 0
// 00953624  8b442408             mov eax, dword ptr [esp + 8]
// 00953628  50                   push eax
// 00953629  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0095362d  52                   push edx
// 0095362e  51                   push ecx
// 0095362f  50                   push eax
// 00953630  56                   push esi
// 00953631  57                   push edi
// 00953632  e8a9feffff           call 0x9534e0
// 00953637  8bc6                 mov eax, esi
// 00953639  6bc02c               imul eax, eax, 0x2c
// 0095363c  83c418               add esp, 0x18
// 0095363f  03c7                 add eax, edi
// 00953641  5f                   pop edi
// 00953642  5e                   pop esi
// 00953643  59                   pop ecx
// 00953644  c20c00               ret 0xc
// library ogre-1.7.0/OgreSkeleton.cpp (function ?_Ufill@?$vector@UDeltaTransform@Ogre@@V?$allocator@UDeltaTransform@Ogre@@@std@@@std@@IAEPAUDeltaTransform@Ogre@@PAU34@IABU34@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreSkeleton.cpp
