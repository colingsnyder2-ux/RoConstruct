// from server: 100% by auto
// roc 2011-06 006f6650  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006f6650
//
// 006f6650  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 006f6653  8b01                 mov eax, dword ptr [ecx]
// 006f6655  8b5004               mov edx, dword ptr [eax + 4]
// 006f6658  ffe2                 jmp edx
// library ogre-1.6.4/OgreSubEntity.cpp (function ?getCastsShadows@SubEntity@Ogre@@UBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreSubEntity.cpp
