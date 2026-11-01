// from server: 100% by auto
// roc 2011-06 00960b10  unit: Ogre::RbxSceneUpdater  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00960b10
//
// 00960b10  51                   push ecx
// 00960b11  8b542410             mov edx, dword ptr [esp + 0x10]
// 00960b15  56                   push esi
// 00960b16  8b742410             mov esi, dword ptr [esp + 0x10]
// 00960b1a  57                   push edi
// 00960b1b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00960b1f  c644240800           mov byte ptr [esp + 8], 0
// 00960b24  8b442408             mov eax, dword ptr [esp + 8]
// 00960b28  50                   push eax
// 00960b29  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00960b2d  52                   push edx
// 00960b2e  51                   push ecx
// 00960b2f  50                   push eax
// 00960b30  56                   push esi
// 00960b31  57                   push edi
// 00960b32  e849feffff           call 0x960980
// 00960b37  8bc6                 mov eax, esi
// 00960b39  83c418               add esp, 0x18
// 00960b3c  c1e006               shl eax, 6
// 00960b3f  03c7                 add eax, edi
// 00960b41  5f                   pop edi
// 00960b42  5e                   pop esi
// 00960b43  59                   pop ecx
// 00960b44  c20c00               ret 0xc
// library ogre-1.7.0/OgreTangentSpaceCalc.cpp (function ?_Ufill@?$vector@UVertexInfo@TangentSpaceCalc@Ogre@@V?$allocator@UVertexInfo@TangentSpaceCalc@Ogre@@@std@@@std@@IAEPAUVertexInfo@TangentSpaceCalc@Ogre@@PAU345@IABU345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTangentSpaceCalc.cpp
