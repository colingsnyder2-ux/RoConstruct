// from server: 100% by auto
// roc 2010-06 008e3de0  unit: RBX::RbxTextureProxy  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e3de0
//
// 008e3de0  51                   push ecx
// 008e3de1  56                   push esi
// 008e3de2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008e3de6  83c15c               add ecx, 0x5c
// 008e3de9  51                   push ecx
// 008e3dea  8bce                 mov ecx, esi
// 008e3dec  c744240800000000     mov dword ptr [esp + 8], 0
// 008e3df4  ff15d4b69e00         call dword ptr [0x9eb6d4]
// 008e3dfa  8bc6                 mov eax, esi
// 008e3dfc  5e                   pop esi
// 008e3dfd  59                   pop ecx
// 008e3dfe  c20400               ret 4
// library ogre-1.7.0/OgreTechnique.cpp (function ?getShadowCasterMaterial@Technique@Ogre@@QBE?AVMaterialPtr@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTechnique.cpp
