// from server: 100% by auto
// roc 2010-06 0052d6e0  unit: RBX::MaterialBaseRefMaterialAdapter  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0052d6e0
//
// 0052d6e0  56                   push esi
// 0052d6e1  8bf1                 mov esi, ecx
// 0052d6e3  e838d6ffff           call 0x52ad20
// 0052d6e8  8b4e08               mov ecx, dword ptr [esi + 8]
// 0052d6eb  50                   push eax
// 0052d6ec  e82f96f5ff           call 0x486d20
// 0052d6f1  5e                   pop esi
// 0052d6f2  c3                   ret 
// library ogre-1.7.0/OgreUTFString.cpp (function ?_getCharacter@_base_iterator@UTFString@Ogre@@IBEIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreUTFString.cpp
