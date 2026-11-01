// from server: 100% by auto
// roc 2009-12 0048fbe0  unit: RBX::RbxTextureProxy  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048fbe0
//
// 0048fbe0  51                   push ecx
// 0048fbe1  56                   push esi
// 0048fbe2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0048fbe6  83c15c               add ecx, 0x5c
// 0048fbe9  51                   push ecx
// 0048fbea  8bce                 mov ecx, esi
// 0048fbec  c744240800000000     mov dword ptr [esp + 8], 0
// 0048fbf4  ff15d0be9800         call dword ptr [0x98bed0]
// 0048fbfa  8bc6                 mov eax, esi
// 0048fbfc  5e                   pop esi
// 0048fbfd  59                   pop ecx
// 0048fbfe  c20400               ret 4
// library ogre-1.7.0/OgreTechnique.cpp (function ?getShadowCasterMaterial@Technique@Ogre@@QBE?AVMaterialPtr@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTechnique.cpp
