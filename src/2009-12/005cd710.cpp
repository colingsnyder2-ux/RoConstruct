// from server: 100% by auto
// roc 2009-12 005cd710  unit: RBX::MaterialBaseRefMaterialAdapter  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cd710
//
// 005cd710  56                   push esi
// 005cd711  8bf1                 mov esi, ecx
// 005cd713  e878b8f1ff           call 0x4e8f90
// 005cd718  8b4e08               mov ecx, dword ptr [esi + 8]
// 005cd71b  50                   push eax
// 005cd71c  e84fe4e7ff           call 0x44bb70
// 005cd721  5e                   pop esi
// 005cd722  c3                   ret 
// library ogre-1.7.0/OgreUTFString.cpp (function ?_getCharacter@_base_iterator@UTFString@Ogre@@IBEIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreUTFString.cpp
