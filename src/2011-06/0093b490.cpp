// from server: 100% by auto
// roc 2011-06 0093b490  unit: Ogre::RbxTextureCompositorSceneManager  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0093b490
//
// 0093b490  51                   push ecx
// 0093b491  8b542410             mov edx, dword ptr [esp + 0x10]
// 0093b495  56                   push esi
// 0093b496  8b742410             mov esi, dword ptr [esp + 0x10]
// 0093b49a  57                   push edi
// 0093b49b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0093b49f  c644240800           mov byte ptr [esp + 8], 0
// 0093b4a4  8b442408             mov eax, dword ptr [esp + 8]
// 0093b4a8  50                   push eax
// 0093b4a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0093b4ad  52                   push edx
// 0093b4ae  51                   push ecx
// 0093b4af  50                   push eax
// 0093b4b0  56                   push esi
// 0093b4b1  57                   push edi
// 0093b4b2  e849f6ffff           call 0x93ab00
// 0093b4b7  8bc6                 mov eax, esi
// 0093b4b9  83c418               add esp, 0x18
// 0093b4bc  c1e006               shl eax, 6
// 0093b4bf  03c7                 add eax, edi
// 0093b4c1  5f                   pop edi
// 0093b4c2  5e                   pop esi
// 0093b4c3  59                   pop ecx
// 0093b4c4  c20c00               ret 0xc
// library ogre-1.7.0/OgreTangentSpaceCalc.cpp (function ?_Ufill@?$vector@UVertexInfo@TangentSpaceCalc@Ogre@@V?$allocator@UVertexInfo@TangentSpaceCalc@Ogre@@@std@@@std@@IAEPAUVertexInfo@TangentSpaceCalc@Ogre@@PAU345@IABU345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTangentSpaceCalc.cpp
