// from server: 100% by auto
// roc 2009-12 007e52a0  unit: RBX::Log  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e52a0
//
// 007e52a0  8b01                 mov eax, dword ptr [ecx]
// 007e52a2  50                   push eax
// 007e52a3  e8869f1200           call 0x90f22e
// 007e52a8  c3                   ret 
// library ogre-1.7.0/OgreTextureUnitState.cpp (function ?_getTexturePtr@TextureUnitState@Ogre@@QBEABVTexturePtr@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTextureUnitState.cpp
