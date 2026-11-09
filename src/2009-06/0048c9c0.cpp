// from server: 100% by EspClaude
// roc 2009-06 0048c9c0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048c9c0
//
// 0048c9c0  53                   push ebx
// 0048c9c1  55                   push ebp
// 0048c9c2  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0048c9c8  56                   push esi
// 0048c9c9  57                   push edi
// 0048c9ca  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0048c9ce  8bf1                 mov esi, ecx
// 0048c9d0  c70700000000         mov dword ptr [edi], 0
// 0048c9d6  85f6                 test esi, esi
// 0048c9d8  740e                 je 0x48c9e8
// 0048c9da  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048c9de  39460c               cmp dword ptr [esi + 0xc], eax
// 0048c9e1  7705                 ja 0x48c9e8
// 0048c9e3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 0048c9e6  7606                 jbe 0x48c9ee
// 0048c9e8  ffd5                 call ebp
// 0048c9ea  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048c9ee  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0048c9f2  8b0e                 mov ecx, dword ptr [esi]
// 0048c9f4  890f                 mov dword ptr [edi], ecx
// 0048c9f6  894704               mov dword ptr [edi + 4], eax
// 0048c9f9  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0048c9fc  7705                 ja 0x48ca03
// 0048c9fe  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0048ca01  7606                 jbe 0x48ca09
// 0048ca03  ffd5                 call ebp
// 0048ca05  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0048ca09  8b07                 mov eax, dword ptr [edi]
// 0048ca0b  8b0e                 mov ecx, dword ptr [esi]
// 0048ca0d  85c0                 test eax, eax
// 0048ca0f  7404                 je 0x48ca15
// 0048ca11  3bc1                 cmp eax, ecx
// 0048ca13  7402                 je 0x48ca17
// 0048ca15  ffd5                 call ebp
// 0048ca17  8b4f04               mov ecx, dword ptr [edi + 4]
// 0048ca1a  3bcb                 cmp ecx, ebx
// 0048ca1c  743a                 je 0x48ca58
// 0048ca1e  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048ca21  c644241400           mov byte ptr [esp + 0x14], 0
// 0048ca26  8b542414             mov edx, dword ptr [esp + 0x14]
// 0048ca2a  52                   push edx
// 0048ca2b  8b542418             mov edx, dword ptr [esp + 0x18]
// 0048ca2f  52                   push edx
// 0048ca30  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0048ca34  52                   push edx
// 0048ca35  51                   push ecx
// 0048ca36  50                   push eax
// 0048ca37  53                   push ebx
// 0048ca38  e803fdffff           call 0x48c740
// 0048ca3d  8b5610               mov edx, dword ptr [esi + 0x10]
// 0048ca40  8bd8                 mov ebx, eax
// 0048ca42  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0048ca46  50                   push eax
// 0048ca47  8d4e08               lea ecx, [esi + 8]
// 0048ca4a  51                   push ecx
// 0048ca4b  52                   push edx
// 0048ca4c  53                   push ebx
// 0048ca4d  e84efdffff           call 0x48c7a0
// 0048ca52  83c428               add esp, 0x28
// 0048ca55  895e10               mov dword ptr [esi + 0x10], ebx
// 0048ca58  8bc7                 mov eax, edi
// 0048ca5a  5f                   pop edi
// 0048ca5b  5e                   pop esi
// 0048ca5c  5d                   pop ebp
// 0048ca5d  5b                   pop ebx
// 0048ca5e  c21400               ret 0x14
// copied from an identical function in another client (function ?erase@?$vector@VParameterDef@Ogre@@V?$allocator@VParameterDef@Ogre@@@std@@@std@@QAE?AV?$_Vector_iterator@VParameterDef@Ogre@@V?$allocator@VParameterDef@Ogre@@@std@@@2@V?$_Vector_const_iterator@VParameterDef@Ogre@@V?$allocator@VParameterDef@Ogre@@@std@@@2@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardSet.cpp