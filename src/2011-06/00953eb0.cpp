// from server: 100% by auto
// roc 2011-06 00953eb0  unit: Ogre::UTVertexSurfaceTexTangent::?$SpecializedMeshGen  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00953eb0
//
// 00953eb0  51                   push ecx
// 00953eb1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00953eb5  56                   push esi
// 00953eb6  8b742410             mov esi, dword ptr [esp + 0x10]
// 00953eba  57                   push edi
// 00953ebb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00953ebf  c644240800           mov byte ptr [esp + 8], 0
// 00953ec4  8b442408             mov eax, dword ptr [esp + 8]
// 00953ec8  50                   push eax
// 00953ec9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00953ecd  52                   push edx
// 00953ece  51                   push ecx
// 00953ecf  50                   push eax
// 00953ed0  56                   push esi
// 00953ed1  57                   push edi
// 00953ed2  e879feffff           call 0x953d50
// 00953ed7  83c418               add esp, 0x18
// 00953eda  8d0cf500000000       lea ecx, [esi*8]
// 00953ee1  2bce                 sub ecx, esi
// 00953ee3  8d04cf               lea eax, [edi + ecx*8]
// 00953ee6  5f                   pop edi
// 00953ee7  5e                   pop esi
// 00953ee8  59                   pop ecx
// 00953ee9  c20c00               ret 0xc
// library ogre-1.7.0/OgreMaterialSerializer.cpp (function ?_Ufill@?$vector@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@IAEPAU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@PAU32@IABU32@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMaterialSerializer.cpp
