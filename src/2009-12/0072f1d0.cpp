// from server: 100% by auto
// roc 2009-12 0072f1d0  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072f1d0
//
// 0072f1d0  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0072f1d3  8b01                 mov eax, dword ptr [ecx]
// 0072f1d5  8b5004               mov edx, dword ptr [eax + 4]
// 0072f1d8  ffe2                 jmp edx
// library ogre-1.6.4/OgreSubEntity.cpp (function ?getCastsShadows@SubEntity@Ogre@@UBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreSubEntity.cpp
