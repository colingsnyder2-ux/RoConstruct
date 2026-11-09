// roc 2012-06 007d5140  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007d5140
//
// 007d5140  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 007d5143  8b01                 mov eax, dword ptr [ecx]
// 007d5145  8b5004               mov edx, dword ptr [eax + 4]
// 007d5148  ffe2                 jmp edx
// library ogre-1.4.9/OgreSubEntity.cpp (function ?getCastsShadows@SubEntity@Ogre@@UBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSubEntity.cpp
